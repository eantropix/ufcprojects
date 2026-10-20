# AP1 - Ray Tracing do Cenário 3D e Visualização do Raio de Visão

**Aluno:** Arthur Santos Viana de Oliveira (Persona: Lucas Vasconcelos)  
**Matrícula:** 470788  
**Disciplina:** Computação Gráfica - UFC  
**Ambiente:** Linux (C++17, OpenMP, GLFW3, OpenGL)

---

## 1. Visão Geral do Projeto

Este projeto é a implementação completa do cenário tridimensional e da simulação de Ray Tracing especificados na **Avaliação Prática 1 (AP1)**. Utilizando como base a arquitetura orientada a objetos desenvolvida nas tarefas anteriores (`tarefa1`, `tarefa2`, `tarefa3` e `tarefaCursor`), o sistema renderiza:

1. **Anel Cilíndrico:** Centro da base $C_1 = (96, 0, 204)\,\text{m}$, raio $R_1 = 14\,\text{m}$, altura $H_1 = 85\,\text{m}$, direção $\vec{D}_1 = (4, 3, 0)$.
2. **Esfera:** Centro $C_2 = (96, 74, 204)\,\text{m}$, raio $R_2 = 24\,\text{m}$.
3. **Cone de Base Aberta:** Centro da base $C_3 = (204, 0, 96)\,\text{m}$, raio $R_3 = 34\,\text{m}$, altura $H_3 = 210\,\text{m}$, direção $\vec{D}_3 = (4, 0, 3)$.
4. **Pirâmide Reta de Base Quadrada:** Centro da base $C_4 = (154, 0, 154)\,\text{m}$, arestas da base $L_4 = 60\,\text{m}$, altura $H_4 = 180\,\text{m}$.
5. **Plano do Chão ($xz$):** $y = 0$, normal $\vec{n} = (0, 1, 0)$, com textura quadriculada para referência de escala e profundidade espacial.
6. **Fonte de Luz Pontual ($P_f$):** $P_f = (300, 300, 1000)\,\text{m}$, intensidade $I_f = (1.0, 1.0, 1.0)$.
7. **Luz Ambiente Global:** $I_a = (0.5, 0.5, 0.5)$.
8. **Material Comum:** $K_a = K_d = K_e = (0.5, 0.25, 0.5)$, $e = 3$.

Além disso, o visualizador implementa a representação tridimensional do **raio de visão emitido pelo observador em $P_e = (240, 180, 360)\,\text{m}$** que atinge a lateral do cilindro no ponto exato $P_{\text{hit}} = (108.123, 15.154, 217.133)\,\text{m}$, demonstrando a concordância perfeita entre a solução analítica e a renderização gráfica.

---

## 2. Fundamentação e Demonstração Analítica

### 2.1. Determinação dos Parâmetros ($k$ e $\alpha$)
Pela matrícula $470788$ ($A=4, B=7, C=0, D=7, E=8, F=8$):
$$k = (300 + 4 + 7 + 0 + 7 + 8 + 8) \pmod{10} = 334 \pmod{10} = 4$$
$$\alpha = 1 + (k \pmod 4) = 1 + (4 \pmod 4) = 1 \implies P_{at} = C_1 = (96, 0, 204)\,\text{m}$$

### 2.2. Equação do Raio e Interseção
O raio emitido por $P_e = (240, 180, 360)$ na direção de $P_{at} = C_1 = (96, 0, 204)$ é expresso por:
$$P(t) = P_e + t (P_{at} - P_e)$$
Com $\vec{v} = P_{at} - P_e = (-144, -180, -156)\,\text{m}$.

Ao testar a interseção contra o anel cilíndrico de eixo unitário $\hat{u} = (0.8, 0.6, 0.0)$, a equação quadrática simplifica-se com simetria exata:
$$t = 1 \pm \frac{R_1}{\sqrt{a}} = 1 \pm \frac{14}{\sqrt{27653.76}} \implies t_1 \approx 0.915812$$

