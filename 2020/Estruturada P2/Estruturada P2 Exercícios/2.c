#include <stdio.h>
#include <string.h>
#define tam 20

struct dados{
	int conta;
	char nome[tam];
	float saldo;
};

void preencher(struct dados funcionarios[]);
int verificacao(struct dados funcionarios[]);

int main(){
	
	struct dados funcionarios[tam];
	int i;
	
	preencher(funcionarios);
	
	if(verificacao(funcionarios) == 1) printf("%d cliente!", verificacao(funcionarios));
	if(verificacao(funcionarios) > 1) printf("%d clientes!", verificacao(funcionarios));
	if(verificacao(funcionarios) == 0) printf("Nenhum cliente!");
	
	return 0;
}
void preencher(struct dados funcionarios[]){
	int i;
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
}
int verificacao(struct dados funcionarios[]){
	int i,quantidade=0;
	
	for(i = 0;i < tam; i++){
		if(funcionarios[i].saldo <= (880.0*3)){
			quantidade++;
		}
	}
	
	return quantidade;
}
