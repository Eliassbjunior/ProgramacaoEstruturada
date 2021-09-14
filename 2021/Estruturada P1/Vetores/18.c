#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 20
void ler_frase(char frase_um[], char frase_dois[]);
void resto(char frase_um[], char frase_dois[]);

int main(){
	
	char frase_um[tam],frase_dois[tam];

	ler_frase(frase_um,frase_dois);
	resto(frase_um,frase_dois);

	return 0;
}
void ler_frase(char frase_um[], char frase_dois[]){
	
	printf("Digite frase 1: \n");
	scanf("%[^\n]s", frase_um);

	fflush(stdin);

	printf("Digite frase 2: ");
	scanf("%[^\n]s", frase_dois);
}
void resto(char frase_um[], char frase_dois[]){
	int resultado,um,dois;
	

	um=strlen(frase_um);
	dois=strlen(frase_dois);
	resultado=strcmp(frase_um,frase_dois);

	if(um == dois){
		printf("Tamanho iguais");
	}else{
		printf("Tamanho diferentes");
	}

	if(resultado == 0){
		printf("\nFrases iguais");
	}else{
		printf("Frases diferentes");
	}
}


