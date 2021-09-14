#include <stdio.h>
#include <stdlib.h>
#define SIZE 200
#include <string.h>
#include <conio.h>
#include <locale.h>
 
typedef struct cadastro
{
    char nome[50];
    char telefone[50];
    char endereco[50];
    char bairro[50];
    char numero[50];
};
struct cadastro cad[50];
struct cadastro teste;
 
FILE *arq;
 
int op;
char atendente;
int senha;
void cadastro();
void pesquisa();
void lista();
void cadastroPedido();
void estoques();
 
char *replaceWord(const char *s, const char *oldW, const char *newW)
{
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
 
    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;
 
            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }
 
    // Making new string of enough length
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);
 
    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }
 
    result[i] = '\0';
    return result;
}
 
 
int main(void) {
    system("cls");
    char nome5[50];
 
    setlocale(LC_ALL, "Portuguese");
 
    printf("------- LOGIN -------\n");
    printf("Nome do atendente: \n");
    scanf("%[^\n]s", nome5);
 
    while (1 == 1){
        fflush(stdin);
        printf("Senha da Pizzaria: \n");
        scanf("%d", &senha);
        if (senha == 123456) {
            logado(nome5);
            break;
        } else {
            printf("Senha incorreta, digite novamente!\n");
        }
    }
}
 
void logado(char nome5[50]){
   
        while(op != 7){
           
        system("color F5");
        system("cls");
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("                                            PIZZARIA DOS MONSTROS   \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("                                         SEJA BEM VINDO ATENDENTE %s\n", nome5);
        printf("________________________________________________________________________________________________________________________\n\n");
 
        printf("[1] - Cadastrar\n[2] - Listar todos \n[3] - Pesquisar\n[4] - Pedido\n[5] - Estoque\n[6] - Cadastro Produto\n[7] - Sair\n");
        printf("________________________________________________________________________________________________________________________\n\n\n");
        printf("Qual opção voce deseja acessar? ");
 
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                cadastro();
                break;
            case 2:
                lista();
                break;
            case 3:
                pesquisa();
                break;
            case 4:
                cadastroPedido();
                break;
            case 5:
                estoques();
                break;
            case 6:
                break;
            case 7:
                system("exit");
                break;
            default:
                printf("opcao invalida");
                break;
        }
           
        }
   
}
 
void lista()
{
    int i;
    struct cadastro cad;
    FILE *arq;
 
    arq = fopen("cadastro.txt", "r");
   
    system("cls");
    printf("\n\n\t\t\t\t TODOS OS CADASTROS DOS CLIENTES\n");
    printf("\t\t\t\t----------------------------------\n\n");
    system("type cadastro.txt");
    getchar();
    getchar();
   
    fprintf(arq, "\naaaaaNome: %saaaa\n", fscanf(arq, "%s", "Nome: "));
}
 
void cadastro()
{
    int i;
    struct cadastro cad[50];
    static int linha;
    FILE *arq;
 
    arq = fopen("cadastro.txt", "ab");
    system("cls");
    printf("\n\n\t\t\t\t\t CADASTRO DO CLIENTE\n");
    printf("\t\t\t\t\t-------------------------\n\n");
    printf("\nDigite o nome do cliente ------------- : ");
    fflush(stdin);
    scanf("%s", &cad[i].nome);
    fscanf(arq, "%s", &cad[i].nome);
 
    printf("\nDigite o telefone do cliente---------- : ");
    fflush(stdin);
    scanf("%s", &cad[i].telefone);
    fscanf(arq, "%s", &cad[i].telefone);
 
    printf("\nDigite o endereco do cliente---------- : ");
    fflush(stdin);
    scanf("%s", &cad[i].endereco);
    fscanf(arq, "%s", &cad[i].endereco);
 
    printf("\nDigite o bairro do cliente------------- : ");
    fflush(stdin);
    scanf("%s", &cad[i].bairro);
    fscanf(arq, "%s", &cad[i].bairro);
 
    printf("\nDigite o numero da casa do cliente---- : ");
    fflush(stdin);
    scanf("%s", &cad[i].numero);
    fscanf(arq, "%s", &cad[i].numero);
 
    for (i = 0; i < 1; i++)
    {
        fprintf(arq, "%s %s %s %s %s\n", cad[i].nome, cad[i].telefone, cad[i].endereco, cad[i].bairro, cad[i].numero);
        printf("gravado com sucesso");
    }
    fclose(arq);
}
 
