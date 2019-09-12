#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// ========================================
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
//=========================================
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
//===========================================

int best_lap(int n, double *laps)  // Calculates the best lap
{
	double val = laps[0];  // At first, the first lap is also the best lap
	int best = 0;
	for (int i = 1; i < n; ++i)  // Compares from the second to the last
	{
		if (val > laps[i])  // If the current best lap took longer, it must change
		{
			val = laps[i]; 
			best = i;
		}
	}
	return best;
}

int worst_lap(int n, double *laps)  // Calculates the best lap
{
	double val = laps[0];  // At first, the first lap is also the worst lap
	int worst = 0;
	for (int i = 1; i < n; ++i)  // Compares from the second to the last
	{
		if (val < laps[i])  // If the current best lap took longer, it must change
		{
			val = laps[i]; 
			worst = i; 
		}
	}
	return worst;
}

double time(int lap_number, double *laps) {return laps[lap_number];}  // Gets time from lap

double average(int n, double *laps)  // Basic arithmetic average function
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
// ============================================
void fill_array(int size, int array_name, int *p)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d[%d]: ", array_name, i);
		scanf("%d", &p[i]);
		printf("\n");
	}
}

int scalar_product(int size, int *p1, int *p2)  // Pre-condition: Both arrays have the same size
{
	int sp = 0;
	for (int i = 0; i < size; ++i)
	{
		sp += (p1[i] * p2[i]);
	}
	return sp;
}

void q4() {
	int n;
	printf("Size: ");
	scanf("%d", &n);
	int v1[n]; int v2[n]; int result;
	printf("Insira os valores do Vetor 1\n");
	fill_array(n, 1, v1);
	printf("Insira os valores do Vetor 2\n");
	fill_array(n, 2, v2);
	result = scalar_product(n, v1, v2);
	printf("Result: %d\n", result);
}
// =======================================================
void q5() {
	
	int a[10] = {9, 6, 1, 2, 7, 4, 0, 9, 8, 5}; 
	int b[10] = {9, 8, 1, 5, 3, 7, 9, 0, 4, 2};
	int r[11];  // Result must always have 1 more slot than a and b.
	for (int i = 9; i >= 0; --i)
	{
		int aux = a[i] + b[i];
		if (aux >= 10)
		{
			r[i+1] = aux - 10;
			if (i == 0)
			{
				r[i] = 1;
			}
			a[i-1] += 1;
		}
		else r[i+1] = aux;
	}
	for (int i = 0; i < 11; ++i)
	{
		printf("%d ", r[i]);
	}
}
// ===============================================
int buscar (int numero, int *sequencia)
{
	//int tamanho = sizeof(sequencia);
	for(int i = 0; i < 5; ++i)
	{
		//printf("Comparando %d com %d\n", numero, sequencia[i]);
		if (numero == sequencia[i]) {/*printf("Deu\n");*/ return i;}
		//printf("Passou\n");
	}
	return -1;
}
void q6() {
	int n, x = 0, indice;
	printf("Digite o tamanho: ");
	scanf("%d", &n);
	int v[n];
	for (int i = 0; i < n; ++i)
	{
		printf("v[%d]: ", i);
		scanf("%d", &v[i]);
	}
	printf("Que número deseja procurar? ");
	scanf("%d", &x);
	indice = buscar(x, v);
	if (indice != -1) {printf("%d encontrado no índice %d", v[indice], indice);}
	else {printf("Número não encontrado");}
}
// =========================================
void troca (int *x, int *y) 
{
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

void ordena (int *sequencia, int n)
{
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for (int i = 0; i < (n - 1); ++i)
		{
			if (sequencia[i] > sequencia[i+1])
			{
				flag = 1;
				troca(&sequencia[i], &sequencia[i+1]);
			}
		}
	}
}

void q7() {
	int n;
	printf ("Digite o tamanho da sequencia: \n");
	scanf("%d", &n);
	int *v = (int*) malloc (n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		printf("v[%d]: ", i);
		scanf("%d", &v[i]);
	}
	ordena(v, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", v[i]);
	}

}
// ===================================
void fill_matrix(int **m, int lin, int col)
{
	for (int i = 0; i < lin; ++i)
	{
		fill_array(col, i, m[i]);
	}
}
int repeticoes (int **v, int m, int n, int num)
{
	int rep = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((v[i][j]) == num) ++rep;
		}
	}
	return rep;
}
void q8() {
	//int matrix[3][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
	int lin, col, num;  // Lines, columns, number
	printf("Linhas: ");
	scanf("%d", &lin);
	printf("Colunas: ");
	scanf("%d", &col);
	int **matrix = (int**) malloc(lin*sizeof(int*));  // Dynamically allocating matrix with "lin" lines
	for(int i = 0; i < lin; ++i)
	{
		int *line = (int*) malloc(col*sizeof(int));  // Dynamically allocating line with "col" columns
		matrix[i] = line;  // Pass line with "col" columns to one of the matrix's lines
	}
	fill_matrix(matrix, lin, col);
	printf("Digite o numero que quer procurar: ");
	scanf("%d", &num);
	printf("Repeticoes: %d\n\n", repeticoes(matrix, lin, col, num));
}
// ==========================================

