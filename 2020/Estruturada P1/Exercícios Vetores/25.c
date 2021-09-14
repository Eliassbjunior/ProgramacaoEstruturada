#include <stdlib.h>
#include <stdio.h>

#define TAM 100

void preencheVetor(int *vetor){
	
	int i;
	printf("Insira os valores do vetor\n");
	for (i=0;i<TAM;i++){
		scanf("%d ", &vetor[i]);
	}
}

void imprime(int *vetor){
	
	int i,j, cont=0;
	printf("\nValores impressos: \n");
	for (i=0;i<=TAM;i++){
		for(j=0;j<i;j++){
			if(vetor[i] == vetor[j]){
				vetor[i] = 0;
			}else continue;
		}
		if (vetor[i] != 0)
			printf("%d ", vetor[i]);
	}	
}

int main (){
	
	printf("####### Não imprime valores repetidos ######\n");
	
	int vetor[TAM];
	
	preencheVetor(vetor);
	
	imprime(vetor);
		
	return 0;
}
