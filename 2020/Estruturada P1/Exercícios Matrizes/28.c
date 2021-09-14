#include <stdio.h>
#include <stdlib.h>
#define TAM 20

void inserir_digrafo(int matriz_A[][TAM]);
void criar_digrafo_R(int matriz_A[][TAM]);

int main(){
	int matriz_A[TAM][TAM];

	inserir_digrafo(matriz_A);
	criar_digrafo_R(matriz_A);

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
void criar_digrafo_R(int matriz_A[][TAM]){
	int i,j,matriz_R[TAM][TAM];
	

	for (i = 0; i < TAM; ++i)
	{
		for (j = 0; j < TAM; ++j)
		{
			if(i!=j){

				if(matriz_A[i][j] == 1){
					matriz_R[i][j]=0;
				}else{
					if(matriz_A[i][j] == 0){
						matriz_R[i][j]=1;
					}
				}
			}else{
				if(i==j){
					matriz_R[i][j]=0;
				}

			}
		}
	}
}