Um desenvolvedor de cenários para jogos utilizou quatro objetos e
um plano, para desenvolver um cenário 3D: um anel cilíndrico, uma esfera, um cone de base aberta,
uma pirâmide reta de base quadrada.

Seja k = (300 + A + B + C + D + E + F) % 10, onde A = 4, B = 7, C = 0, D = 7, E = 8, F = 8. Ele será usado para calcular diversos valores a seguir:

No cenário idealizado, o plano é utilizado para representar o chão, que coincide com o plano xz. O
vetor normal ao plano aponta do chão para o céu, no sentido positivo do eixo y. Os objetos foram
definidos no cenário com as seguintes configurações:
• Anel cilíndrico com centro da base C1 = (100 − k, 0, 200 + k), raio R1 = 10 + k,
altura H1 = 5 + 20k, e direção D1 = (|k|, |k − 1|,|k − 4|);
• Esfera com centro C2 = (100 − k, |20k − R2/4|, 200 + k), raio R2 = 20 + k;
• Cone de base aberta com centro da base C3 = (200 + k, 0, 100 − k); raio da base
R3 = 30 + k, altura H3 = 10 + 50k, e direção D3 = (|k|, |k − 4|,|k − 1|); e
• Pirâmide reta de base quadrada, com centro da base C4= (150 + k, 0, 150 + k), arestas da
base com dimensões L4 = 20 + 10k e paralelas aos eixos x e z (aos pares) e altura.
H4 = 20 + 40k.
Obs.: Considere todas as unidades em metros.
Considerando que haja uma fonte de luz pontual com os seguintes atributos:

• Posição da fonte de luz, Pf = (300, 300,1000) e
• Intensidade da fonte, If = (1, 1, 1);

Determine a energia Ee = (re, ge, be), com 0 ≤ re, ge, be ≤ 1.0, que chega ao olho de um observador
posicionado no ponto
Pe = (Pex, Pey, Pez) = (0 + 60k, 100 + 20k, 600 − 60k) que olha para o ponto Pat = (Patx, Paty, Patz)
cujas coordenadas dependem do valor de alpha = 1 + k%4, isto é,
Pat, = Calpha.
Considere que todos os objetos têm o mesmo material, cujas propriedades são (krd, kgd, kbd) = (kre, kge, kbe) = (kra, kga, kba) = (0.5, 0.25, 0.5) e coeficiente de polimento e = 3. Considere também uma luz ambiente com intensidade Ia = (0.5, 0.5, 0.5).
Explique cada passo da solução, indicando as expressões matemáticas utilizadas, bem como os
valores numéricos dos termos e os respectivos resultados.
