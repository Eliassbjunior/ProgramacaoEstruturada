#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 30
void preencher(int vetor[]);
void modifica(int vetor[]);
void mostrar(int vetor[]);
int main(){
	int vetor[tam];
	
	preencher(vetor);
	modifica(vetor);
	mostrar(vetor);
		
	
}
void preencher(int vetor[]){
	int i;
	srand(time(NULL));
	
	for(i=0;i<tam;i++){
		vetor[i]=rand% 100+ 1;
	}
}


void modifica(int vetor[]){
	int somatorio=0,i;
	for(i=0;i< tam;i++){
		for(j=0;j<tam;j++){
			if(i !=j){
				somatorio += vetor[j];
			}
		}
	}
}
void mostrar(int vetor[]){
	int i;
	for(i=0;i<tam;i++){
		printf("%d ",vetor[i]);
	}
}
