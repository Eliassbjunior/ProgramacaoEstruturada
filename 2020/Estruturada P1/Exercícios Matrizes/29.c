#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void inserir_digrafo(int matriz_A[][TAM]);
void verificar(int matriz_A[TAM][TAM]);

int main(){
	int matriz_A[TAM][TAM];
	
	inserir_digrafo(matriz_A);
	verificar(matriz_A);
	
	return 0;
}
void inserir_digrafo(int matriz_A[][TAM]){
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
void verificar(int matriz_A[TAM][TAM]){

	int i,j,k,existencia=0;

	for (int i = 0; i < TAM; ++i)
	{
		for (j = 0; j < TAM; ++j)
		{
			if (matriz_A[i][j] == 1)
			{
				for (k = 0; k < TAM; ++k)
				{
					if (matriz_A[j][k] == 1)
					{
						if (matriz_A[k][i] == 1)
						{
							printf("Ciclo elementar: %d %d %d %d\n",i+1 ,j+1, k+1, i+1);
							existencia = 1;
						}
					}
				}
			}
		}
	}
	
	if (existencia == 0)
	{
		printf("Nao existe ciclo elementar!\n");
	}
}
