#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define l 50
#define c 20
void ler(char matriz[][c], int tamanho[]);
void imprimir(char matriz[][c], int tamanho[]);
int main(){

	char matriz[l][c];
	int tamanho[l];

	ler(matriz,tamanho);
	imprimir(matriz,tamanho);

	return 0;
}
void ler(char matriz[][c],int tamanho[]){
	int i,j,k;
	char auxiliar[c];
	
	printf("Digite o nome:\n");
	
	for(i=0; i<l; i++){
		scanf("%[^\n]s", auxiliar);
		fflush(stdin);
		tamanho[i]=strlen(auxiliar);
		
		for(k=0;k < tamanho[i] ;k++){
			matriz[i][k]=auxiliar[k];
		}
		
		for(k=0;k < tamanho[i];k++){
			auxiliar[k]=0;
		}
	}
}
void imprimir(char matriz[][c], int tamanho[]){
	int i,j;
	
	for(i=0; i<l; i++){
		printf("\n");
		for(j=(tamanho[i]-1);j>=0;j--){
			printf("%c",matriz[i][j]);
		}
	}
}
