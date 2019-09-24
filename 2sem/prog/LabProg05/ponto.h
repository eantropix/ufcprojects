/* TAD: Ponto (x,y) */
/* Tipo exportado */ 
#ifndef PONTO_H
#define PONTO_H
struct ponto{
	float x; float y;
};

typedef struct ponto Ponto;

/* Funções exportadas */

/* Função criaP - Aloca e retorna um ponto com coordenadas (x,y) */ 
Ponto* criaP(float x, float y);

/* Função liberaP - Libera a memória de um ponto previamente criado */ 
void liberaP(Ponto** p);

/* Função acessaP - Retorna os valores das coordenadas de um ponto */ 
void acessaP(Ponto* p, float* x, float* y);

/* Função atribuiP - Atribui novos valores às coordenadas de um ponto */ 
void atribuiP(Ponto* p, float x, float y);

/* Função distanciaP - Retorna a distância entre dois pontos */ 
float distanciaP(Ponto* p1, Ponto* p2);
#endif