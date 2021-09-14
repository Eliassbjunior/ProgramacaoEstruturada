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

void imprime(int *vetor, int *n){
	
	int i,j, cont=1, posi;
	printf("\nValores impressos: \n");
	for (i=0;i<TAM;i++){
		cont = 1;
		for(j=0;j<i;j++){
			if(vetor[i] == vetor[j])
				cont++;	
		}
		
		if (cont == n)
			printf("O valor %d aparece %d vezes", vetor[i], n);		
	}	
}

int main (){
	
	printf("####### imprime valores que aparece repetidos N vezes ######\n");
	
	int vetor[TAM], n;
	
	printf("Insira o valor de N(1 <= n <= 100)\n");
	scanf("%d", &n);
	
	preencheVetor(vetor);
	
	imprime(vetor, n);
		
	return 0;
}
