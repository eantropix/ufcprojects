#include <stdio.h>
#include <stdlib.h>
// ==============================================
void troca (char *string)
{
  int index = 0;
  char item = string[index];
  while (item != '\0')
  {
    if ((65 <= item) && (item <= 90)) {string[index] = (item + 32);}
    else if ((97 <= item) && (item <= 122)) {string[index] = (item - 32);}
    else if (item == ' ') {continue;}
    else {printf("Trocou n kkk"); break;}
    ++index;
    item = string[index];
  }
}
int ocorrencia (char *string, char caractere)
{
  int n_ocorre = 0;
  int index = 0;
  char item = string[index];
  while (item != '\0')
  {
    if (item == caractere) {++n_ocorre;}
    ++index;
    item = string[index];
  }
  return n_ocorre;
}
void remover (char *string, char caractere)
{
  int index = 0;
  char item = string[index];
  while (item != '\0')
  {
    if (item == caractere) {string[index] = ' ';}
    ++index;
    item = string[index];
  }
}
void titulo (char *string)
{
  char *letra = (char*) malloc (1 * sizeof(char));
  letra = &string[0];
  troca(letra);
}
void inverte (char *string)
{
  int index = 0, dir = 0, tam = 0;
  char item = string[index];
  while (item != '\0')
  {
    dir = index;
    ++tam; ++index;
    item = string[index];
  }
  for (int esq = 0; esq < (tam / 2); ++esq, --dir)
  {
    char aux = string[esq];
    string[esq] = string[dir];
    string[dir] = aux;
  }
}
void inserir_string(char *string)
{
  printf("Vetor: ");
  scanf(" %[^\n]s", string);
  printf("\n");
}
void mostrar_string(char *string)
{
  int index = 0;
  char item = string[index];
  while (item != '\0')
  {
    printf(" %c", item);
    ++index;
    item = string[index];
  }
  printf("\n\n");
}
void q1() {
  int n;
  printf("Tamanho: ");
  scanf("%d", &n);
  char *vetor = (char*) malloc ((n+1)*sizeof(char));
  inserir_string(vetor);
  printf("Antes da troca: ");
  mostrar_string(vetor);
  troca(vetor);
  printf("Depois da troca: ");
  mostrar_string(vetor);
  titulo(vetor);
  printf("Mudando o titulo: ");
  mostrar_string(vetor);
  inverte(vetor);
  printf("E pra inverter essa bagaça: ");
  mostrar_string(vetor);
  remover(vetor, 'a');
  printf("Agora a gente tira esse 'a': ");
  mostrar_string(vetor);
}
// ==============================================
int acha_index(char *string, int *dir)
{
  int index = 0, esq = 0, dir = 0, tam = 0, erros = 0, flag = 1;
  char item = string[index];
  while (item != '\0')  // Loop para pegar o último índice do vetor, e o seu tamanho
  {
    dir = index;
    ++tam; ++index;
    item = string[index];
  }
}
int eh_palindromo(char *string)
{
  int index = 0, esq = 0, dir = 0, tam = 0, erros = 0, flag = 1;
  char item = string[index];
  while (item != '\0')  // Loop para pegar o último índice do vetor, e o seu tamanho
  {
    dir = index;
    ++tam; ++index;
    item = string[index];
  }
  while (esq < (tam / 2) && flag)
  {
    if (string[esq] == ' ') {++esq;}
    if (string[dir] == ' ') {--dir;}
    if (string[esq] != string[dir]) {++erros;}
    if (erros) flag = 0;
    ++esq; --dir;
  }
  if (erros) {return 0;}
  else       {return 1;}
}
void q2() {
  int n;
  printf("Digite o tamanho: ");
  scanf("%d", &n);
  char *str = (char*) malloc (n*sizeof(char));
  printf("Digite a frase: ");
  scanf(" %[^\n]s", str);
  int res = eh_palindromo(str);
  if (res) {printf("Palindromo");}
  else     {printf("Não palindromo");}
}
// ========================================================

int ocorrencia(char *frase, char *palavra)
{

}

void q3() {

}

void q4() {
}

void q5() {
}

void q6() {
}

void q7() {
}

void q8() {
}

int main(void) {
  int n;
  printf("Digite o número da questão: ");
  scanf("%d", &n);
  
  switch(n) {
    case 1: q1(); break;
    case 2: q2(); break;
    case 3: q3(); break;
    case 4: q4(); break;
    case 5: q5(); break;
    case 6: q6(); break;
    case 7: q7(); break;
    case 8: q8(); break;
    default : break;
  }
  return 0;
}
