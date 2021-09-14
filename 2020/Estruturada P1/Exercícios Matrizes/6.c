#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 2
#define C 8
void preencher(int matrizPrincipal[L][C]);
void calcular(int matrizPrincipal[L][C], int matrizResultante[L][C], int X);
void imprimir(int matrizC[L][C]);

int main(){
	int matrizPrincipal[L][C], matrizResultante[L][C], X;
	
	preencher(matrizPrincipal);
	scanf("%d", &X);
	calcular(matrizPrincipal,matrizResultante,X);
	imprimir(matrizResultante);

	return 0;
}
void preencher(int matrizPrincipal[L][C]){
	int i,j;

	srand(time(NULL));

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			matrizPrincipal[i][j] = 0;
			matrizPrincipal[i][j] = rand()%29 + 1;
		}
	}
}
void calcular(int matrizPrincipal[L][C], int matrizResultante[L][C], int X){
	int i,j;

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			matrizResultante[i][j] = matrizPrincipal[i][j] * X;
		}
	}
}
void imprimir(int matrizC[L][C]){
	int i,j;
	
	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			printf("%d ", matrizC[i][j]);	
		}
		printf("\n");
	}
	
}
