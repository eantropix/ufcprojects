#include "guabiru.h"

Cidade* criaCidade(char *nome, char *desc)
{
    Cidade* c = (Cidade*) malloc (sizeof(Cidade));
    strcpy(c->nome, nome);
    strcpy(c->desc, desc);
    return c;
}

void mostraCidade(Cidade* c)
{
    printf("%s\n", c->nome);
    printf("%s\n\n", c->desc);
}

Parada* criaParada(Cidade *ant, Cidade *atual, Cidade *prox)
{
    Parada *p = (Parada*) malloc (sizeof(Parada));
    p->c = atual;
    p->ant_c = ant;
    p->prox_c = prox;
    return p;
}

void mostraParada(Parada *p)
{
    printf("PARADA\n");
    mostraCidade(p->c);
    printf("\n\n");
    if (p->ant_c != NULL) {printf("PARADA ANTERIOR: %s\n", p->ant_c->nome);}
    if (p->prox_c != NULL) {printf("PROXIMA PARADA: %s\n", p->prox_c->nome);}
}

Rota* criaRota(Parada *inicio, Parada* fim, char horario[5])
{
    
}