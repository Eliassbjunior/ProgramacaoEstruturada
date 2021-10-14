#include <stdio.h>
#define linha 10
#define coluna 3

void preenche(float matriz[][coluna]);
void imprime(float matriz[][coluna]);

int main(){
	float matriz[linha][coluna];
	
	preenche(matriz);
	imprime(matriz);
	
	return 0;
}

void preenche(float matriz[][coluna]){
	int i, j;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			matriz[i][j]=-1;
			while((matriz[i][j]<0)||(matriz[i][j]>10)){
				printf("Informe a %d nota do %d aluno:\n", j+1, i+1);
				scanf("%f", &matriz[i][j]);
			}
		}
	}
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			printf("%.2f ", matriz[i][j]);
		}
		printf("\n");
	}
}

void imprime(float matriz[][coluna]){
	int i, j;
	float maior0=0, menor0=10, maior1=0, menor1=10, maior2=0, menor2=10;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(j==0){
				if(matriz[i][j]>maior0){
					maior0=matriz[i][j];
				}
				if(matriz[i][j]<menor0){
					menor0=matriz[i][j];
				}
			}
			if(j==1){
				if(matriz[i][j]>maior1){
					maior1=matriz[i][j];
				}
				if(matriz[i][j]<menor1){
					menor1=matriz[i][j];
				}
			}
			if(j==2){
				if(matriz[i][j]>maior2){
					maior2=matriz[i][j];
				}
				if(matriz[i][j]<menor2){
					menor2=matriz[i][j];
				}
			}
		}
	}
	printf("\nMaior nota Prova1: %.2f\nMaior nota Prova2: %.2f\nMaior nota Prova3: %.2f\n", maior0, maior1, maior2);
	printf("\nMenor nota Prova1: %.2f\nMenor nota Prova2: %.2f\nMenor nota Prova3: %.2f", menor0, menor1, menor2);
}