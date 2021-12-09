#include <stdio.h>
#include <time.h>
#define tam 20

void preenche(int vetor[]);
void ordenar(int vetor[]);
void imprime(int vetor[]);

int main(){
	int vetor[tam];
	preenche(vetor);
	ordenar(vetor);
	imprime(vetor);
	
	return 0;
}

void preenche(int vetor[]){
	int i;
	srand(time(NULL));
	for(i=0; i<tam; i++){
		vetor[i]=rand()%30+1;
	}
}
//InsertionSort Decrescente
void ordenar(int vetor[]){
	int i, j, aux, valor;
	for(i=1; i<tam; i++){
		valor=vetor[i];
		for(j=i-1;(j>=0)&&(valor>vetor[j]); j--){
			vetor[j+1]=vetor[j];
		}
		vetor[j+1]=valor;
	}
}

void imprime(int vetor[]){
	int i;
	for(i=0; i<tam; i++){
		printf("%d ", vetor[i]);
	}
}