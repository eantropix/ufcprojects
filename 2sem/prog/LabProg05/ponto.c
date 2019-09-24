#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

/* Função criaP - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto* criaP(float x, float y)
{
    Ponto *p = (Ponto*) malloc (sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

/* Função liberaP - Libera a memória de um ponto previamente criado */ 
void liberaP(Ponto **p)
{
    free(*p);
}

/* Função acessaP - Retorna os valores das coordenadas de um ponto */ 
void acessaP(Ponto* p, float* x, float* y)
{
    *x = p->x;
    *y = p->y;
}

/* Função atribuiP - Atribui novos valores às coordenadas de um ponto */ 
void atribuiP(Ponto* p, float x, float y)
{
    (*p).x = x; (*p).y = y;
}

/* Função distanciaP - Retorna a distância entre dois pontos */ 
float distanciaP(Ponto* p1, Ponto* p2)
{
    return sqrt((p1->x - p2->x) * (p1->x - p2->x)) + ((p1->y - p2->y) * (p1->y - p2->y));
}
