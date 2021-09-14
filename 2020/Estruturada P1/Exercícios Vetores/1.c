#include <stdio.h>
#include <stdlib.h>
#define tam 30
void preenche(float *vetor[tam]);
int verifica(float verificador,float *vetor[tam]);
int main(){
	float *vetor[tam], verificador;
	preenche(vetor);
	
	printf("Digite o numero para verificaca: ");
	scanf("%f", &verificador);

	resp=verifica(verificador,vetor);

	if(resp == 1){
		printf("Numero pertence ao vetor!\n");
	}else{
		printf("Numero nao pertence ao vetor!\n");
	}
	return 0
}
void preenche(float *vetor[tam]){
	int i;

	printf("Digite 30 numeros reais: \n");
	for (i = 0; i < tam; ++i)
	{
		scanf("%f", &vetor[i])
	}
	printf("\n");
}
int verifica(float verificador, float *vetor[tam]){
	int i;
	for (i = 0; i < tam; ++i)
	{
		if(verificador == vetor[i]){
			return 1;
		}
	}
	return 0;
}