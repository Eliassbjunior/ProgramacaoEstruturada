#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 30

struct dados{
	int matricula,p1,p2,p3;
	char nome[tam];
};
void preencher(struct dados alunos[]);
void imprimir(struct dados alunos[], char consulta[]);

int main(){
	struct dados alunos[tam];
	char consulta[tam];
	
	preencher(alunos);
	printf("Nome para consulta: \n");
	scanf("%[^\n]s", consulta);
	imprimir(alunos,consulta);
	
	return 0;	
}
void preencher(struct dados alunos[]){
	int i;
	printf("Cadastro de notas\n");
	for(i = 0; i < tam; i++){
		fflush(stdin);
		printf("Nome: \n");
		scanf("%[^\n]s", alunos[i].nome);
		printf("Matricula: \n");
		scanf("%d", &alunos[i].matricula);
		printf("Nota P1: \n");
		scanf("%d", &alunos[i].p1);
		printf("Nota P2: \n");
		scanf("%d", &alunos[i].p2);
		
		alunos[i].p3 = (alunos[i].p1 + alunos[i].p2)/2;
		system("cls");
	}
}
void imprimir(struct dados alunos[], char consulta[]){
	int i;
	
	for(i = 0;i < tam; i++){
		if(strcmp(alunos[i].nome,consulta) == 0){
			printf("\nAluno: %s", alunos[i].nome);
			printf("\nP1: %d", alunos[i].p1);
			printf("\nP2: %d", alunos[i].p2);
			printf("\nP3: %d", alunos[i].p3);
		}
	}
}
