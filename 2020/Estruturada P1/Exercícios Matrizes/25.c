#include<stdio.h>
#include<stdlib.h>
#define TAM 10

void inserir_grafo(int matriz_A[][TAM]);
void verificando_vertice(int matriz_A[][TAM]);

int main(){
	
	int matriz_A[TAM][TAM];

	inserir_grafo(matriz_A);
	verificando_vertice(matriz_A);

	return 0;
}
void inserir_grafo(int matriz_A[][TAM]){
	int i,j;

	printf("Digite os valores da matriz de adjacencia: \n");
	for (i = 0; i < TAM; ++i)
	{
		for (j = 0; j < TAM; ++j)
		{
			scanf("%d", &matriz_A[i][j]);

			if(matriz_A[i][j] != 1 && matriz_A[i][j] != 0){
				do{

					printf("So e permitido 1 e 0 na matriz de adjacencia!\n");
					printf("Digite o valor da matriz de adjacencia: \n");
					scanf("%d", &matriz_A[i][j]);

				}while(matriz_A[i][j]!= 1 && matriz_A[i][j]!= 1);
			
			}
		}
	}
}
void verificando_vertice(int matriz_A[][TAM]){
	int i,j,grau=0;

	system("cls");
	for (i = 0; i < TAM; ++i)
	{
		for (j = 0; j < TAM; ++j)
		{
			printf("%d", matriz_A[i][j]);
		}
		printf("\n");

		
	}

	printf("\n");

	for (i = 0; i < TAM; ++i)
	{
		for (j = 0; j < TAM; ++j)
		{
			if(matriz_A[i][j] == 1){
				grau++;
			}
		}
		printf("Vertice %d e grau %d!\n",i+1,grau);
		grau=0;
	}
}
