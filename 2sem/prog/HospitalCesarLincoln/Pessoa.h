/* TAD: Pessoa (idade, próximo)*/
struct pessoa
{
	unsigned int idade;
	Pessoa* seguinte;
};
typedef struct pessoa Pessoa;

/* Aloca e retorna uma pessoa */ 
Pessoa *cria_pessoa(int idade);

/* Libera a memória de uma pessoa previamente criada */ 
void libera_pessoa(Pessoa **pessoa);

/* Retorna o próxima da pessoa ou NULL caso contrário */ 
Pessoa *obtem_proximo(Pessoa *pessoa);

/* Adiciona o próxima da pessoa. Retorna 1 se der certo e 0 caso contrário */ 
int atribui_proximo(Pessoa *pessoa, Pessoa *proximo);

/* Retorna a idade da pessoa ou 0 se não for possível */
int obtem_idade(Pessoa *pessoa);