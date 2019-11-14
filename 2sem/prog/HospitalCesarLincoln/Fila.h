#include "Pessoa.h"

/* TAD: Fila (primeiro)*/
struct fila
{
	Pessoa* primeiro;
};
typedef struct fila Fila;

/* Aloca e retorna uma fila */ 
Fila *cria_fila();

/* Libera a memória de uma fila previamente criada */ 
void libera_fila(Fila **fila);

/* Adiciona uma pessoa à fila. Retorna 1 se der certo e 0 caso contrário */ 
int adiciona_pessoa(Fila *fila, Pessoa *pessoa);

/* Remove uma pessoa da fila. Retorna a pessoa se der certo e NULL caso contrário */
Pessoa *remove_pessoa(Fila *fila);

/* Retorna a primeira pessoa da fila ou NULL caso contrário */
Pessoa *obtem_primeiro(Fila *fila);

/* Retorna 1 se a fila estiver vazia e 0 caso contrário */ 
int fila_vazia(Fila *fila);

/* Retorna o número de pessoas na fila */ 
int tamanho_fila(Fila *fila);