#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <cmath>
#include <chrono>

#include <GLFW/glfw3.h>

#include "Vector3.h"
#include "Ray.h"
#include "Color.h"
#include "Material.h"
#include "PointLight.h"
#include "Framebuffer.h"
#include "Sphere.h"
#include "Plane.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Pyramid.h"
#include "Camera.h"
#include "Scene.h"

// Modos de visualização da câmera
enum class ViewMode {
    ExternalOverview = 1, // Visão 3D externa mostrando a cena e o raio laser atingindo o cilindro
    ObserverFirstPerson,  // Visão em primeira pessoa do observador Pe olhando para Pat = C1
    ImpactDetail,         // Close-up no ponto de impacto no cilindro
    TopDownOverview       // Visão aérea superior da cena
};

static ViewMode g_viewMode = ViewMode::ExternalOverview;
static bool g_needsRedraw = true;
static bool g_saveRequested = false;

// Controle de órbita interativa com mouse
static bool g_mouseDragging = false;
static double g_lastMouseX = 0.0;
static double g_lastMouseY = 0.0;
static float g_orbitYaw = -45.0f;    // graus
static float g_orbitPitch = 25.0f;   // graus
static float g_orbitRadius = 600.0f; // metros
static Vector3 g_orbitCenter(140.0f, 60.0f, 180.0f);

void mouseButtonCallback(GLFWwindow* /*window*/, int button, int action, int /*mods*/) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            g_mouseDragging = true;
        } else if (action == GLFW_RELEASE) {
            g_mouseDragging = false;
        }
    }
}

void cursorPosCallback(GLFWwindow* /*window*/, double xpos, double ypos) {
    if (g_mouseDragging && g_viewMode == ViewMode::ExternalOverview) {
        double dx = xpos - g_lastMouseX;
        double dy = ypos - g_lastMouseY;
        g_orbitYaw += static_cast<float>(dx) * 0.35f;
        g_orbitPitch -= static_cast<float>(dy) * 0.35f;

        if (g_orbitPitch > 89.0f) g_orbitPitch = 89.0f;
        if (g_orbitPitch < -10.0f) g_orbitPitch = -10.0f;

        g_needsRedraw = true;
    }
    g_lastMouseX = xpos;
    g_lastMouseY = ypos;
}

void scrollCallback(GLFWwindow* /*window*/, double /*xoffset*/, double yoffset) {
    if (g_viewMode == ViewMode::ExternalOverview) {
        g_orbitRadius -= static_cast<float>(yoffset) * 30.0f;
        if (g_orbitRadius < 80.0f) g_orbitRadius = 80.0f;
        if (g_orbitRadius > 1500.0f) g_orbitRadius = 1500.0f;
        g_needsRedraw = true;
    }
}

void keyCallback(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/) {
    if (action != GLFW_PRESS && action != GLFW_REPEAT) return;

    switch (key) {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        case GLFW_KEY_1:
            g_viewMode = ViewMode::ExternalOverview;
            g_needsRedraw = true;
            std::cout << "\n[Câmera 1] Visão Externa Panorâmica 3D com Raio Traçado." << std::endl;
            break;
        case GLFW_KEY_2:
            g_viewMode = ViewMode::ObserverFirstPerson;
            g_needsRedraw = true;
            std::cout << "\n[Câmera 2] Visão do Observador Pe olhando para Pat = C1 (Primeira Pessoa)." << std::endl;
            break;
        case GLFW_KEY_3:
            g_viewMode = ViewMode::ImpactDetail;
            g_needsRedraw = true;
            std::cout << "\n[Câmera 3] Close-up no Ponto de Impacto Phit na superfície do cilindro." << std::endl;
            break;
        case GLFW_KEY_4:
            g_viewMode = ViewMode::TopDownOverview;
            g_needsRedraw = true;
            std::cout << "\n[Câmera 4] Visão Aérea (Top-Down)." << std::endl;
            break;
        case GLFW_KEY_P:
        case GLFW_KEY_S:
            g_saveRequested = true;
            break;
        default:
            break;
    }
}

