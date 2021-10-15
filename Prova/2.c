#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define TAM 30
void preencher(int vet[]);
void imprimir(int vet[]);

int main(){
	int vet[TAM];

	preencher(vet);
	imprimir(vet);

	return 0;
}
void preencher(int vet[]){

	srand(time(NULL));
	for(int i = 0; i < TAM; i++){
		vet[i] = rand()%500+1;
	}
}
void imprimir(int vet[]){
	int quantidade = 1, numero = 0;
	FILE *arqResult = fopen("Resultado.txt", "w");

	for(int i = 0; i < TAM; i++){
		if(vet[i] == 0){

		}else{
			numero = vet[i];
			for(int j = i+1; j < TAM; j++){
				if(vet[j] == numero){
					quantidade++;
					vet[j] = 0;
				}
			}
			fprintf(arqResult,"Quantidade do número %d: %d \n", numero, quantidade);
			quantidade = 1;
		}
	}
	fclose(arqResult);
}