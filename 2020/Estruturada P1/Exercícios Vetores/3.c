/*3) Considere um vetor com 40 números inteiros positivos gerados aleatoriamente de 1 a 100. Faça um algoritmo
para vericar o número de vezes que um número inteiro positivo n lido pelo teclado aparece neste vetor. O
programa também deve informar em quais posições (índices) do vetor o número aparece, caso ele pertença ao
vetor. Crie e utilize dois procedimentos: um para preencher o vetor e outro para realizar a vericação.
Obs. 1: O seu programa deve vericar primeiro quantas vezes o número n aparece no vetor. Depois, se ele
aparecer alguma vez no vetor, imprimir as posições que ele aparece. Se ele não pertencer ao vetor, seu programa
deve imprimir: "Número não pertence ao vetor".
Obs. 2: O exemplo da Figura 1 preenche e imprime um vetor com 10 números inteiros positivos de 1 a 10
gerados aleatoriamente.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 40
void gerando_vetor(int *vetor[tam]);
void verificacao(int *vetor[tam],int verifica);
int main(){
	int *vetor[tam],verifica;

	gerando_vetor(vetor);
	
	printf("Digite o valor para verificacao: ");
	scanf("%d", &verifica);
	
	verificacao(vetor,verifica);

	return 0;

}
void gerando_vetor(int *vetor[tam]){
	int i;
	
	srand(time(NULL));
	
	for (i = 0; i < tam; ++i)
	{
		vetor[i]=0;
		vetor[i]= rand()% 100 + 1;
	}

	printf("\n-------Vetor---------\n");
	for (i = 0; i < tam; ++i)
	{
		printf("%d ",vetor[i]);
	}
	printf("\n---------------------\n");
}
void verificacao(int *vetor[tam],int verifica){
	int i,quantidade=0;

	for (i = 0; i < tam; ++i)
	{
		if(vetor[i] == verifica){
			quantidade = quantidade + 1;
		}
	}
	if(quantidade != 0){
		printf("O numero aparece %d vezes!\n", quantidade);
		for (i = 0; i < tam; ++i)
		{
			if(vetor[i] == verifica){
				printf("Indice %d\n", i);
			}
		}	
	}
}
