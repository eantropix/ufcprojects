#ifndef GUABIRU_HEADER
#define GUABIRU_HEADER
#include <iostream>
#include <string.h>
struct cidade
{
    char nome[30];
    char desc[50];
};
typedef struct cidade Cidade;


//Cria uma cidade com nome e descrição especificados.
Cidade* criaCidade(char *nome, char *desc);

//Mostra a descrição de uma cidade especificada.
void mostraDesc(Cidade* c);

#endif