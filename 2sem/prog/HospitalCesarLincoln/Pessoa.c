#include <stdio.h>
#include <stdlib.h>
#include "Pessoa.h"

/* Aloca e retorna uma pessoa */ 
Pessoa *cria_pessoa(int idade) {
  Pessoa* p = (Pessoa*) malloc (sizeof(Pessoa));
  p->idade = idade;
  p->seguinte = NULL;
  return p;
}

/* Libera a memória de uma pessoa previamente criada */ 
void libera_pessoa(Pessoa **pessoa) {
  free(*pessoa);
}

/* Retorna o próxima da pessoa ou NULL caso contrário */ 
Pessoa *obtem_proximo(Pessoa *pessoa) {
  if (pessoa->seguinte != NULL) {return pessoa->seguinte;}
  return NULL;
}

/* Adiciona o próxima da pessoa. Retorna 1 se der certo e 0 caso contrário */ 
int atribui_proximo(Pessoa *pessoa, Pessoa *proximo) {
  if (proximo != NULL) {pessoa->seguinte = proximo; return 1;}
  else if (proximo == NULL) {return 1;}
  else {return 0;}
}

/* Retorna a idade da pessoa ou 0 se não for possível */
int obtem_idade(Pessoa *pessoa) {
  if (pessoa->idade != NULL) {return pessoa->idade;}
  else {return 0;}
}