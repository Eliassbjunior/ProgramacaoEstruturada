#include<stdio.h>
#include<stdlib.h>
#define tam 10

void preencher(struct dados funcionarios[]);
void ordenar(struct dados funcionarios[]);
void imprimir(struct dados funcionarios[]);

struct dados{
	char p_nome[tam];
	int idade;
	float salario;
	char cargo[tam];
};
int main(){
	struct dados funcionarios[tam];

	preencher(funcionarios);
	ordenar(funcionarios);
	imprimir(funcionarios);

	return 0;
}

void preencher(struct dados funcionarios[]){
	for(int i = 0; i < tam; i++){
		printf("Digite o primeiro nome: \n");
		scanf(" %[\n]s", funcionarios[i].p_nome);

		printf("Digite a idade: \n");
		scanf("%d", funcionarios[i].idade);

		printf("Digite o salario: \n");
		scanf("%f", funcionarios[i].salario);

		printf("Digite o cargo: \n");
		scanf(" %[\n]s", funcionarios[i].cargo);
		
	}
}

void ordenar(struct dados funcionarios[]){
	int i,j,aux,min;
	
	for(i = 0; i < tam-1;i++){
		min=i;
		for(j = i+1 ;j < tam;j++){
			if(funcionarios[j].idade < funcionarios[min].idade){
				min=j;
			}
		}
		aux = funcionarios[i].idade;
		funcionarios[i].idade = funcionarios[min].idade;
		funcionarios[min].idade = aux;
	}
	
}
void imprimir(struct dados funcionarios[]){
	for(int i = 0; i < tam; i++){
		printf("\nNome: %s\nIdade: %d\nSalario: %.3f\nCargo: %s\n", funcionarios[i].p_nome,funcionarios[i].idade,funcionarios[i].salario,funcionarios[i].cargo);
		printf("-------------------------------------------------\n")
	}
}