vvv/*Faça um algoritmo para ler duas palavras (com no máximo 10 caracteres cada uma) e imprimir a menor
delas ou se elas têm o mesmo tamanho. Crie e utilize dois procedimentos: um para ler as palavras e outro
para imprimir o que se pede.
Obs.: Considere que o usuário digitará somente letras minúsculas.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define tam 10
void ler_palavras(char palavra_um[],char palavra_dois[]);
void resto(char palavra_um[],char palavra_dois[]);
int main(){
	char palavra_um[tam],palavra_dois[tam];

	ler_palavras(palavra_um,palavra_dois);
	resto(palavra_um,palavra_dois);

}
void ler_palavras(char palavra_um[],char palavra_dois[]){
	int i;

	printf("Digite uma palavra: \n");
	scanf("%[^\n]s", palavra_um);
	
	fflush(stdin);

	printf("Digite outra palavra: \n");
	scanf("%[^\n]s", palavra_dois);


}
void resto(char palavra_um[],char palavra_dois[]){
	
	int um,dois;

	um=strlen(palavra_um);
	dois=strlen(palavra_dois);

	printf("\n");

	if (um > dois)
	{
		printf("%s",palavra_dois);
	}else{
		if (dois > um)
		{
			printf("%s",palavra_um);
		}
		if (um == dois)
			{
				printf("Elas possuem o mesmo tamanho!\n");
			}	
	}
}
