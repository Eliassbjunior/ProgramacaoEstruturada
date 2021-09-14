/*2) Faça um algoritmo para ler pelo teclado uma matriz 3 x 5 com valores reais e
imprimir quantos valores maiores do que 20 ela possui. Crie e utilize um procedimento
para a leitura da matriz e uma função para fazer o cálculo. A impressão da informação
(quantos valores maiores do que 20) deve ser na função main.*/

#include <stdio.h>
#include <stdlib.h>
#define L 3
#define C 5
void preencher(float matriz[L][C]);
int calcular(float matriz[L][C]);

int main(){
	float matriz[L][C];
	int verificacao = -1;

	preencher(matriz);
	verificacao = calcular(matriz);

	if(verificacao == -1){
		printf("Erro!");
	}else{
		printf("\n%d valores maiores que 20!", verificacao);
	}

	return 0;
}

void preencher(float matriz[L][C]){
	int i,j;

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			scanf("%f", &matriz[i][j]);
		}
	}
}
int calcular(float matriz[L][C]){
	int i,j,quantidade=0;

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			if(matriz[i][j] > 20){
				quantidade++;
			}
		}
	}
	return quantidade;
}
