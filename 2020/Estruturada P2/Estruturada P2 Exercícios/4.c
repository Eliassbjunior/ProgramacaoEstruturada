#include <stdio.h>
#include <stdlib.h>
#define tam 30
struct dados{
	int matricula,p1,p2,p3;
	char nome[tam];
};
void preencher(struct dados alunos[]);
void imprimir(struct dados alunos[]);

int main(){
	struct dados alunos[tam];
	
	preencher(alunos);
	imprimir(alunos);
	
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
void imprimir(struct dados alunos[]){
	int i,aprovado,reprovado;
	
	for(i = 0;i < tam; i++){
		if(alunos[i].p3 >= 6){
			aprovado++;
		}else{
			reprovado++;
		}
	}
	
	printf("%d alunos aprovados\n", aprovado);
	printf("%d alunos reprovados\n", reprovado);
}
