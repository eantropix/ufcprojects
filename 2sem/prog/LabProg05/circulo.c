#include <math.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
/* Função criaC - Aloca e retorna um circulo com base no ponto e no raio informados */ 
Circulo* criaC(Ponto* p, float raio)
{
    Circulo *c = (Circulo*) malloc (sizeof(Circulo)); return c;
}


/* Função liberaC - Libera a memória de um circulo previamente criado */ 
void liberaC(Circulo** c)
{
    free(*c);
}

/* Função acessaC - Retorna os valores das coordenadas de um circulo e seu raio */ 
void acessaC(Circulo* c, float* x, float* y, float* r)
{
    *x = c->p->x; *y = c->p->y; *r = c->r;
}

/* Função atribuiC - Atribui novos valores às coordenadas de um ponto e seu raio */
void atribuiC(Circulo* c, float x, float y, float r)
{
    c->p->x = x; c->p->y = y; c->r = r;
}

/*Função pertenceC - Retorna 1 se o ponto pertence ao circulo ou 0, caso contrário */ 
int pertenceC(Circulo* c, Ponto* p)
{
    Ponto *centro = c->p;
    float dist = distanciaP(centro, p);
    if (dist <= c->r) {return 1;}
    return 0;
}

/* Função areaC - Retorna o cálculo da área do circulo */ 
float areaC(Circulo* c)
{
    float r = c -> r; return M_PI*pow(r, 2);
}
#endif