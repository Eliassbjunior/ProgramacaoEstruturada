/*3) Faça um algoritmo para ler pelo teclado uma matriz 4 x 4 com valores inteiros e
também um número inteiro x. Ao final, o algoritmo tem que imprimir se o número x
pertence ou não à matriz. O número x tem que ser lido na função main. Crie e utilize um
procedimento para a leitura da matriz e uma função para realizar a busca. A impressão
da informação (se x está presente ou não na matriz) deve ser na função main.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 4
void preencher(int matriz[TAM][TAM]);
int buscar(int matriz[TAM][TAM], int X);

int main(){
	int matriz[TAM][TAM], X, verificacao = -1;

	preencher(matriz);
	
	printf("\nValor de X: ");
	scanf("%d", &X);

	verificacao = buscar(matriz, X);

	if(verificacao == -1){
		printf("\nErro");
	}else{
		if(verificacao == 0){
			printf("\nO valor %d nao esta presente!", X);
		}else{
			printf("\nO valor %d esta presente!", X);
		}
	}

	return 0;
}
void preencher(int matriz[TAM][TAM]){
	int i,j;

	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}

int buscar(int matriz[TAM][TAM], int X){
	int i,j;

	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			if(matriz[i][j] == X ){
				return 1;
			}
		}
	}
	
	return 0;
}
