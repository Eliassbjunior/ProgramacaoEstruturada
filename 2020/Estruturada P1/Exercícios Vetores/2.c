#include <stdio.h>
#include <stdlib.h>
#define tam 15
void preenche(int *vetor[tam]);
void inverter(int *vetor[tam]);
void imprimir(int *vetor[tam]);
int main(){
	int *vetor[tam];

	preenche(vetor);
	inverter(vetor);
	imprimir(vetor);

	return 0;
}
void preenche(int *vetor[tam]){
	int i;

	printf("Digite 15 numeros reais: \n");
	for (i = 0; i < tam; ++i)
	{
		scanf("%d", &vetor[i]);
	}
	printf("\n");
}
void inverter(int *vetor[tam]){
	int i,j,aux;
	for (i = 0; i < tam; ++i)
	{
		for (j = i+1; j < tam; ++j)
		{
			if(vetor[j]< vetor[i]){
				
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
			}
		}		
	}
}
void imprimir(int *vetor[tam]){
	int i;
	
	printf("\n");
	for (i = 0; i < tam; ++i)
	{
		printf("%d ", vetor[i]);
	}
}
