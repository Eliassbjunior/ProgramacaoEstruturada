#include <stdio.h>
#include <stdlib.h>
#define TAM 20

void inserir_grafo(int matriz_A[][TAM]);
int verificando_grafo(int matriz_A[][TAM]);

int main(){
	
	int retorno=0,matriz_A[TAM][TAM];

	inserir_grafo(matriz_A);
	retorno=verificando_grafo(matriz_A);

	if(retorno == 1){
		printf("E uma matriz de adjacencia!\n");
	}else{
		if(retorno == 0){
			printf("Nao e uma matriz de adjacencia\n");
		}
	}

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
int verificando_grafo(int matriz_A[][TAM]){
	int i,j,somatorio=0;
	
	for(i = 0; i < TAM; ++i){
		if(matriz_A[i][i] == 0){
			somatorio+=1;
		}
	}
	
	if(somatorio == TAM){

		for (i = 0; i < TAM/2; ++i)
		{
			for (j = 0; j < TAM/2; ++j)
			{
				if(matriz_A[i][j] == matriz_A[j][i] && i!=j){
					somatorio+=1;		
				}
			}
		}
		
		if(somatorio == TAM*TAM){
			return 1;
		}else{
			return 0;
		}	
	}else{

		return 0;
	}
}
