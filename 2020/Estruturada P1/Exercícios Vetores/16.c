#include <stdio.h>
#include <stdlib.h>
#define tam 30
void preenche(int *vetor[]);
int verificar(int *vetor[]);
int main(){
	int vetor[tam],resp;

	preenche(vetor);
	resp=verificar(vetor);
		
	if(resp == tam-1){
		printf("Vetor esta em ordem nao crescente!");
	}
	if(resp != tam-1){
		printf("Vetor nao esta em ordem nao crescente!");	
	}
	
	return 0;
}
	
void preenche(int *vetor[]){
	int i;

	printf("Digite 30 numeros inteiros: \n");
	for (i = 0; i < tam; ++i)
	{
		scanf("%d", &vetor[i]);
	}
	printf("\n");
}
int verificar(int *vetor[]){
	int i,d=0;
	
	for (i = 0; i < tam-1; ++i)
	{
		if(vetor[i] <= vetor[i+1]){
			d++;
		}
	}
	return d;
}

