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
void remove (char *string, char caractere)
{
  int index = 0;
  char item = string[index];
  while (item != '\0')
  {
    if (item == caractere) {string[index] = '0';}
    ++index;
    item = string[index];
  }
}
void titulo (char *string)
{
  char *letra = (char*) malloc (1 * sizeof(char));
  letra = string[0];
  troca[letra];
  
}
void inserir_vetor(char *string, int n)
{
  for (int i = 0; i < n; ++i)
  {
    printf("Posicao %d: ", i);
    scanf(" %c", &string[i]);
  }
  printf("\n");
}
void mostrar_vetor(char *string)
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
  char *vetor = (char*) malloc ((n+1)*sizeof(char));  // Allocate n+1 slots, last slot (n) will stop the function
  inserir_vetor(vetor, n);
  printf("Antes da inversão: ");
  mostrar_vetor(vetor);
  troca(vetor);
  printf("Depois da inversão: ");
  mostrar_vetor(vetor);
}
// ==============================================
void q2() {

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
