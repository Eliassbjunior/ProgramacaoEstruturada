#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 7
#define C 3
void preencher(int matriz[L][C]);
void calcular(int matriz[L][C], int matrizT[C][L]);
void imprimir(int matriz[L][C], int matrizT[C][L]);

int main(){
	int matriz[L][C], matrizT[C][L];
	
	preencher(matriz);
	calcular(matriz,matrizT);
	imprimir(matriz,matrizT);

	return 0;
}
void preencher(int matriz[L][C]){
	int i,j;

	srand(time(NULL));

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			matriz[i][j] = 0;
			matriz[i][j] = rand()%25 + 1;
		}
	}
}
void calcular(int matriz[L][C], int matrizT[C][L]){
	int i,j;

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			matrizT[j][i] = matriz[i][j];
		}
	}
}
void imprimir(int matriz[L][C], int matrizT[C][L]){
	int i,j;
	
	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			printf("%d ", matriz[i][j]);	
		}
		printf("\n");
	}
	

	for(i = 0; i < C; i++){
		for(j = 0; j < L; j++){
			printf("%d ", matrizT[i][j]);	
		}
		printf("\n");
	}
}