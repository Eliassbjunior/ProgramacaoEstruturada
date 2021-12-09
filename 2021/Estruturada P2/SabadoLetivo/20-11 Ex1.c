#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define tam 10
#define TAM 100

void preencher(struct dados funcionarios[]);
void padraoNome(char nome[]);
void ordenar(struct dados funcionarios[]);
int buscabinaria(struct dados funcionarios[])

struct dados{
	char p_nome[tam];
	int idade;
	float salario;
	char cargo[tam];
};
int main(){
	struct dados funcionarios[TAM];
	int aux = 0;

	preencher(funcionarios);
	ordenar(funcionarios);
	aux = buscabinaria(funcionarios);

	if(aux != -1){
		printf("Nome existente");
	}else{
		printf("Nome inexistente");
	}

	return 0;
}

void preencher(struct dados funcionarios[]){
	char aux;
	for(int i = 0; i < TAM; i++){
		printf("Digite o primeiro nome: \n");
		scanf(" %[\n]s", funcionarios[i].p_nome);

		printf("Digite a idade: \n");
		scanf("%d", funcionarios[i].idade);

		printf("Digite o salario: \n");
		scanf("%f", funcionarios[i].salario);

		printf("Digite o cargo: \n");
		scanf(" %[\n]s", funcionarios[i].cargo);
		
		padraoNome(funcionarios[i].p_nome);
	}
}
void padraoNome(char nome[]){
	char aux[tam]

	cpy(aux,nome);
	strlwr(aux);
	toupper(aux[0]);
	cpy(nome,aux);

}

void ordenar(struct dados funcionarios[]){
	int i,j,min;
	char aux[tam];
	
	for(i = 0; i < TAM-1;i++){
		min=i;
		for(j = i+1 ;j < TAM;j++){
			if(strcmp(funcionarios[j].nome,funcionarios[min].nome) > 0){
				min=j;
				strcpy(aux,funcionarios[i].nome);
				strcpy(funcionarios[i].nome,funcionarios[min].nome);
				strcpy(funcionarios[min].nome,aux);
			}
		}
	}
}

int buscabinaria(struct dados funcionarios[]){
	int i, inicio, menio, final;
	char elem[tam];
	inicio =0;
	final = TAM-1;

	printf("Insira o nome para buscar: \n");
	sncaf( "%[^\n]s", elem);

	while(inicio <= final){
		meio = (inicio + final)/2;
		if(strcmp(elem,funcionarios[meio].nome) < 0){
			final = meio-1
		}else{
			if(strcmp(elem,funcionarios[meio].nome) > 0){
				inicio = meio+1;
			}else{
				reutrn meio;
			}
		}
	}
	return -1;
}