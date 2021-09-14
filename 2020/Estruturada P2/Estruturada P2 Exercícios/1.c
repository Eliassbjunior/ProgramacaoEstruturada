#include <stdio.h>
#include <string.h>
#define tam 20
struct dados{
	int conta;
	char nome[20];
	float saldo;
}funcionarios;

int main(){
	struct dados funcionarios[tam];	
	
	int i,quantidade=0;
	
	printf("Informacoes da conta bancaria!\n");
	for(i = 0; i < tam; i++){
		fflush(stdin);
		printf("Nome do titular: \n");
		scanf("%[^\n]s", funcionarios[i].nome);

		printf("Numero da conta: \n");
		scanf("%d", &funcionarios[i].conta);
		printf("Saldo da conta: \n");
		scanf("%f", &funcionarios[i].saldo);
		system("cls");
		
		if(i != tam-1){
			printf("Informacoes da conta bancaria!\n");
		}
	}
	
	for(i = 0;i < tam; i++){
		if(funcionarios[i].saldo > 1000.0){
			quantidade++;
		}
	}
	if(quantidade == 1) printf("%d cliente!", quantidade);
	if(quantidade > 1) printf("%d clientes!", quantidade);
	if(quantidade == 0) printf("Nenhum cliente!");
	
	return 0;
}
