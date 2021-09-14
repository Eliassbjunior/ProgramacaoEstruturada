#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6
void preencher(int matriz[TAM][TAM]);
int verificar(int matriz[TAM][TAM]);

int main(){
	int matriz[TAM][TAM],verificado = 0;

	preencher(matriz);
	verificado = verificar(matriz);

	if(verificado == 1){
		printf("MATRIZ SIMETRICA\n");
	}else{
		printf("MATRIZ NAO SIMETRICA\n");
	}

	return 0;
}
void preencher(int matriz[TAM][TAM]){
	int i,j;

	srand(time(NULL));

	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			matriz[i][j] = 0;
			matriz[i][j] = rand()%50 + 1;
		}
	}
}
int verificar(int matriz[TAM][TAM]){
	int i,j;

	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			if(matriz[i][j] != matriz[j][i]){
				return 0;
			}
		}
	}
	return 1;
}