void cadastroPedido()
{
    char telefonePesquisa[50];
    int i;
    int OpcaoPedido;
    struct cadastro cad[50];
    char teste[50];
 
    arq = fopen("cadastro.txt", "rb");
 
    if (arq == NULL)
    {
        printf("Nao foi possivel abrir o aquivo ");
        exit(0);
        return;
    }
 
    printf("Digite o telefone \n");
    scanf("%s", &telefonePesquisa);
   
    for (i = 0; i < 200; i++){
        if (cad[i].telefone == telefonePesquisa){
            printf("encontrado");
 
            fscanf(arq, "\nNome: %s\nTelefone: %s\nEndereco: %s\nBairro: %s\nNumero: %s", cad[i].nome, cad[i].telefone, cad[i].endereco, cad[i].bairro, cad[i].numero);
            printf("\nNome: %s\nTelefone: %s\nEndereco: %s\nBairro: %s\nNumero: %s", cad[i].nome, cad[i].telefone, cad[i].endereco, cad[i].bairro, cad[i].numero);
        }
    }
    fclose(arq);
}
 
 
void pesquisa(){
   
    char leitura[50];
    char telefone[50];
    char nome[50];
    char option[50];
   int i;
   char num[50];
   
   fflush(stdin);
    printf("\nDigite o telefone: ");
    scanf("%s", num);
   
   
    FILE *file;
    file = fopen("cadastro.txt", "r");
   
    if(file == NULL){
        printf("Não foi possível abrir o arquivo.\n");
        getchar();
        exit(0);
    }
   
    char frase[100];
    char resultado[256];
    char *result = NULL;
    int ret;
   
    int length;
    int length1;
    
	   
    char endereco[50];
    char bairro[50];
    char casa[50];
    
    for(i = 0; i < 50; i++){
    	fscanf(file,"%s %s %s %s %s",nome,telefone,endereco,bairro,casa);
    	
    	if( 0 == strcmp(telefone,num)){
    	    printf("\nNome: %s\nTelefone: %s\nEndereco: %s\nBairro: %s\nNumero: %s", nome,telefone,endereco,bairro,casa);
    	    break;
		}
	}
    
    
    /*while(fgets(frase, 512, file) != NULL){
        result = replaceWord(frase, "Nome: ", "");
 
        if(strcmp(nome, result) == 0){
            printf("Encontrado");
            break;
        } else {
            printf("Tamanho nome: %s%", strlen(nome));
            printf("Tamanho result: %s%", strlen(result));
            //printf("Procurando: %s%", nome);
            //printf("\n");
            //printf("Encontrado: %s%", result);
            //printf("Não Encontrado\n\n");
        }
       
        //while(strcmp(resultado, nome)){
        //  printf("%s", frase);
        //  break;
        //}
    }
   */
   
    fclose(file);
   
    printf("\nDigite 1 para continuar ou outro valor para sair : ");
    scanf("%d", &option);
    printf("\n");
   
}
 
struct Ingredient {
    int id;
    char name[50];
    int amount;
};
 
struct Pizza {
    char name[50];
    int ingredients[50];
    float price;
};
 
struct Ingredient ingredients[200];
struct Pizza pizzas[200];
 
FILE* arq;
void loadArchive(){
    arq = fopen("ingredientes.txt", "w");
   
    if (arq == NULL){
        printf("Failed to found the archive \"ingredientes.txt\"");
        fclose(arq);
        system("pause");
    } else {
        printf("Loaded successful!");
    }
}
 
