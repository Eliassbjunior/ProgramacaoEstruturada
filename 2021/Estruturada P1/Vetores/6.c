// 6, 12, 14, 18, 19, 21, 25, 28, 29 e 30
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define TAM 10
void preencher(int vet[]);
void imprimir(int vet[]);
int main(){
   	int vet[TAM] = {0,0,0,0,0,0,0,0,0,0};

   	preencher(vet);
   	imprimir(vet);

    return 0;
}
void preencher(int vet[]){
	srand(time(NULL));

	int verificacao = 1, aux = 0;

	for(int i = 0; i < TAM; i++){
		
		aux = rand()% 20+1;
		if(i == 0 ){
			vet[i] = aux;
		}else{
			while(verificacao != 0){

				for(int j = 0; j < i; j++){
					if(vet[j] == aux){
						verificacao = 1;
						aux = rand()% 20+1;
						break;
					}else{
						verificacao = 0;
					}
				}
			}
			vet[i] = aux;
			verificacao = 1;
		}

		
	}
}

void imprimir(int vet[]){

	for(int i = 0; i < TAM; i++){
		printf("%d ", vet[i]);
	}
}