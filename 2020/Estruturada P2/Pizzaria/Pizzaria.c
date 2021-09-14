#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 50
struct dados{
	int quantidade[TAM];
	char produto[TAM][TAM]; //Produto e uma matriz porque essa recebe o nome e precisa se bidimensional, um vetor nao daria certo.
	int quantidade_de_produtos_registrados;
	int id[TAM];
};
struct dados estoque;

void estoquee(int id, struct dados estoque);
int cadastros();
void listar_todos();
int pesquisa();
void pedido(struct dados estoque);
int confirmacao();
void cadastro_produto(struct dados estoque);
int produtos_registrados();



int main(){
	
	setlocale(LC_ALL, "Portuguese");
	system("cls");
    char nome5[50];
    int senha=0;
 
 
    printf("------- LOGIN -------\n");
    printf("Nome do atendente: \n");
    scanf("%[^\n]s", nome5);
 
    while (1 == 1){
        fflush(stdin);
        printf("Senha da Pizzaria: \n");
        scanf("%d", &senha);
        if (senha == 123456) {
            break;
        } else {
            printf("Senha incorreta, digite novamente!\n");
        }
    }
    system("cls");
    system("color F5");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                            PIZZARIA DOS MONSTROS   \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("                                         SEJA BEM VINDO ATENDENTE %s\n", nome5);
    printf("________________________________________________________________________________________________________________________\n\n");
	
	
	int opcao=0, retorno;
	estoque.quantidade_de_produtos_registrados = 0;
	
	while(opcao!= 7){
		
		while(opcao!=0 || opcao !=7){
				
		
			printf("\n[1] - Cadastrar cliente\n[2] - Listar todos clientes \n[3] - Pesquisar cliente\n[4] - Pedido\n[5] - Estoque\n[6] - Cadastrar Produto\n[7] - Sair\n");	
			printf("Qual opção voce deseja acessar? ");
			scanf("%d", &opcao);
		
			switch(opcao){
				case 1:
					//A funcao cadastro retorna se o castrado foi feito ou nao.
					retorno = cadastros(); 
					if(retorno == 1){
						printf("Cliente Cadastrado!");
					}else{
						printf("\nFalha no cadastro!");
					}
					
				break;
				case 2:
					listar_todos();
					
				break;
				case 3:
					retorno = pesquisa();
					if(0 == retorno){
						printf("Usuário não encontrado");
					}
				
				break;	
				
				case 4:
					pedido(estoque);
					
				break;
				
				case 5:
					estoquee(0 , estoque);
					
				break;	
				
				case 6:
					cadastro_produto(estoque);
				break;
				case 0:
					getchar();
				break;
			}
			getchar();
			getchar();
			system("cls");
		}
	
		return 0;
	}
}
int cadastros(){
	
	char nome[TAM];
	char telefone[TAM];
	char endereco[TAM];
	char bairro[TAM];
	int n_casa;	
	int auxiliar,i;
	
	FILE *arqEntrada = fopen("Cadastrados.txt", "a");
	
	if (arqEntrada == NULL)
    {
        return 0;
    }
    
	fflush(stdin);
	
	printf("\nDigite seu nome: ");
	scanf("%[^\n]s", nome);
	
	fflush(stdin);
	
	printf("\nDigite o telefone do cliente: ");
    scanf("%s", telefone);
 
 	fflush(stdin);
 	
    printf("\nDigite o endereco do cliente: ");
    scanf("%[^\n]s", endereco);
  
    fflush(stdin);
    
    printf("\nDigite o bairro do cliente: ");
    scanf("%[^\n]s", bairro);
 
    printf("\nDigite o numero da casa do cliente: ");
    scanf("%d", &n_casa);
	
	auxiliar=strlen(nome);
	//Aqui e retirado os espaços das strings para colocar no arquivo.
	for(i = 0; i < auxiliar;i++){
		if(nome[i] == ' '){
			nome[i]='_';
		}
	}
	auxiliar=strlen(endereco);
	
	for(i = 0; i < auxiliar;i++){
		if(endereco[i] == ' '){
			endereco[i]='_';
		}
	}   
	
	auxiliar = strlen(bairro);
	
	for(i = 0; i < auxiliar;i++){
		if(bairro[i] == ' '){
			bairro[i]='_';
		}
	}
	auxiliar=0;
	
	fprintf(arqEntrada, "%s %s %s %s %d\n", nome, telefone, endereco, bairro, n_casa);
	fclose(arqEntrada);
	
	return 1;
}
void listar_todos(){
	
	FILE *arqEntrada = fopen("Cadastrados.txt", "r");
	
	if (arqEntrada == NULL)
    {
        printf("Erro na abertura do arquivo!");
        exit(0);
    }

	int i,j;
	
	
	char c, letra = '\n';
	char nome_listar[TAM];
	char telefone_listar[TAM];
	char endereco_listar[TAM];
	char bairro_listar[TAM];
	int n_casa_listar;
	int auxiliar;
	
	fscanf(arqEntrada, "%s %s %s %s %d", nome_listar, telefone_listar, endereco_listar, bairro_listar, &n_casa_listar);
	//Aqui e retirado o underline e colocado o espaco de novo
	while(fread (&c, sizeof(char), 1, arqEntrada)) {
		auxiliar=strlen(nome_listar);
	
		for(i = 0; i < auxiliar;i++){
			if(nome_listar[i] == '_'){
				nome_listar[i]=' ';
			}
		}
		auxiliar=strlen(endereco_listar);
		
		for(i = 0; i < auxiliar; i++){
			if(endereco_listar[i] == '_'){
				endereco_listar[i]=' ';
			}
		}   
		
		auxiliar = strlen(bairro_listar);
		
		for(i = 0; i < auxiliar;i++){
			if(bairro_listar[i] == '_'){
				bairro_listar[i]=' ';
			}
		}
		printf("\nNome: %s\nTelefone: %s \nEndereco: %s\nBairro: %s\nNumero da casa: %d\n", nome_listar, telefone_listar, endereco_listar, bairro_listar, n_casa_listar);
		printf("------------------------------------------------------------------------------------\n");
		
		for(j = 0; j < TAM; j++){
			nome_listar[j]=' ';
			telefone_listar[j]=' '; 
			endereco_listar[j]=' ';
			bairro_listar[j]=' '; 
			n_casa_listar=0;		
		}
		
		fscanf(arqEntrada, "%s %s %s %s %d", nome_listar, telefone_listar, endereco_listar, bairro_listar, &n_casa_listar);
		
    }
		
	
	fclose(arqEntrada);
}
int pesquisa(){
	int i;

	char c, letra = '\n';
	char pesquisaa[TAM];
	char nome_listar[TAM];
	char telefone_listar[TAM];
	char endereco_listar[TAM];
	char bairro_listar[TAM];
	int n_casa_listar;
	int auxiliar=0;
	
	fflush(stdin);
	printf("\nDigite o telefone: ");
    scanf("%s", pesquisaa);
    
    FILE *arqEntrada = fopen("Cadastrados.txt", "r");
    if (arqEntrada == NULL)
    {
        printf("Erro na abertura do arquivo!");
        exit(0);
    }
    
	while(fread (&c, sizeof(char), 1, arqEntrada)) {
 		
 		fscanf(arqEntrada,"%s %s %s %s %d",nome_listar, telefone_listar, endereco_listar, bairro_listar, &n_casa_listar);
 		
		auxiliar=strlen(nome_listar);
	
		for(i = 0; i < auxiliar;i++){
			if(nome_listar[i] == '_'){
				nome_listar[i]=' ';
			}
		}
		auxiliar=strlen(endereco_listar);
		
		for(i = 0; i < auxiliar;i++){
			if(endereco_listar[i] == '_'){
				endereco_listar[i]=' ';
			}
		}   
		
		auxiliar = strlen(bairro_listar);
		
		for(i = 0; i < auxiliar;i++){
			if(bairro_listar[i] == '_'){
				bairro_listar[i]=' ';
			}
		}
		
		if(0 == strcmp(telefone_listar,pesquisaa)){
			auxiliar=strlen(nome_listar);
			printf("\nNome: ");
			for(i = 0; i < auxiliar; i++){
				printf("%c",nome_listar[i]);
			}
			printf("\nTelefone: %s \nEndereco: %s\nBairro: %s\nNumero da casa: %d\n", telefone_listar, endereco_listar, bairro_listar, n_casa_listar);
    	    auxiliar=1;
			break;
		}
		
		
	}
	fclose(arqEntrada);
	return auxiliar;
}
void pedido(struct dados estoque){
	int id,auxiliar=0;
	
	auxiliar = confirmacao();
	//A funcao confirmacao so permite o cliente fazer o pedido se estiver cadastrado.
	
	if(auxiliar == 1){
		printf("Aprovado!");
		printf("\n-----------------");
		printf("\n1- Mussarela");
		printf("\n2- Calabreza");
		printf("\n-----------------");
		printf("\nFaca o pedido: ");
		scanf("%d", &id);
		if(id == 1){
			printf("\nPagar: R$25.00\n");
		}else{
			if(id == 2){
				printf("\nPagar: R$28.00\n");
			}
		}
		//Aqui depois que sabemos o tipo de pizza que o cliente quer vamos para a funcao estoque fazer o desconto do produto usado para fazer a pizza.
		estoquee(id,estoque);	
	}else{
		printf("Faca o cadastro\n Usuario nao cadastrado.\n");
	}
}
int confirmacao(){
	int i;

	//Dentro dessa funcao e verificado se o cliente tem cadastro
	
	char c, letra = '\n';
	char pesquisaa[TAM];
	char nome_listar[TAM];
	char telefone_listar[TAM];
	char endereco_listar[TAM];
	char bairro_listar[TAM];
	int n_casa_listar;
	int auxiliar=0;
	
	fflush(stdin);
	printf("\nDigite o telefone: ");
    scanf("%s", pesquisaa);
    
    FILE *arqEntrada = fopen("Cadastrados.txt", "r");
    if (arqEntrada == NULL)
    {
        printf("Erro na abertura do arquivo!");
        exit(0);
    }
	
	while(fread (&c, sizeof(char), 1, arqEntrada)) {
 		
 		fscanf(arqEntrada,"%s %s %s %s %d",nome_listar, telefone_listar, endereco_listar, bairro_listar, &n_casa_listar);
 		
		auxiliar=strlen(nome_listar);
	
		for(i = 0; i < auxiliar;i++){
			if(nome_listar[i] =='_'){
				nome_listar[i]=' ';
			}
		}
		auxiliar=strlen(endereco_listar);
		
		for(i = 0; i < auxiliar;i++){
			if(endereco_listar[i] == '_'){
				endereco_listar[i]=' ';
			}
		}   
		
		auxiliar = strlen(bairro_listar);
		
		for(i = 0; i < auxiliar;i++){
			if(bairro_listar[i] == '_'){
				bairro_listar[i]=' ';
			}
		}
		
		if(0 == strcmp(telefone_listar,pesquisaa)){
			printf("------------------------------------------------------------------------------------\n");
			printf("\nNome: %s\nTelefone: %s \nEndereco: %s\nBairro: %s\nNumero da casa: %d\n", nome_listar, telefone_listar, endereco_listar, bairro_listar, n_casa_listar);
			printf("------------------------------------------------------------------------------------\n");
			
			return 1;
		}
	}
	fclose(arqEntrada);
	return 0;
}
void estoquee(int id, struct dados estoque){
	
    estoque.quantidade_de_produtos_registrados = produtos_registrados();
	
	//Aqui e a funcao de estoque
	//Aqui e verificado qual o id do produto para fazer os descontos na quantidade e caso o ID seja 0 ele so vai mostrar o estoque sem desconto nenhum.
	
	int i,j,k,auxiliar;
	char produtoo[TAM];
	int tamanho[TAM];
	
	
	if(id == 1){
		FILE *arqEntrada = fopen("Estoque.txt", "r");
		for(i = 0; i < estoque.quantidade_de_produtos_registrados;i++){
			
			fflush(stdin);
			fscanf(arqEntrada,"%s", produtoo);
	
			auxiliar=strlen(produtoo);
			for(j = 0; j < auxiliar;j++){
				if(produtoo[j] == '_'){
					produtoo[j]=' ';
				}
			}
			
			for(j = 0; j < auxiliar; j++){
				estoque.produto[i][j] = produtoo[j];
			}
			tamanho[i]=auxiliar;
			fscanf(arqEntrada,"%d %d", &estoque.quantidade[i], &estoque.id[i]);

	
		}
		for(i = 0; i < estoque.quantidade_de_produtos_registrados;i++){
			if(estoque.id[i] == 1 || estoque.id[i] == 3){
				if(estoque.quantidade > 0){
					estoque.quantidade[i]--;	
				}
			}
			
		}
		fclose(arqEntrada);
	}else{
		if(id == 2){
			FILE *arqEntrada = fopen("Estoque.txt", "r");
			for(i = 0; i < estoque.quantidade_de_produtos_registrados;i++){
				
				fflush(stdin);
				fscanf(arqEntrada,"%s", produtoo);
				auxiliar=strlen(produtoo);
				
				for(j = 0; j < auxiliar;j++){
					if(produtoo[j] == '_'){
						produtoo[j]=' ';
					}
				}
				
				for(j = 0; j < auxiliar; j++){
					estoque.produto[i][j] = produtoo[j];
				}
				tamanho[i]=auxiliar;
				fscanf(arqEntrada,"%d %d",&estoque.quantidade[i], &estoque.id[i]);
			}
			for(i = 0; i < estoque.quantidade_de_produtos_registrados;i++){
				if(estoque.id[i] == 2 || estoque.id[i] == 3){
					if(estoque.quantidade > 0){
						estoque.quantidade[i]--;	
					}
					
				}
				
			}
			fclose(arqEntrada);
		}else{
			if(id == 0){
				estoque.quantidade_de_produtos_registrados = produtos_registrados();
				FILE *arqEntrada = fopen("Estoque.txt", "r");
				for(i = 0; i < estoque.quantidade_de_produtos_registrados;i++){
					fflush(stdin);
					
					fscanf(arqEntrada,"%s %d %d", produtoo, &estoque.quantidade[i], &estoque.id[i]);
					auxiliar=strlen(produtoo);
				
					for(j = 0; j < auxiliar;j++){
						if(produtoo[j] == '_'){
							produtoo[j]=' ';
						}
					}
					printf("\n--------------------------\n");
					printf("Produto:%s \nQuantidade:%d", produtoo , estoque.quantidade[i]);
					printf("\n--------------------------");
				}
				fclose(arqEntrada);	
			}
		}
	}

	if(id != 0){
		
		estoque.quantidade_de_produtos_registrados = produtos_registrados();
		FILE *arqEntradaa = fopen("Estoque.txt", "w");
		
		for(i = 0; i < estoque.quantidade_de_produtos_registrados;i++){
		
			for(j = 0; j < tamanho[i]; j++){
				if(estoque.produto[i][j] == ' '){
					estoque.produto[i][j]='_';
				}
				fprintf(arqEntradaa,"%c", estoque.produto[i][j]);
			}
			
			fprintf(arqEntradaa," ", estoque.produto[i][tamanho[i]]);
			
			fprintf(arqEntradaa,"%d %d\n",estoque.quantidade[i],estoque.id[i]);		
		}
		
		fclose(arqEntradaa);
	}
}

