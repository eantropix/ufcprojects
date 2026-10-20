#include "Scene.h"
#include <cmath>
#include <algorithm>

Scene::Scene()
    : light(Vector3(300.0f, 300.0f, 1000.0f), Color(1.0f, 1.0f, 1.0f)),
      ambientIntensity(0.5f, 0.5f, 0.5f),
      backgroundColor(0.06f, 0.08f, 0.12f),
      showRayBeam(true)
{
}

void Scene::addBaseObject(std::shared_ptr<Object> obj) {
    baseObjects.push_back(obj);
}

void Scene::addRayBeamObject(std::shared_ptr<Object> obj) {
    rayBeamObjects.push_back(obj);
}

bool Scene::intersect(const Ray& ray, float tMin, float tMax, HitRecord& hit) const {
    float closest_t = tMax;
    bool found = false;
    HitRecord tempHit;

    for (const auto& obj : baseObjects) {
        if (obj->intersect(ray, tMin, closest_t, tempHit)) {
            closest_t = tempHit.t;
            hit = tempHit;
            found = true;
        }
    }

    if (showRayBeam) {
        for (const auto& obj : rayBeamObjects) {
            if (obj->intersect(ray, tMin, closest_t, tempHit)) {
                closest_t = tempHit.t;
                hit = tempHit;
                found = true;
            }
        }
    }

    return found;
}

Color Scene::traceRay(const Ray& ray, int /*depth*/) const {
    HitRecord hit;
    if (!intersect(ray, 1e-3f, 1e7f, hit)) {
        return backgroundColor;
    }

    const Material* mat = hit.material;
    if (!mat) return Color(1.0f, 0.0f, 1.0f);

    // Se tiver emissão própria (laser beam / marcadores de luz), retorna a luz emitida
    if (mat->emissive.r > 0.0f || mat->emissive.g > 0.0f || mat->emissive.b > 0.0f) {
        return mat->emissive;
    }

    // 1. Componente Ambiente
    Color I_amb = ambientIntensity * mat->ka;

    // 2. Componente Direta (Difusa + Especular)
    Color I_diff(0.0f, 0.0f, 0.0f);
    Color I_spec(0.0f, 0.0f, 0.0f);

    Vector3 L_vec = light.position() - hit.point;
    float distL = L_vec.length();
    Vector3 L = L_vec.normalized();

    float N_dot_L = hit.normal.dot(L);
    if (N_dot_L > 0.0f) {
        Ray shadowRay(hit.point + hit.normal * 1e-3f, L);
        HitRecord shadowHit;
        bool inShadow = false;

        for (const auto& obj : baseObjects) {
            if (obj->intersect(shadowRay, 1e-3f, distL - 1e-3f, shadowHit)) {
                inShadow = true;
                break;
            }
        }

        if (!inShadow) {
            I_diff = (light.intensity() * mat->kd) * N_dot_L;

            Vector3 V = (ray.origin - hit.point).normalized();
            Vector3 R = (hit.normal * (2.0f * N_dot_L) - L).normalized();
            float V_dot_R = V.dot(R);
            if (V_dot_R > 0.0f) {
                float specFactor = std::pow(V_dot_R, mat->shininess);
                I_spec = (light.intensity() * mat->ks) * specFactor;
            }
        }
    }

    return (I_amb + I_diff + I_spec).clamped();
}

void Scene::render(const Camera& cam, Framebuffer& fb, bool drawReticle) const {
    int w = fb.width();
    int h = fb.height();

    #pragma omp parallel for schedule(dynamic, 8)
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            float s = (static_cast<float>(x) + 0.5f) / static_cast<float>(w);
            float t = (static_cast<float>(y) + 0.5f) / static_cast<float>(h);
            Ray ray = cam.getRay(s, t);
            Color c = traceRay(ray);
            fb.setPixel(x, y, c);
        }
    }

    if (drawReticle) {
        int cx = w / 2;
        int cy = h / 2;
        int crosshairSize = 14;
        Color crosshairColor(1.0f, 1.0f, 0.0f); // Amarelo luminoso
        for (int dx = -crosshairSize; dx <= crosshairSize; ++dx) {
            if (std::abs(dx) > 3) {
                fb.setPixel(cx + dx, cy, crosshairColor);
            }
        }
        for (int dy = -crosshairSize; dy <= crosshairSize; ++dy) {
            if (std::abs(dy) > 3) {
                fb.setPixel(cx, cy + dy, crosshairColor);
            }
        }
    }
}
