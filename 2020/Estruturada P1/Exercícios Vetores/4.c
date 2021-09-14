/*4) Faça um algoritmo para ler (pelo teclado) os 25 elementos de um vetor do tipo inteiro e verificar se o mesmo
está em ordem não-decrescente. Crie e utilize um procedimento para preencher o vetor e uma função para a
verificação. A impressão da informação (se o vetor está ou não em ordem não-decrescente) deve ser na função
main.*/
#include <stdio.h>
#include <stdlib.h>
#define tam 25
void preenche(int *vetor[]);
int verificar(int *vetor[]);
int main(){
	int vetor[tam],resp;

	preenche(vetor);
	resp=verificar(vetor);
		
	if(resp == tam-1){
		printf("Vetor esta em ordem nao decrescente!");
	}
	if(resp != tam-1){
		printf("Vetor nao esta em ordem nao decrescente!");	
	}
	
	return 0;
}
	
void preenche(int *vetor[]){
	int i;

	printf("Digite 25 numeros inteiros: \n");
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
		if(vetor[i] >= vetor[i+1]){
			d++;
		}
	}
	return d;
}