void cadastro_produto(struct dados estoque){
	//Aqui está sendo feito o cadastro de novos produtos no arquivo.
	int i = produtos_registrados();
	
	FILE *arqEntrada = fopen("Estoque.txt", "a");
	
	
	int auxiliar,j,k;
	char produto[TAM];
	
	
	fflush(stdin);
	printf("\nNome do produto que deseja adicionar ao estoque: ");
	scanf("%[^\n]s", produto);
	
	auxiliar = strlen(produto);
	
	for(k = 0; k < auxiliar;k++){
		if(produto[k] == ' '){
			produto[k]='_';
		}
	}
	for(j = 0; j < auxiliar; j++){
		estoque.produto[i][j] = produto[j];
	}
	fflush(stdin);
	
	printf("\nQuantidade adicionada: ");
	scanf("%d", &estoque.quantidade[i]);
	
	printf("\nID 1 - Pizza de Mussarela");
	printf("\nID 2 - Pizza de Calabreza");
	printf("\nID 3 - Corresponde as todas pizzas.");
	printf("\nA qual ID de pizza esse ingrediente corresponde? ");
	scanf("%d", &estoque.id[i]);
	
	for(j = 0; j < auxiliar; j++){
		fprintf(arqEntrada,"%c", estoque.produto[i][j]);
	}
	fprintf(arqEntrada," ", estoque.produto[i][j]);
	
	fprintf(arqEntrada,"%d %d\n",estoque.quantidade[i], estoque.id[i]);
	estoque.quantidade_de_produtos_registrados++;
	
	fclose(arqEntrada);
}

int produtos_registrados(){
	FILE *arqEntrada = fopen("Estoque.txt", "r");
	//Essa funcao e so para saber quantos produtos tem no estoque
	char c, letra = '\n';
	int cont=0;
	
	while(fread (&c, sizeof(char), 1, arqEntrada)) {
		if(c == letra){
			cont++;
		}
	}
	fclose(arqEntrada);
	return cont;
}
