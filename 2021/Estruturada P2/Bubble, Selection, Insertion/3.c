#include <stdio.h>
#include <stdlib.h>
#define tam 15
void preencher(int vetor[]);
void ordenar(int vetor[]);
void imprimir(int vetor[]);

int main(){
	int vetor[tam];
	
	preencher(vetor);
	printf("Antes\n");
	imprimir(vetor);
	ordenar(vetor);
	printf("Depois\n");
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
	int i,j,aux,min;
	
	for(i = 0; i < tam-1;i++){
		min=i;
		for(j = i+1 ;j < tam;j++){
			if(vetor[j]<vetor[min]){
				min=j;
			}
		}
		aux=vetor[i];
		vetor[i]=vetor[min];
		vetor[min]=aux;
	}
	
}
void imprimir(int vetor[]){
	int i;

	for(i = 0 ;i < tam; i++){
		printf("%d\n",vetor[i]);
	}
}
