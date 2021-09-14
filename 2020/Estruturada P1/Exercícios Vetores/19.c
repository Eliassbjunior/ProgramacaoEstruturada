#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define tam 15
void ler_frase(char palavra[]);
int resto(char palavra[]);

int main()
{	
	char palavra[tam];
	int tamanho=0,conferir=0;
	ler_frase(palavra);

	tamanho=strlen(palavra);
	conferir=resto(palavra);	
	
	if(conferir == tamanho){
		printf("A palavra e Polindrome");
	}else{
		printf("A palavra nao e Polindrome");
	}

	return 0;
}
void ler_frase(char palavra[]){
	int i;
	printf("Digite a palavra: \n");
	scanf("%s", palavra);
	
	
}
int resto(char palavra[]){
	int i,t,tamanho,conferir=0;
	
	tolower(palavra);
	tamanho=strlen(palavra);
	t=tamanho;
	for(i=0;i<tamanho;i++){
		t--;
		if(palavra[i] == palavra[t]){
			conferir++;
		}

	}
	return conferir;	
	
}