void play(char player, char** matrix)
{
	int lin, col;
	do {
		printf("Coordinates: ");
		scanf("%d %d", &lin, &col);
		if (matrix[lin][col] != '.')
		{
			printf("Invalid coordinate!\n");
		}
	}while (matrix[lin][col] != '.');
	matrix[lin][col] = player;
}
int is_winner(char player, char** matrix)
{
	if 		((matrix[0][0] != '.') && (matrix[0][0] == matrix[1][1]) && (matrix[1][1] == matrix[2][2])) // Diagonal Principal
		/* printf("Case 1");*/return 1;
	else if ((matrix[0][2] != '.') && (matrix[0][2] == matrix[1][1]) && (matrix[1][1] == matrix[2][0])) // Diagonal Secund.
		/* printf("Case 2");*/return 1;
	else if ((matrix[0][0] != '.') && (matrix[0][0] == matrix[0][1]) && (matrix[0][1] == matrix[0][2])) // Primeira linha
		/* printf("Case 3");*/return 1;
	else if ((matrix[1][0] != '.') && (matrix[1][0] == matrix[1][1]) && (matrix[1][1] == matrix[1][2])) // Segunda linha
		/* printf("Case 4");*/return 1;
	else if ((matrix[2][0] != '.') && (matrix[2][0] == matrix[2][1]) && (matrix[2][1] == matrix[2][2])) // Terceira linha
		/* printf("Case 5");*/return 1;
	else if ((matrix[0][0] != '.') && (matrix[0][0] == matrix[1][0]) && (matrix[1][0] == matrix[2][0])) // Primeira coluna
		/* printf("Case 6");*/return 1;
	else if ((matrix[0][1] != '.') && (matrix[0][1] == matrix[1][1]) && (matrix[1][1] == matrix[2][1])) // Segunda coluna
		/* printf("Case 7");*/return 1;
	else if ((matrix[0][2] != '.') && (matrix[0][2] == matrix[1][2]) && (matrix[1][2] == matrix[2][2])) // Terceira coluna
		/* printf("Case 8");*/return 1;
	return 0;
}
char next_player(char *player)
{
	if (*player == 'o') return ('x');
	else return ('o');
}
void show_matrix(char **m)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			printf("%c ", m[i][j]);
		}
		printf("\n");
	}
}
void fill_matrix_2(char **m)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m[i][j] = '.';
		}
	}
}	
void q9() {
	int someone_won = 0;
	char player = 'x';
	char **matrix = (char**) malloc(3*sizeof(char*));  // Dynamically allocating matrix with "lin" lines
	for(int i = 0; i < 3; ++i)
	{
		char *line = (char*) malloc(3*sizeof(char));  // Dynamically allocating line with "col" columns
		matrix[i] = line;  // Pass line with "col" columns to one of the matrix's lines
	}
	fill_matrix_2(matrix);
	while (!someone_won)
	{
		printf("Player %c 's turn: \n", player);
		show_matrix(matrix);
		play(player, matrix);
		if (is_winner(player, matrix)) {someone_won = 1;}
		else {printf("Here: "); player = next_player(&player);}
	}
	printf("Player %c won!\n", player);
	show_matrix(matrix);
}
// ===================================================
int calcula_nota(int aluno, char** m, char *g, int n_questoes)
{
	int acertos = 0;
	for (int j = 0; j < n_questoes; ++j)
	{
		if (m[aluno][j] == g[j]) ++acertos;
	}
	return acertos;
}


void q10() {
	int matriculas[3] = {0, 0, 0};
	int n_questoes = 3;
	char *gabarito = (char*) malloc(n_questoes*sizeof(char)); 
	double n_aprovados = 0, perc_aprov = 0;
	char **respostas = (char**) malloc(3*sizeof(char*));  // Dynamically allocating matrix with "lin" lines
	for(int i = 0; i < 3; ++i)
	{
		char *r_aluno = (char*) malloc(n_questoes*sizeof(char));  // Dynamically allocating line with "col" columns
		respostas[i] = r_aluno;  // Pass line with "col" columns to one of the matrix's lines
	} 
	printf("-- Insira o gabarito --\n");
	for (int i = 0; i < n_questoes; ++i)
	{
		printf("Questão %d: ", i);
		scanf(" %c", &gabarito[i]);
	}
	for (int i = 0; i < 3; ++i)
	{
		printf("Insira a matricula do Aluno %d: ", i);
		scanf("%d", &matriculas[i]);
		printf("Insira as questões do Aluno %d\n", matriculas[i]);
		for (int j = 0; j < n_questoes; ++j)
		{
			printf("Questão %d: ", j);
			scanf(" %c", &respostas[i][j]);
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		printf("-- Aluno %d - Matricula %d -- \n", i, matriculas[i]);
		printf("Respostas: \n");
		for (int j = 0; j < n_questoes; ++j)
		{
			printf("%c ", respostas[i][j]);
		}
		int nota = calcula_nota(i, respostas, gabarito, n_questoes);
		printf("\nNota: %d\n\n", nota);
		if (nota >= 2) ++n_aprovados;
	}
	perc_aprov = n_aprovados / 3.0;
	printf("Percentual de aprovação: %.3lf", perc_aprov);
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