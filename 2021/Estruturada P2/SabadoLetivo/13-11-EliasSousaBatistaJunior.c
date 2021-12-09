#include<stdio.h>
#include<stdlib.h>
#define TAM 30

struct aluno{
	int matricula;
	char primeiroNome[TAM];
	float n1,n2,media;
};

void preencher(struct aluno v[]);
int busca(struct aluno v[], float media);

int main(){
	struct aluno v[100];
	int quantidade = 0;
	float media;

	preencher(v);

	printf("Digite a media a ser pesquisada: \n");
	scanf("%f", &media);

	quantidade = busca(v, media);

	printf("Quantidade de alunos com media maior que %.1f: %d", media, quantidade);

	return 0;
}
void preencher(struct aluno v[]){
	for(int i = 0; i < TAM; i++){
		printf("Digite a matricula: \n");
		scanf("%d", v[i].matricula);

		printf("Digite o nome: \n");
		scanf(" %[\n]s", v[i].primeiroNome);

		printf("Digite a nota 1: \n");
		scanf("%f", v[i].n1);

		printf("Digite a nota 2: \n");
		scanf("%f", v[i].n2);

		v[i].media = (v[i].n1 + v[i].n2)/2;
	}
}
int busca(struct aluno v[], float media){
	int quantidade = 0;

	for(int i = 0; i < TAM; i++){
		if(v[i].media >= media){
			quantidade++;
		}
	}

	return quantidade;
}
