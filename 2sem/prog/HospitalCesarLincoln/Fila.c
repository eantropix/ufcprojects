#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Pessoa.h"

struct fila {
  Pessoa *primeiro;
};


/* Aloca e retorna uma fila */ 
Fila *cria_fila() {
  return NULL;
}

/* Libera a memória de uma fila previamente criada */ 
void libera_fila(Fila **fila) {
  while ((*fila)->primeiro != NULL)
  {
    remove_pessoa(*fila);  // Remove todas as pessoas da fila
  }
  free(*fila);  // Para então liberar memória
}

/* Adiciona uma pessoa à fila. Retorna 1 se der certo e 0 caso contrário */ 
int adiciona_pessoa(Fila *fila, Pessoa *pessoa) {
  Pessoa* atual; Pessoa* proximo;  // Ponteiros para acompanhar a fila
  atual = fila->primeiro;  // Atual é o primeiro
  proximo = atual->seguinte;  // Próximo é o "segundo"
  while (proximo != NULL)  // Enquanto não chegar no fim:
  {
    atual = proximo;
    proximo = proximo->seguinte;  
  }  // Ao sair do loop, chegamos no fim da fila
  atual->seguinte = pessoa; // Pessoa pode ser adicionada no fim da fila
  if (atual->seguinte != NULL) {return 1;}
  return 0;
}

/* Remove uma pessoa da fila. Retorna a pessoa se der certo e NULL caso contrário */
Pessoa *remove_pessoa(Fila *fila) {
  if (fila->primeiro != NULL) {return fila->primeiro;}
  return NULL;
}

/* Retorna a primeira pessoa da fila ou NULL caso contrário */
Pessoa *obtem_primeiro(Fila *fila) {
  return NULL;
}

/* Retorna 1 se a fila estiver vazia e 0 caso contrário */ 
int fila_vazia(Fila *fila) {
  return 0;
}


/* Retorna o número de pessoas na fila */ 
int tamanho_fila(Fila *fila) {
  return -1;
}