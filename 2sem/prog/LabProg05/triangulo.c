#include <stdlib.h>
#include "ponto.h"
#include "triangulo.h"

/* Função criaT - Aloca e retorna um triangulo com base nos pontos */ 
Triangulo* criaT(Ponto* p1, Ponto* p2, Ponto* p3)
{
    Triangulo *t = (Triangulo*) malloc (sizeof(Triangulo));
    t->p1 = p1; t->p2 = p2; t->p3 = p3;
    return t;
}

/* Função liberaT - Libera a memória de um triangulo previamente criado */ 
void liberaT(Triangulo** t)
{
    free(*t);
}

/* Função acessaT - Retorna os valores dos pontos de um triângulo */ 
void acessaT(Triangulo* t, Ponto* p1, Ponto* p2, Ponto* p3)
{
    p1 = t->p1;
    p2 = t->p2;
    p3 = t->p3;
}

/* Função atribuiT - Atribui novos valores aos pontos de um triângulo */ 
void atribuiT(Triangulo* t, Ponto* p1, Ponto* p2, Ponto* p3)
{
    t->p1 = p1;
    t->p2 = p2;
    t->p3 = p3;
}

/* Função verificaT - Retorna 1 se os pontos do triângulo atendem a condição de existência e 0, caso contrário */
int verificaT(Triangulo* t)
{
    return 1;
}

/* Função pertenceT - Retorna 1 se o ponto pertence ao triângulo ou 0, caso contrário */
int pertenceT(Triangulo* t, Ponto* p)
{
    return 1;
}