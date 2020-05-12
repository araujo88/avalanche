#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Parametros {
int tamanho; // tamanho da matriz
int graos; // total de graos despejados
int intervalos; // intervalo entre os graos despejados em que será impressa a matriz
} pr;

int RandomInteger (int low, int high);
int **Alocar_matriz_real (int t);
int **Liberar_matriz_real (int t, int **v);
void Mostrar_matriz(int t, int **v);
void Zerar_matriz(int t, int **v);
void Preenche_matriz(int t, int **v);
void Verifica_avalanche(int t, int **v);
void Iteracoes(int **v, int t, int e, int it);
void Imprimir_data();

int main(void)
{
	int **m;
	pr p;	
	
	printf("\n\nUniversidade Federal do Rio Grande do Sul - Escola de Engenharia");
	printf("\nTrabalho final elaborado para a disciplina ENG03049 - Linguagem C para Engenharia - Prof. Bardo E. J. Bodmann");
	printf("\nAlgoritmo para avalanches de graos de areia baseado no modelo de Bak, Tang e Wiesenfeld - desenvolvido por Leonardo Antonio de Araujo - Versao 3\n");

	printf("\nDigite o tamanho da matriz:");
	scanf("%d", &p.tamanho);
	printf("\nDigite o numero de graos:");
	scanf("%d", &p.graos);
	printf("\nDigite o numero de intervalos entre os graos:");
	scanf("%d", &p.intervalos);

	m=Alocar_matriz_real(p.tamanho);
	Zerar_matriz(p.tamanho, m);
	Iteracoes(m, p.tamanho, p.graos, p.intervalos);

	m=Liberar_matriz_real(p.tamanho, m);	
	return 0;
}

void Iteracoes(int **v, int t, int e, int it)
{
	int i, n, a, b;

	n=it;

	printf("\n");
	if (v == NULL) {
		printf("** Erro: Abortando o programa **\n");
		exit(1);
	}
	if (t < 1)
	/* verifica parametros recebidos */
	{
	printf("** Erro: Parametro invalido **\n");
	exit(1);
	}

	for (i=1; i<=e; i++) {
		Preenche_matriz(t, v);
		Verifica_avalanche(t, v);
		if (i==it) {
			Mostrar_matriz(t, v);
			it=it+n;
		}
	}	
	printf("\nTarefa executada com exito.\n");
}

void Verifica_avalanche(int t, int **v)
{
	int i, j;

	if (v == NULL) {
		printf("** Erro: Abortando o programa **\n");
		exit(1);
	}
	if (t < 1)
	/* verifica parametros recebidos */
	{
	printf("** Erro: Parametro invalido **\n");
	exit(1);
	}
	
	for (i=0; i<t; i++) { 
		for(j=0; j<t; j++) {
			if ((v[i][j])>4) { // verifica se chegou ao nivel critico
				v[i][j]=v[i][j]-4;
				if(i+1<t-1) v[i+1][j]=v[i+1][j]+1;
				if(j+1<t-1) v[i][j+1]=v[i][j+1]+1;
				if(i-1>0) v[i-1][j]=v[i-1][j]+1;
				if(j-1>0) v[i][j-1]=v[i][j-1]+1;
				i=0; // recomeca a busca
				j=0;
			}
		}
	}
}

void Preenche_matriz(int t, int **v)
{
	int i, j, x, y;
	
	if (v == NULL) {
		printf("** Erro: Abortando o programa **\n");
		exit(1);
	}
	if (t < 1)
	/* verifica parametros recebidos */
	{
	printf("** Erro: Parametro invalido **\n");
	exit(1);
	}
	
	x=t/2;
	y=t/2;

	v[x][y]+=1;
}

void Zerar_matriz(int t, int **v)
{
	int i, j;

	if (v == NULL) {
		printf("** Erro: Abortando o programa **\n");
		exit(1);
	}
	if (t < 1)
	/* verifica parametros recebidos */
	{
	printf("** Erro: Parametro invalido **\n");
	exit(1);
	}
	
	for (i=0; i<t; i++) {
		for(j=0; j<t; j++) {
		 	v[i][j]=0;
		}
	}
}

void Mostrar_matriz(int t, int **v)
{
	int i, j;
	char c[4];	
	static int count=0;
	char nome[50];

	if (v == NULL) {
		printf("** Erro: Abortando o programa **\n");
		exit(1);
	}
	if (t < 1)
	/* verifica parametros recebidos */
	{
	printf("** Erro: Parametro invalido **\n");
	exit(1);
	}

	sprintf(nome,"test-1-%d.vtk", count);
	FILE *pf;
	
	if((pf = fopen(nome,"a")) ==NULL) {
		printf("\nErro ao abrir o arquivo\n");
		exit(1);
	}
	
	printf("\n%s", nome);

	fprintf(pf, "# vtk DataFile Version 2.0\n");
	fprintf(pf, "test\n");
	fprintf(pf, "ASCII\n");
	fprintf(pf, "DATASET STRUCTURED_POINTS\n");
	fprintf(pf, "DIMENSIONS %d %d 1\n", t, t);
	fprintf(pf, "ORIGIN 0 0 0\n");
	fprintf(pf, "SPACING 1 1 1\n");
	fprintf(pf, "POINT_DATA %d\n", t*t);
	fprintf(pf, "SCALARS values float\n");
	fprintf(pf, "LOOKUP_TABLE default");

	for (i=0; i<t; i++) {
		fprintf(pf, "\n");		
		for (j=0; j<t; j++) {
			if ((j==0)) {
				sprintf(c,"%d", v[i][j]);
				fprintf(pf, c);
			}
			else {
				sprintf(c," %d", v[i][j]);
				fprintf(pf, c);
			}
		}
	}
	fclose(pf);
	count++;
}

int **Alocar_matriz_real (int t)
{
	int **v; /* ponteiro para a matriz */
	int i; /* variavel auxiliar */
	if (t < 1)
	/* verifica parametros recebidos */
	{
	printf("** Erro: Parametro invalido **\n");
	return (NULL);
	}
	v = (int **) calloc (t, sizeof(int *)); /* Um vetor de m ponteiros para float */
	/* aloca as linhas da matriz */
	if (v == NULL)
	{
	printf("** Erro: Memoria Insuficiente **");
	return (NULL);
	}
	for ( i = 0; i < t; i++ )
	{
	v[i] = (int*) calloc (t, sizeof(int)); /* aloca as colunas da matriz */
	/* m vetores de n floats */
	if (v[i] == NULL)
	{
	printf("** Erro: Memoria Insuficiente **");
	return (NULL);
	}
	}
	return (v); /* retorna o ponteiro para a matriz */
}

int **Liberar_matriz_real (int t, int **v)
{
	int i; /* variavel auxiliar */
	if (v == NULL)
	return (NULL);
	if (t < 1)
	/* verifica parametros recebidos */
	{
	printf("** Erro: Parametro invalido **\n");
	return (v);
	}
	for (i=0; i<t; i++) free (v[i]); /* libera as linhas da matriz */
	free (v); /* libera a matriz (vetor de ponteiros) */
	return (NULL); /* retorna um ponteiro nulo */
}

int RandomInteger (int low, int high)
{
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}
