// struct cidade
// {
//     char nome[30];
//     char desc[50];
// };
// typedef struct cidade Cidade;
#include <iostream>
#include <stdlib.h>
#include "guabiru.h"

cidade c

Cidade* criaCidade(char *nome, char *desc)
{
    Cidade* f = (Cidade*) malloc (sizeof(Cidade));
}

void mostraDesc(Cidade* c)
{
    printf("%s", c->desc);
}