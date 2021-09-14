#include<stdio.h>
#include<string.h>
#define TAM 50
void preencher(char frase[]);
void imprimir(char frase[]);
int main(){
	char frase[TAM];

	preencher(frase);
	imprimir(frase);

	return 0;
}

void preencher(char frase[]){
	printf("Digite uma frase:");
	scanf("%[^\n]s", frase);
}
void imprimir(char frase[]){

	int tamanho = strlen(frase);

	for(int i = 0; i < tamanho; i++){
		if(frase[i] == ' '){

		}else{
			printf("%c", frase[i]);
		}
	}
	
}