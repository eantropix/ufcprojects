/* TAD: Circulo (ponto,raio) */ 
/* Tipo exportado */
#include "ponto.h"
struct circulo
{
    Ponto *p; float r;
};
typedef struct circulo Circulo;


/* Funções exportadas */
/* Função criaC - Aloca e retorna um circulo com base no ponto e no raio informados */ 
Circulo* criaC(Ponto* p, float raio);

/* Função liberaC - Libera a memória de um circulo previamente criado */ 
void liberaC(Circulo** c);

/* Função acessaC - Retorna os valores das coordenadas de um circulo e seu raio */ 
void acessaC(Circulo* c, float* x, float* y, float* r);

/* Função atribuiC - Atribui novos valores às coordenadas de um ponto e seu raio */
void atribuiC(Circulo* c, float x, float y, float r);

/*Função pertenceC - Retorna 1 se o ponto pertence ao circulo ou 0, caso contrário */ 
int pertenceC(Circulo* c, Ponto* p);

/* Função areaC - Retorna o cálculo da área do circulo */ 
float areaC(Circulo* c);
