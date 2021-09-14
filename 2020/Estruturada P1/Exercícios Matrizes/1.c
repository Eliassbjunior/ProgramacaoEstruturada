#include <stdio.h>
#include <stdlib.h>
#define L 4
#define C 3

void preencher(float matriz[L][C]);
void imprimir(float matriz[L][C]);

int main(){
	float matriz[L][C];
	
	preencher(matriz);
	imprimir(matriz);
	
	return 0;
}
void preencher(float matriz[L][C]){
	int i,j;
	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			scanf("%f", &matriz[i][j]);	
		}
	}
}
void imprimir(float matriz[L][C]){
	int i,j;
	float maior=0;
	
	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			if(matriz[i][j] >= maior){
				maior = matriz[i][j];
			}	
		}
	}
	printf("Maior numero: %.2f ", maior);
}