void loadIngredients(){
    ingredients[0].id = 0;
    strcpy(ingredients[0].name, "Farinha de trigo");
    ingredients[0].amount = 0;
   
    ingredients[1].id = 1;
    strcpy(ingredients[1].name, "Sal");
    ingredients[1].amount = 0;
   
    ingredients[2].id = 2;
    strcpy(ingredients[2].name, "Fermento");
    ingredients[2].amount = 0;
   
    ingredients[3].id = 3;
    strcpy(ingredients[3].name, "Azeite");
    ingredients[3].amount = 0;
   
    ingredients[4].id = 1;
    strcpy(ingredients[4].name, "Molho de tomate");
    ingredients[4].amount = 0;
   
    ingredients[5].id = 1;
    strcpy(ingredients[5].name, "Queijo mussarela");
    ingredients[5].amount = 0;
   
    ingredients[6].id = 1;
    strcpy(ingredients[6].name, "Orégano");
    ingredients[6].amount = 0;
   
    ingredients[7].id = 1;
    strcpy(ingredients[7].name, "Azeitona");
    ingredients[7].amount = 0;
   
    ingredients[8].id = 1;
    strcpy(ingredients[8].name, "Ovo");
    ingredients[8].amount = 0;
   
    ingredients[9].id = 1;
    strcpy(ingredients[9].name, "Linguiça calabresa");
    ingredients[9].amount = 0;
   
    ingredients[10].id = 1;
    strcpy(ingredients[10].name, "Cebola");
    ingredients[10].amount = 0;
   
    int i;
    int sizechar = sizeof(char);
   
    for(i = 1; i <= 200; i++){
        if(sizeof(ingredients[i].name) / sizechar > 0){
            fprintf(arq, "\nIng%d: %s | Quantidade: %d%", i, ingredients[i].name, ingredients[i].amount);
        } else {
            break;
        }
    }
   
}
 
void loadPizzas(){
    strcpy(pizzas[0].name, "Mussarela");
    pizzas[0].ingredients[0] = 0;
    pizzas[0].price = 12.0;
   
    strcpy(pizzas[1].name, "Calabresa");
    pizzas[1].ingredients[0] = 0;
    pizzas[1].price = 12.0;
}
 
void estoques(){
 
    char option[50];
 
    loadArchive();
    loadIngredients();
    loadPizzas();
   
    char frase[100];
    char resultado[256];
    char *result = NULL;
   
    while(fgets(frase, 512, arq) != NULL){
        result = replaceWord(frase, "Nome: ", "");
    }
   
    printf("\n\nIng1: %s | Quantidade: %d% ", ingredients[0].name, ingredients[0].amount);
    printf("\nIng2: %s | Quantidade: %d% ", ingredients[1].name, ingredients[1].amount);
    printf("\nIng3: %s | Quantidade: %d% ", ingredients[2].name, ingredients[2].amount);
    printf("\nIng4: %s | Quantidade: %d% ", ingredients[3].name, ingredients[3].amount);
    printf("\nIng5: %s | Quantidade: %d% ", ingredients[4].name, ingredients[4].amount);
    printf("\nIng6: %s | Quantidade: %d% ", ingredients[5].name, ingredients[5].amount);
    printf("\nIng7: %s | Quantidade: %d% ", ingredients[6].name, ingredients[6].amount);
    printf("\nIng8: %s | Quantidade: %d% ", ingredients[7].name, ingredients[7].amount);
    printf("\nIng9: %s | Quantidade: %d% ", ingredients[8].name, ingredients[8].amount);
    printf("\nIng10: %s | Quantidade: %d% ", ingredients[9].name, ingredients[9].amount);
    printf("\nIng11: %s | Quantidade: %d% ", ingredients[10].name, ingredients[10].amount);
   
    printf("\n\n");
   
    printf("Pizza1: %s \n", pizzas[0].name);
    printf("Pizza2: %s \n", pizzas[1].name);
   
    printf("\nDigite 1 para continuar ou outro valor para sair : ");
    scanf("%d", &option);
    printf("\n");
       
}
