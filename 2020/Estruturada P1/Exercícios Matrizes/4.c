#include <stdio.h>
#include <stdlib.h>
#define L 5
#define C 3

void preencher(float matrizA[L][C], float matrizB[L][C]);
void calcular(float matrizA[L][C], float matrizB[L][C], float matrizC[L][C]);
void imprimir(float matrizC[L][C]);

int main(){
	float matrizA[L][C], matrizB[L][C], matrizC[L][C];

	preencher(matrizA, matrizB);
	calcular(matrizA, matrizB, matrizC);
	imprimir(matrizC);

	return 0;
}
void preencher(float matrizA[L][C], float matrizB[L][C]){
	int i,j;

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			scanf("%f", &matrizA[i][j]);
		}
	}

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			scanf("%f", &matrizB[i][j]);
		}
	}
}
void calcular(float matrizA[L][C], float matrizB[L][C], float matrizC[L][C]){
	int i,j;

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			matrizC[i][j] = matrizA[i][j] + matrizB[i][j]; 
		}
	}
}
void imprimir(float matrizC[L][C]){
	int i,j;
	
	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			printf("%.2f ", matrizC[i][j]);	
		}
		printf("\n");
	}
	
}
