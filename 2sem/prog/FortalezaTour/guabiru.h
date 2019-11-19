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
    char desc[100];
};
typedef struct cidade Cidade;

struct mapa  // Mapa possui uma lista de cidades.
{
    Cidade* lista[184];
    int tam;
};
typedef struct mapa Mapa;
struct parada  // Parada será utilizada para construir as rotas.
{
    Cidade *c;
    struct parada *prox_p;
    struct parada *ant_p;
};
typedef struct parada Parada;

struct rota  // Rota tem as paradas inicial, final e a hora de chegada.
{
    Parada *inicio;
    Parada *fim;
    int tam_rota;
    char hora_chegada[5];
};
typedef struct rota Rota;

struct painel
{
    Rota* rotas[30];
    int n_rotas;
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

Cidade* buscaCidade(Mapa* m, char* c);

// Cria uma parada com cidades especificadas
Parada* criaParada(Parada *ant, Cidade *atual, Parada *prox);

// Remove uma parada de uma rota - DESATIVADO
void removeParada(Cidade *c);

// Mostra a descrição da cidade de uma parada.
void mostraParada(Parada* p);

Mapa* criaMapa(char** lista_nomes, char** lista_descricoes, int n_cidades);

//Cria uma rota com n cidades
Rota* criaRota(Mapa* mapa, int tam_rota, char** cidades_rota, char horario[5]);

// Mostra as cidades de uma rota
void mostraRota(Rota *r);

// Cria um vetor de rotas
Painel* criaPainel();

//Atualiza o painel (desnecessário)
void atualizaPainel(Painel* p, Rota** rotas, int n_rotas);


// Recebe as rotas e retorna uma lista com cidades únicas (sem repetições)
char** destinosUnicos(Painel* p, int n_rotas);

// Mostra os destinos retornados por 'destinosUnicos'
void mostraDestinos(char** destinos);

// Mostra todos os destinos disponíveis para viagem
void mostraPainel(Painel* p, int n_rotas);

#endif