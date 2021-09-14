#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define l 30
#define c 20

void ler(char matriz[][c],int tamanho[]);
void verificar(char matriz[][c],int tamanho_lista[],char nome[]);

int main(){
	
	char matriz[l][c],nome[c];
	int tamanho_lista[l];
	
	ler(matriz,tamanho_lista);
	
	printf("Digite um nome para pesquisa: ");
	scanf("%[^\n]s", nome);
	strlwr(nome);
	
	verificar(matriz,tamanho_lista,nome);
	
	return 0;
}
void ler(char matriz[][c],int tamanho_lista[]){
	int i,j,k;
	char auxiliar[c];
	
	printf("Digite o nome:\n");
	
	for(i=0; i<l; i++){
		
		scanf("%[^\n]s", auxiliar);
		strlwr(auxiliar);
		
		fflush(stdin);
		
		tamanho_lista[i]=strlen(auxiliar);
		
		for(k=0;k < tamanho_lista[i] ;k++){
			matriz[i][k]=auxiliar[k];
		}
		
		for(k=0;k < tamanho_lista[i];k++){
			auxiliar[k]=0;
		}
	}
}
void verificar(char matriz[][c],int tamanho_lista[],char nome[]){
	int i,j,tamanho_nome,igualdade=0,conclusao=0;
	
	tamanho_nome=strlen(nome);
	for(i = 0; i < l; i++){
		
		if(tamanho_nome == tamanho_lista[i]){
			
			for(j = 0; j < tamanho_nome;j++){
				
				if(nome[j] == matriz[i][j]){
					igualdade++;
				}
			}
		}
		if(igualdade == tamanho_nome){
			conclusao=1;
		}else{
			igualdade=0;
		}
		
	}
	if(conclusao == 1){
		printf("Nome esta na lista!");
	}else{
		if(conclusao == 0){
			printf("Nome nao esta na lista");
		}
	}
}
