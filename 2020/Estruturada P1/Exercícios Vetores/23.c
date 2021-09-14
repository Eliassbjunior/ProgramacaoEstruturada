#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define tam 10
void ler (char palavra_um[], char palavra_dois[]);
void imprimir(char palavra_um[], char palavra_dois[]);

int main(){

	char palavra_um[tam],palavra_dois[tam];

	ler(palavra_um,palavra_dois);
	imprimir(palavra_um,palavra_dois);

	return 0;
}
void ler (char palavra_um[], char palavra_dois[]){
	
	printf(" Digite a primeira palavra: ");
	scanf("%[^\n]s", palavra_um);
	fflush(stdin);

	printf(" Digite a segunda palavra: ");
	scanf("%[^\n]s", palavra_dois);

}
void imprimir(char palavra_um[], char palavra_dois[]){
	int resultado;

	resultado=strcmp(palavra_um,palavra_dois);

	printf("\n");
	if(resultado < 0){
		printf("%s\n", palavra_um);
	}
	if(resultado > 0){
		printf("%s\n", palavra_dois);
	}
}