A altura sobre o eixo no impacto é:
$$h = 18.791\,\text{m} \in [0, 85\,\text{m}]$$
Confirmando que o impacto ocorre na superfície lateral do cilindro antes de atingir o chão ($t = 1.0$).

### 2.3. Ponto de Impacto, Normal e Iluminação
* **Ponto de Impacto:** $P_{\text{hit}} = (108.123093, 15.153866, 217.133351)\,\text{m}$
* **Normal Unitária:** $\hat{N} = (-0.207824, 0.277099, 0.938096)$
* **Vetor da Luz:** $\hat{L} = (0.224447, 0.333197, 0.915753)$, com $\hat{N} \cdot \hat{L} \approx 0.904748 > 0$ (sem oclusão de sombras).
* **Vetor de Reflexão:** $\hat{R} = (-0.600504, 0.168213, 0.781728)$, com $\hat{V} \cdot \hat{R} \approx 0.236243$.

### 2.4. Energia Resultante $E_e$
* **Ambiente:** $I_{\text{amb}} = (0.250000, 0.125000, 0.250000)$
* **Difusa:** $I_{\text{dif}} = (0.452374, 0.226187, 0.452374)$
* **Especular:** $I_{\text{esp}} = (0.006592, 0.003296, 0.006592)$
* **Total:**
  $$E_e = \mathbf{(0.7090, 0.3545, 0.7090)}$$
  *(Matiz $H = 300^\circ$ — tom magenta iluminado).*

O renderizador computa e valida exatamente este valor no pixel central da mira!

---

## 3. Modos de Câmera e Controles Interativos

A aplicação disponibiliza 4 modos de câmera selecionáveis em tempo real via teclado:

| Tecla | Modo de Câmera | Descrição |
| :---: | :--- | :--- |
| <kbd>1</kbd> | **Visão Externa 3D (Panorâmica)** | Mostra o cenário completo com o raio de visão desenhado como um feixe laser amarelo fluorescente conectando o observador $P_e$ (marcador ciano) ao cilindro em $P_{\text{hit}}$ (marcador de impacto laranja), além da pirâmide, cone, esfera e chão. |
| <kbd>2</kbd> | **Visão do Observador $P_e$ (Primeira Pessoa)** | Posiciona a câmera exatamente em $P_e$ olhando para $P_{at} = C_1$, com um retículo de mira amarelo no centro. O pixel central atinge o cilindro com a energia teórica exata calculada ($E_e$). |
| <kbd>3</kbd> | **Close-up no Impacto** | Vista detalhada e aproximada da curvatura do cilindro onde o raio penetra e ilumina a superfície. |
| <kbd>4</kbd> | **Visão Aérea (Top-Down)** | Câmera zenital ortogonal ao chão mostrando a disposição espacial de todos os objetos e a trajetória do raio. |
| <kbd>Mouse</kbd> | **Órbita 3D Interativa** | Clique com o botão esquerdo e arraste para girar a câmera livremente ao redor do centro da cena no modo 1. |
| <kbd>Scroll</kbd> | **Zoom Dinâmico** | Gire a roda do mouse para aproximar ou afastar a câmera. |
| <kbd>P</kbd> / <kbd>S</kbd> | **Salvar Imagem PPM** | Exporta a cena atualmente exibida em formato PPM de alta qualidade. |
| <kbd>ESC</kbd> | **Encerrar** | Fecha a janela interativa. |

---

## 4. Como Compilar e Executar

### Pré-requisitos
* Compilador C++17 com suporte a OpenMP (`g++`)
* Bibliotecas GLFW3 e OpenGL

```bash
# Instalação dos pacotes (caso necessário no Ubuntu/Debian)
sudo apt install libglfw3-dev libgl1-mesa-dev
```

### Compilação
Na pasta `ap1`:
```bash
make clean
make
```

### Execução
```bash
./main
```

Ao iniciar, o programa gera automaticamente duas imagens de alta resolução no diretório:
* `cenario_visao_externa.ppm` (e `.png`): Visão global com o raio visível.
* `cenario_visao_observador.ppm` (e `.png`): Visão em primeira pessoa do observador com retículo.
