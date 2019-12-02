#ifndef USUARIO
#define USUARIO
#include <stdio.h>
#include <stdlib.h>

struct cidade
{
    char* nome;
    char* pais;
};
typedef struct cidade Cidade;

struct viagem
{
    char data[8]; // DD/MM/AA
    Cidade* c;
};
typedef struct viagem Viagem;

struct noh_viagem
{
    Viagem* v;
    Noh_viagem *anterior;
    Noh_viagem *proximo;
}
typedef struct noh_viagem Noh_viagem;

struct lista_viagens
{
    Usuario* u;

}
struct usuario 
{
    unsigned int id;
    char nome[40];
};
typedef struct usuario Usuario;
#endif