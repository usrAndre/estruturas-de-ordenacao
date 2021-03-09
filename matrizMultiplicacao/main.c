// PROGRAMA PARA MULTIPLICAR MATRIZES 3X3 //

#include <stdio.h>

int multiplica_mat(int A[3][3], int B[3][3], int C[3][3]);
int imprime_mat(int M[3][3], char c);

int main()
{
	int matriz_A[3][3];
	int matriz_B[3][3];
	int matriz_C[3][3];
	int i=0, j=0, k=0, sum=0;

	// pega os valores do teclado para montar a matriz A
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Elemento a%i%i da matriz A: ", i+1, j+1);
			scanf("%i", &matriz_A[i][j]);
		}
	}

	// pega os valores do teclado para montar a matriz B
	printf("\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Elemento b%i%i da matriz B: ", i+1, j+1);
			scanf("%i", &matriz_B[i][j]);
		}
	}

	//calcula a matriz C=AxB
	multiplica_mat(matriz_A, matriz_B, matriz_C);

	// imprime as matrizes A, B, C
	imprime_mat(matriz_A, 'A');
	imprime_mat(matriz_B, 'B');
	imprime_mat(matriz_C, 'C');

	printf("\n");
	return 0;
}

int multiplica_mat(int A[3][3], int B[3][3], int C[3][3])
{
	int i=0, j=0, k=0, sum=0;

	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			for(k=0; k<3; k++)
			{
				sum += A[i][k] * B[k][j];
			}
			C[i][j]=sum;
			sum=0;
		}
	}

	return 0;
}

int imprime_mat(int M[3][3], char c)
{
	int i=0, j=0;

	printf("\nMatriz %c\n", c);
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%i  ", M[i][j]);
		}
		printf("\n");
	}

	return 0;
}
