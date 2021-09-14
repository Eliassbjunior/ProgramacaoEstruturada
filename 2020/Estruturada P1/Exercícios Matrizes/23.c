#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 60
#define C 15

void inserir(char matriz[][C],int posicao_livros[0],int tamanho_livros[]);
void remover(char matriz[][C],int posicao_livros[0],int tamanho_livros[]);
void listar(char matriz[][C],int posicao_livros[0],int tamanho_livros[]);

int main(){
	
	int posicao_livros[0],escolha=0,tamanho_livros[L];
	char matriz[L][C];
	
	posicao_livros[0]=L-1;
	
	do{
		escolha=0;
		
		printf("\n-----------------Arquivo de Livros----------------------\n");
		printf("1 - Adicionar Livro\n");
		printf("2 - Remover Livro\n");
		printf("3 - Listar Livros\n");
		printf("4 - Sair");
		printf("\n--------------------------------------------------------\n");
		scanf("%d", &escolha);
		
		
		while(escolha < 1 && escolha > 4  ){
			system("cls");
			printf("Alternativa nao existente\n");
			printf("Tente novamente\n");
			
			printf("\n-----------------Arquivo de Livros----------------------\n");
			printf("1 - Adicionar Livro\n");
			printf("2 - Remover Livro\n");
			printf("3 - Listar Livros\n");
			printf("4 - Sair");
			printf("\n--------------------------------------------------------\n");
			scanf("%d", &escolha);
		}
		
		switch (escolha){
			case 1: inserir(matriz,posicao_livros,tamanho_livros); break;
			case 2: remover(matriz,posicao_livros,tamanho_livros); break;	
			case 3: listar(matriz,posicao_livros,tamanho_livros); break;
		}
		
	}while(escolha != 4);
	
	printf("\nObrigado por usar nosso software!");
	return 0;
}
void inserir(char matriz[][C],int posicao_livros[0],int tamanho_livros[]){
	int i,j,k;
	
	char livro[C];
	
	printf("Digite o nome do livro: \n");
	fflush(stdin);
	
	scanf("%[^\n]s", livro);
	
	fflush(stdin);
	
	if(posicao_livros[0] < 0){
		printf("Limite atingido!");
	}else{
		for(i = posicao_livros[0] ;i >= 0 ;i--){
			for(k=0;k<C;k++){
				matriz[i][k]=' ';
			}
			tamanho_livros[i]=strlen(livro);
			
			for(j=0; j < tamanho_livros[i]; j++){
				matriz[i][j]=livro[j];
			}
		}
		for(k=0;k<C;k++){
			livro[k]=' ';
		}
		
		system("cls");
		printf("\nLivro adicionado com sucesso!");
		
		posicao_livros[0]--;	
	}
	
		
}
void remover(char matriz[][C],int posicao_livros[0],int tamanho_livros[]){
	int i,j;
	
	posicao_livros[0]++;
	
	if(posicao_livros[0] == L){
		system("cls");
		printf("Nao existe nenhum livro!");
	}else{
		i=posicao_livros[0];
		
		for(j=0; j<C;j++){
			matriz[i][j]=' ';	
		}
		
		system("cls");
	    printf("\nLivro removido com sucesso!");
	}
		
}
void listar(char matriz[][C],int posicao_livros[0],int tamanho_livros[]){
	int i,j,k;
	
	system("cls");
	
	if(posicao_livros[0] == L-1){
		system("cls");
		printf("Nao existe nenhum livro!\n");
	}else{
		
		printf("\n-----------------Arquivo de Livros----------------------\n");
		
		for(i=posicao_livros[0]+1;i<L;i++){
			for(j=0; j < tamanho_livros[i] ;j++){
				printf("%c", matriz[i][j]);
			}
			
			printf("\n");
		}
		printf("\n--------------------------------------------------------\n");
			
	}
	system("pause");
	system("cls");
}

