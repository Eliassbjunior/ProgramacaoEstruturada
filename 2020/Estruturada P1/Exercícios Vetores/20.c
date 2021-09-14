#include <stdio.h>
#include <stdlib.h>
#define tam 20
void ler(int vetor_A[]);
void preencher(int vetor_A[], int vetor_B[]);

int main(){
	int vetor_A[tam], vetor_B[tam];

	ler(vetor_A);
	preencher(vetor_A,vetor_B);

	return 0;
}
void ler(int vetor_A[]){
	int i;
	
	printf("Digite 20 numeros: \n");

	for (i = 0; i < tam; ++i)
	{
		scanf("%d", vetor_A[i]);
	}
}
void preencher(int vetor_A[], int vetor_B[]){
	int i,j;

	j=tam;
	for (i = 0; i < tam; ++i)
	{
		j--;
		vetor_B[j]=vetor_A[i];
	}
}