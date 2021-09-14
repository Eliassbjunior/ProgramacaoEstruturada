#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 15
void lerPalavra(char *palavra){
	
	printf("Insira a palavra:\n");
	scanf("%s", palavra);
}

void embaralha(char *palavra){
	
	int i,j, aleatorio;
	srand(time(NULL));
	for(i=0;i < strlen(palavra) && palavra != '\0';i++){
		
		aleatorio = rand() % strlen(palavra) + 0;
		palavra[aleatorio] = palavra[j];	
		aleatorio = 0;
	}
	printf("%s ", palavra);
}

int main (){
	
	printf("####### Embaralha palavra ######\n");
	
	char palavra[TAM];
	lerPalavra(palavra);
	embaralha(palavra);
	
	return 0;
}
