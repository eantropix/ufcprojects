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
int min_n(int *v)  // Gets smallest number from array
{
	int min = v[0];
	for (int i = 0; i < 10; ++i)
		{
			if (v[i] < min) {min = v[i];}
		}
	return min;
}
int max_n(int *v)  // Gets greatest number from array
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

int best_lap(int n, double *laps)
{
	double val = laps[0];
	int best = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (val > laps[i]) {val = laps[i]; best = i; printf("Actual best: %d\n", best);}
	}
	return best;
}

int worst_lap(int n, double *laps)
{
	double val = laps[0];
	int worst = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (val < laps[i]) {val = laps[i]; worst = i; printf("Actual worst: %d\n", worst);}
	}
	printf("%d", worst);
	return worst;
}

double time(int volta, double *laps) {return laps[volta];}

double average(int n, double *laps)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += laps[i];
	}
	double avg = (sum / n);
	return avg;
}
void q3() {
	int N = 0, n_best = 0, n_worst = 0;
	double t_best = 0, t_worst = 0, t_avg = 0;
	printf("Número de voltas: ");
	scanf("%d", &N);
	double laps[100] = {0.0};
	printf("Digite o tempo das voltas\n");
	for (int i = 0; i < N; ++i)
	{
		printf("Volta %d: ", i);
		scanf("%lf", &laps[i]);
	}
	n_best = best_lap(N, laps);
	n_worst = worst_lap(N, laps);
	t_best = time(n_best, laps);
	t_worst = time(n_worst, laps);;
	t_avg = average(N, laps);
	printf("===Resultados===\n");
	printf("Melhor volta: %d - Tempo: %lf\n", n_best, t_best);
	printf("Pior volta: %d - Tempo: %lf\n", n_worst, t_worst);
	printf("Média de tempo: %lf\n", t_avg);
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