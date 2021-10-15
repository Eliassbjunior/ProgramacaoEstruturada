#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define TAM 50 
#define TAMA 10
void preencher(char frase[], char palavra[]);
void verificador(char frase[], char palavra[]);

int main(){
	char frase[TAM], palavra[TAMA];

	preencher(frase, palavra);
	verificador(frase, palavra);


	return 0;
}
void preencher(char frase[], char palavra[]){

	printf("Digite a frase: ");
	scanf(" %[^\n]s", frase);

	printf("Digite uma palavra: ");
	scanf(" %[^\n]s", palavra);

	
}
void verificador(char frase[], char palavra[]){

	int auxiliar = 0, auxiliar2 = 0, aux = 0, validacao = 0, quantidade = 0;
	char p[] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

	auxiliar = strlen(palavra);
	auxiliar2 = strlen(frase);
	
	strlwr(frase);
	strlwr(palavra);
	
	for (int i = 0; i < auxiliar2; ++i)
	{
		if(frase[i] == palavra[0]){
			aux = i-1;
			for(int j = 0; j < auxiliar; j++){
				aux++;
				p[j] = frase[aux];
			}

			validacao = strcmp(p,palavra);

			if(validacao == 0){
				quantidade++;
			}
		} ´@
	}
	printf("A palavra aparece %d vezes na frase!", quantidade);
}