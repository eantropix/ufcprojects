#ifndef GUABIRU_HEADER
#define GUABIRU_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ======================== */
/*  STRUCTS  */
struct cidade  // Cidade será utilizada para construir uma parada.
{
    char nome[30];
    char desc[50];
};
typedef struct cidade Cidade;

struct parada  // Parada será utilizada para construir as rotas.
{
    Cidade *c;
    Cidade *prox_c;
    Cidade *ant_c;
};
typedef struct parada Parada;

struct rota  // Rota tem as paradas inicial, final e a hora de chegada.
{
    Parada *inicio;
    Parada *fim;
    char hora_chegada[5];
};
typedef struct rota Rota;

struct painel
{
    Rota rotas[10];
};
typedef struct painel Painel;

/* ======================== */
/*  MÉTODOS  */
// Cria uma cidade com nome e descrição especificados. 
Cidade* criaCidade(char *nome, char *desc);

// Remove uma cidade recebida.
void removeCidade(Cidade *c);

// Mostra a descrição de uma cidade especificada.
void mostraCidade(Cidade* c);

// Cria uma parada com cidades especificadas
Parada* criaParada(Cidade *ant, Cidade *atual, Cidade *prox);

// Remove uma parada de uma rota - DESATIVADO
void removeParada(Cidade *c);

// Mostra a descrição da cidade de uma parada.
void mostraParada(Parada* p);

//Cria uma rota com n cidades
Rota* criaRota(Parada *inicio, Parada* fim, char horario[5]);

//Cria um vetor de rotas


#endif