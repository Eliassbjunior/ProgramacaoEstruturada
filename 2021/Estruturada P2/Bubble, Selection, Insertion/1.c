#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 15
void preencher(int vetor[]);
void ordenar(int vetor[]);
void imprimir(int vetor[]);

int main(){
	int vetor[tam];
	
	preencher(vetor);
	ordenar(vetor);
	imprimir(vetor);
}
void preencher(int vetor[]){
	int i;

	printf("Digite 15 numeros: \n");
	for(i = 0; i < tam; i++){
		scanf("%d", &vetor[i]);
	}
}
void ordenar(int vetor[]){
	int i,j,aux;
	
	for(i = 0; i < tam; i++){
		for(j = 0; j < tam-1; j++){
			
			if(vetor[j]<vetor[j+1]){
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
			}
		}
	}
}
void imprimir(int vetor[]){
	int i;

	for(i = 0 ;i < tam; i++){
		printf("%d\n",vetor[i]);
	}
}

