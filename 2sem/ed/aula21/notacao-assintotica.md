2. Motivação
Compare estas duas otimizações que fizemos antes:

a) Utilizar a sentinela para reduzir de 2 para 1 o número de
comparações do laço da remoção de um conjunto via lista encadeada.

b) Na remoção de conjunto via vetor, substituir "e" por v[ult]

Qual é mais significativa?
---
PROVA: Sejam f(n) = 1000*n e g(n) = 5*n²; Temos que mostrar então que
existem (m £ N*) e (c £ R*+) tais que para todo n >= m, 0 <= f(n) <= c.g(n)
(1) Sejam então m = 200, c = 1 e n >= m.
Temos: 0 <= 1000 <= 1000n, pois n >= 1
200 <= 200 <= n , pois [n >= m = 200]
n <= c.n, pois [c >= 1]
=>  200n <= c.n² , pois [n >= 0]
=>  1000n <= c.n².5