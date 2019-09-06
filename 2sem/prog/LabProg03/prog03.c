#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void q1() {
	int a[5] = {2, 3, 5, 7, 11};
	int b[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	for (int i = 0; i <= 5; ++i)
	{
		for (int j = 0; j <= 8; ++j)
		{
			if (a[i] == b[j]) {printf("%d, ", a[i]); ++i;}
		}
	}
}
//==================================
int min_n(int *v)
{
	int min = v[0];
	for (int i = 0; i < 10; ++i)
		{
			if (v[i] < min) {min = v[i];}
		}
	return min;
}
int max_n(int *v)
{
	int max = v[0];
	for (int i = 0; i < 10; ++i)
		{
			if (v[i] > max) {max = v[i];}
		}
	return max;
}
void q2() {
	int a[10] = {3, 4, 7, 8, 1, 2, 10, 5, 7, 6};
	printf("%d\n", min_n(a));
	printf("%d\n", max_n(a));
}
//==================================

int melhor_volta(int n, double *voltas)
{
	val = voltas[0];
	melhor = 0;
	for (int i = 1; i < n; ++i)
	{
		if (val > voltas[i] {val = voltas[i]; melhor = i;})
	}
	return melhor;
}

int pior_volta(int n, double *voltas)
{
	val = voltas[0];
	pior = 0;
	for (int i = 1; i < n; ++i)
	{
		if (val < voltas[i] {val = voltas[i]; pior = i;})
	}
	return pior;
}

double tempo(int volta, double *voltas)
{
	return voltas[volta];
}

double media(int n, double *voltas)
{
	double soma = 0;
	for (int i = 0; i < n; ++i)
	{
		soma += voltas[i];
	}
	double media = (soma / n);
	return media;
}
void q3() {
	int N = 0, n_melhor = 0, n_pior = 0;
	double t_melhor = 0, t_pior = 0, t_media = 0;
	printf("Número de voltas: ");
	scanf("%d", &N);
	double voltas[100] = {};
	printf("Digite o tempo das voltas\n");
	for (int i = 0; i < N; ++i)
	{
		printf("Volta %d: ", i+1);
		scanf("%lf", &voltas[i]);
	}
	t_melhor = melhor(N, &n_melhor, voltas);
	t_pior = pior(N, &n_pior, voltas);
	t_media = media(N, voltas);
	printf("===Resultados===\n");
	printf("Melhor volta: %d - Tempo: %lf\n", n_melhor, t_melhor);
	printf("Pior volta: %d - Tempo: %lf\n", n_pior, t_pior);
	printf("Média de tempo: %lf\n", t_media);
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

void q9() {
}

void q10() {
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
    case 9: q9(); break;
    case 10: q10(); break;
    default : break;
  }
  return 0;
}