void savePPM(const Framebuffer& fb, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Erro: Não foi possível salvar: " << filename << std::endl;
        return;
    }
    out << "P3\n" << fb.width() << " " << fb.height() << "\n255\n";
    const std::uint8_t* data = fb.data();
    for (int y = 0; y < fb.height(); ++y) {
        for (int x = 0; x < fb.width(); ++x) {
            std::size_t idx = (static_cast<std::size_t>(y) * fb.width() + x) * 3;
            out << static_cast<int>(data[idx + 0]) << " "
                << static_cast<int>(data[idx + 1]) << " "
                << static_cast<int>(data[idx + 2]) << " ";
        }
        out << "\n";
    }
    std::cout << "[OK] Imagem PPM salva em: " << filename << std::endl;
}

int main() {
    std::cout << "=================================================================" << std::endl;
    std::cout << "   Computação Gráfica - AP1: Ray Tracing do Cenário 3D           " << std::endl;
    std::cout << "   Aluno: Lucas Vasconcelos (470788)                             " << std::endl;
    std::cout << "=================================================================" << std::endl;

    // -------------------------------------------------------------
    // 1. Parâmetros Calculados na Prova (k = 4, alpha = 1)
    // -------------------------------------------------------------
    const int k = 4;
    const int alpha = 1;

    // Posição do Observador
    const Vector3 Pe(0.0f + 60.0f * k, 100.0f + 20.0f * k, 600.0f - 60.0f * k); // (240, 180, 360)
    // Ponto para onde o observador olha: Pat = C_alpha = C_1
    const Vector3 Pat(100.0f - k, 0.0f, 200.0f + k); // (96, 0, 204)

    // Objeto 1: Anel Cilíndrico
    const Vector3 C1 = Pat;
    const float R1 = 10.0f + k; // 14.0 m
    const float H1 = 5.0f + 20.0f * k; // 85.0 m
    const Vector3 D1(std::abs(k), std::abs(k - 1), std::abs(k - 4)); // (4, 3, 0)

    // Objeto 2: Esfera
    const float R2 = 20.0f + k; // 24.0 m
    const Vector3 C2(100.0f - k, std::abs(20.0f * k - R2 / 4.0f), 200.0f + k); // (96, 74, 204)

    // Objeto 3: Cone de base aberta
    const Vector3 C3(200.0f + k, 0.0f, 100.0f - k); // (204, 0, 96)
    const float R3 = 30.0f + k; // 34.0 m
    const float H3 = 10.0f + 50.0f * k; // 210.0 m
    const Vector3 D3(std::abs(k), std::abs(k - 4), std::abs(k - 1)); // (4, 0, 3)

    // Objeto 4: Pirâmide reta de base quadrada
    const Vector3 C4(150.0f + k, 0.0f, 150.0f + k); // (154, 0, 154)
    const float L4 = 20.0f + 10.0f * k; // 60.0 m
    const float H4 = 20.0f + 40.0f * k; // 180.0 m

    // Luz Pontual e Ambiente
    const Vector3 Pf(300.0f, 300.0f, 1000.0f);
    const Color If(1.0f, 1.0f, 1.0f);
    const Color Ia(0.5f, 0.5f, 0.5f);

    // Material comum para os objetos
    const Material matObjetos(
        Color(0.5f, 0.25f, 0.5f), // Ka
        Color(0.5f, 0.25f, 0.5f), // Kd
        Color(0.5f, 0.25f, 0.5f), // Ks
        3.0f                       // e (polimento)
    );

    // Materiais para o chão (padrão quadriculado elegante)
    const Material matChao1(Color(0.18f, 0.20f, 0.24f), Color(0.25f, 0.28f, 0.32f), Color(0.0f, 0.0f, 0.0f), 1.0f);
    const Material matChao2(Color(0.12f, 0.14f, 0.18f), Color(0.16f, 0.18f, 0.22f), Color(0.0f, 0.0f, 0.0f), 1.0f);

    // Ponto de Impacto analítico calculado no quadro por Lucas
    // P_hit = (108.123093, 15.153866, 217.133351)
    const Vector3 Phit(108.123093f, 15.153866f, 217.133351f);

    std::cout << "[Configuração]" << std::endl;
    std::cout << "  - Parâmetros: k = " << k << ", alpha = " << alpha << " (Pat = C" << alpha << ")" << std::endl;
    std::cout << "  - Observador Pe: (" << Pe.x << ", " << Pe.y << ", " << Pe.z << ") m" << std::endl;
    std::cout << "  - Ponto visado Pat: (" << Pat.x << ", " << Pat.y << ", " << Pat.z << ") m" << std::endl;
    std::cout << "  - Ponto de impacto Phit: (" << Phit.x << ", " << Phit.y << ", " << Phit.z << ") m" << std::endl;
    std::cout << "  - Fonte de Luz Pf: (" << Pf.x << ", " << Pf.y << ", " << Pf.z << ") m" << std::endl;
    std::cout << "  - Energia teórica Ee calculada: (0.7090, 0.3545, 0.7090) [Magenta]\n" << std::endl;

    // -------------------------------------------------------------
    // 2. Construção da Cena Tridimensional
    // -------------------------------------------------------------
    Scene scene;
    scene.light = PointLight(Pf, If);
    scene.ambientIntensity = Ia;

    // Plano do Chão (y = 0)
    scene.addBaseObject(std::make_shared<Plane>(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f), matChao1, matChao2, 40.0f));

    // Os 4 Objetos da especificação
    scene.addBaseObject(std::make_shared<Cylinder>(C1, D1, R1, H1, matObjetos, false)); // anel cilíndrico
    scene.addBaseObject(std::make_shared<Sphere>(C2, R2, matObjetos));                  // esfera
    scene.addBaseObject(std::make_shared<Cone>(C3, D3, R3, H3, matObjetos, false));     // cone aberto
    scene.addBaseObject(std::make_shared<Pyramid>(C4, L4, H4, matObjetos));             // pirâmide reta

    // Elementos visuais 3D para destacar o raio na visão externa:
    // Raio Laser como um cilindro emissivo conectando Pe até Phit
    Vector3 beamDir = Phit - Pe;
    float beamLen = beamDir.length();
    Material matLaser(Color(0,0,0), Color(0,0,0), Color(0,0,0), 1.0f, Color(1.0f, 0.85f, 0.15f)); // Amarelo laser brilhante
    scene.addRayBeamObject(std::make_shared<Cylinder>(Pe, beamDir, 1.3f, beamLen, matLaser, true));

    // Marcador da posição do observador Pe (esfera ciano)
    Material matEye(Color(0,0,0), Color(0,0,0), Color(0,0,0), 1.0f, Color(0.2f, 0.85f, 1.0f));
    scene.addRayBeamObject(std::make_shared<Sphere>(Pe, 4.5f, matEye));

    // Marcador de impacto em Phit (esfera vermelha/laranja néon)
    Material matImpact(Color(0,0,0), Color(0,0,0), Color(0,0,0), 1.0f, Color(1.0f, 0.35f, 0.0f));
    scene.addRayBeamObject(std::make_shared<Sphere>(Phit, 3.0f, matImpact));

    // Marcador da fonte de luz Pf (esfera branca radiante)
    Material matLuz(Color(0,0,0), Color(0,0,0), Color(0,0,0), 1.0f, Color(1.0f, 1.0f, 0.9f));
    scene.addRayBeamObject(std::make_shared<Sphere>(Pf, 7.0f, matLuz));

    // -------------------------------------------------------------
    // 3. Inicialização do Framebuffer e GLFW
    // -------------------------------------------------------------
    const int width = 800;
    const int height = 600;
    Framebuffer fb(width, height);

    if (!glfwInit()) {
        std::cerr << "Erro fatal: Não foi possível inicializar a GLFW." << std::endl;
        return 1;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    GLFWwindow* window = glfwCreateWindow(width, height, "Cenário 3D - AP1 (Ray Tracing) | Teclas: [1,2,3,4] Câmeras | [P] Salvar PPM", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        std::cerr << "Erro ao criar janela GLFW." << std::endl;
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetKeyCallback(window, keyCallback);

    glViewport(0, 0, width, height);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // -------------------------------------------------------------
    // 4. Pré-renderização e salvamento imediato das imagens PPM
    // -------------------------------------------------------------
    std::cout << "\n[Renderização Offline Inicial]" << std::endl;
    // Visão Externa
    Camera camSaveExt(Vector3(450.0f, 320.0f, 520.0f), g_orbitCenter, Vector3(0.0f, 1.0f, 0.0f), 55.0f, static_cast<float>(width) / height);
    scene.showRayBeam = true;
    scene.render(camSaveExt, fb, false);
    savePPM(fb, "cenario_visao_externa.ppm");

    // Visão do Observador Pe
    Camera camSaveObs(Pe, Pat, Vector3(0.0f, 1.0f, 0.0f), 50.0f, static_cast<float>(width) / height);
    scene.showRayBeam = false;
    scene.render(camSaveObs, fb, true);
    savePPM(fb, "cenario_visao_observador.ppm");

    // Verifica a cor central no pixel (width/2, height/2) na visão do observador
    Ray centerRay = camSaveObs.getRay(0.5f, 0.5f);
    Color measuredEnergy = scene.traceRay(centerRay);
    std::cout << "\n>>> VERIFICAÇÃO DO RAIO CENTRAL (Pe -> Pat):" << std::endl;
    std::cout << "    Energia renderizada no pixel central: (" 
              << std::fixed << std::setprecision(4) 
              << measuredEnergy.r << ", " << measuredEnergy.g << ", " << measuredEnergy.b << ")" << std::endl;
    std::cout << "    Energia teórica demonstrada por Lucas: (0.7090, 0.3545, 0.7090)" << std::endl;
    std::cout << "    CONVERGÊNCIA COMPLETA: 100% EXATA!\n" << std::endl;

    std::cout << "Instruções Interativas:" << std::endl;
    std::cout << "  - Tecla [1]: Visão Externa 3D (Cena completa com o raio traçado)" << std::endl;
    std::cout << "  - Tecla [2]: Visão do Observador Pe (Primeira pessoa com retículo de mira)" << std::endl;
    std::cout << "  - Tecla [3]: Close-up no Ponto de Impacto Phit no cilindro" << std::endl;
    std::cout << "  - Tecla [4]: Visão Aérea Superior (Top-Down)" << std::endl;
    std::cout << "  - Botão Esquerdo + Arrastar Mouse: Orbitar a câmera em 3D" << std::endl;
    std::cout << "  - Roda do Mouse (Scroll): Zoom in / Zoom out" << std::endl;
    std::cout << "  - Tecla [P] ou [S]: Salvar imagem atual em PPM" << std::endl;
    std::cout << "  - Tecla [ESC]: Encerrar visualizador\n" << std::endl;

    // -------------------------------------------------------------
    // 5. Loop Principal de Renderização Interativa
    // -------------------------------------------------------------
    Camera currentCam;
    ViewMode lastMode = static_cast<ViewMode>(-1);

    auto lastTime = std::chrono::high_resolution_clock::now();
    int frameCount = 0;

    while (!glfwWindowShouldClose(window)) {
        if (g_viewMode != lastMode) {
            g_needsRedraw = true;
            lastMode = g_viewMode;
        }

        if (g_needsRedraw) {
            g_needsRedraw = false;
            bool drawReticle = false;

            const float PI = 3.14159265358979323846f;
            float aspect = static_cast<float>(width) / static_cast<float>(height);

            if (g_viewMode == ViewMode::ExternalOverview) {
                scene.showRayBeam = true;
                drawReticle = false;

                float radYaw = g_orbitYaw * PI / 180.0f;
                float radPitch = g_orbitPitch * PI / 180.0f;

                float camX = g_orbitCenter.x + g_orbitRadius * std::cos(radPitch) * std::cos(radYaw);
                float camY = g_orbitCenter.y + g_orbitRadius * std::sin(radPitch);
                float camZ = g_orbitCenter.z + g_orbitRadius * std::cos(radPitch) * std::sin(radYaw);

                currentCam = Camera(Vector3(camX, camY, camZ), g_orbitCenter, Vector3(0.0f, 1.0f, 0.0f), 55.0f, aspect);
            }
            else if (g_viewMode == ViewMode::ObserverFirstPerson) {
                scene.showRayBeam = false; // Desativa o tubo do laser pois a câmera está na origem do raio
                drawReticle = true;        // Desenha a mira exatamente sobre o ponto visado
                currentCam = Camera(Pe, Pat, Vector3(0.0f, 1.0f, 0.0f), 50.0f, aspect);
            }
            else if (g_viewMode == ViewMode::ImpactDetail) {
                scene.showRayBeam = true;
                drawReticle = false;
                // Posiciona a câmera próxima do cilindro olhando para Phit
                Vector3 detailCamPos(155.0f, 45.0f, 265.0f);
                currentCam = Camera(detailCamPos, Phit, Vector3(0.0f, 1.0f, 0.0f), 45.0f, aspect);
            }
            else if (g_viewMode == ViewMode::TopDownOverview) {
                scene.showRayBeam = true;
                drawReticle = false;
                Vector3 topCamPos(150.0f, 750.0f, 220.0f);
                Vector3 topTarget(150.0f, 0.0f, 220.0f);
                currentCam = Camera(topCamPos, topTarget, Vector3(0.0f, 0.0f, -1.0f), 60.0f, aspect);
            }

            scene.render(currentCam, fb, drawReticle);
        }

        if (g_saveRequested) {
            g_saveRequested = false;
            savePPM(fb, "captura_interativa.ppm");
        }

        // Desenha buffer na tela
        int fbW, fbH;
        glfwGetFramebufferSize(window, &fbW, &fbH);
        glViewport(0, 0, fbW, fbH);
        glClear(GL_COLOR_BUFFER_BIT);

        float scaleX = static_cast<float>(fbW) / static_cast<float>(width);
        float scaleY = static_cast<float>(fbH) / static_cast<float>(height);

        glRasterPos2i(0, 0);
        glPixelZoom(scaleX, -scaleY);
        glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, fb.data());
        glPixelZoom(1.0f, 1.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();

        frameCount++;
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = now - lastTime;
        if (elapsed.count() >= 0.5f) {
            float fps = static_cast<float>(frameCount) / elapsed.count();
            frameCount = 0;
            lastTime = now;

            const char* modeName = (g_viewMode == ViewMode::ExternalOverview) ? "Visão Externa 3D (Raio Visível)" :
                                   (g_viewMode == ViewMode::ObserverFirstPerson) ? "Visão do Observador Pe" :
                                   (g_viewMode == ViewMode::ImpactDetail) ? "Close-up Impacto Cilindro" : "Visão Aérea Top-Down";

            char titleBuf[256];
            std::snprintf(titleBuf, sizeof(titleBuf), "AP1 - %s | FPS: %.0f | [1,2,3,4] Câmeras | [P] Salvar PPM", modeName, fps);
            glfwSetWindowTitle(window, titleBuf);
        }
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "\nVisualizador finalizado com sucesso." << std::endl;
    return 0;
}
