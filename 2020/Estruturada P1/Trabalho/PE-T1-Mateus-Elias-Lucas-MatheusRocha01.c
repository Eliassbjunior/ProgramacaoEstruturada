//Mateus Freitas, Elias Júnior, Lucas de Figueiredo, Matheus Rocha - Jogo 01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define no 20
#define TAM 3

void jogadores(char *jogadorA, char *jogadorB);
void geramatriz(char matriz[3][3]);
void tabuleiro (char matriz[3][3], char *jogadorA, char *jogadorB, int vez);
void jogada(char matriz[3][3], int vez);
int verificacao(char matriz[3][3],char *jogadorA, char *jogadorB);
int jogar_novamente();

int main(){
	
	FILE *arqSaida = fopen("Velha.txt", "w");
	
	char matriz[TAM][TAM];
	char jogadorA[no],jogadorB[no];
	int i,j,g=1,veri,d=0,cont=0,vez=0;

	do{	
		
		system("clear");	
		jogadores(jogadorA,jogadorB);
		geramatriz(matriz);
		cont=0;
		vez=0;
	
		while(cont != 9 ){
		
			tabuleiro(matriz ,jogadorA,jogadorB,vez);
			jogada(matriz,vez);
			tabuleiro(matriz ,jogadorA,jogadorB,vez);
			veri=verificacao(matriz,jogadorA,jogadorB);
			vez++;
			cont++;
			if(veri == 1){
				cont=9;
			}else{
				if(veri == 0 && cont == 9 ){
					printf("VELHA: Nao houve nenhum vencedor!\n");
				}
			}
		}
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(matriz[i][j] != ' '){
					fprintf(arqSaida,"matriz[%d][%d] %c\n",i,j,matriz[i][j]);
				}
			}
		}
		vez=vez-1;
		
		if(veri == 0 && cont == 9 ){
			fprintf(arqSaida,"VELHA: Nao houve nenhum vencedor!\n");
			}else{
				if(vez %2 == 0){
					fprintf(arqSaida,"%s e o vencedor!\n",jogadorA);
				}else{
					fprintf(arqSaida,"%s e o vencedor!\n",jogadorB);
				}
			}
		g=jogar_novamente();
		
		if(g == 0){
			fclose(arqSaida);
		}
	}while(g != 0 );
}

void jogadores(char *jogadorA, char *jogadorB){
	char jogador_um[no],jogador_dois[no];
	int sorteio=0;
	
	__fpurge(stdin);
	srand(time(NULL));
		
	printf("Nome do jogador: \n");
	scanf("%[^\n]s", jogador_um);
	__fpurge(stdin);
	
	printf("Nome do jogador: \n");
	scanf("%[^\n]s", jogador_dois);
	__fpurge(stdin);

	system("clear");
	sorteio= rand()% 2+1;
	
	if(sorteio == 1){
		strcpy(jogadorA,jogador_um);
		strcpy(jogadorB,jogador_dois);
		
		printf("Jogador: %s e X!\n",jogadorA);
		printf("Jogador: %s e O!\n",jogadorB);	
	}else{
		if(sorteio == 2){
			strcpy(jogadorB,jogador_um);
			strcpy(jogadorA,jogador_dois);
		
			printf("Jogador: %s e X!\n",jogadorA);
			printf("Jogador: %s e O!\n",jogadorB);	
		}
		
	}
  getchar();
	
}

void geramatriz(char matriz[3][3]){
	
	int i, j;
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
		matriz[i][j]=' ';
		}
	}
}
void tabuleiro (char matriz[3][3], char *jogadorA, char *jogadorB, int vez){
	
	system("clear");
	if(vez %2 == 0){
		printf("Jogador X: %s\n",jogadorA);
	}else{
		printf("Jogador O: %s\n",jogadorB);
	}
	printf("\t     C0\t    C1\t   C2\t\n");
	printf("\t     \t|    \t|   \t\n");
	printf("\tL0   %c \t|  %c \t|  %c\t\n", matriz[0][0], matriz[0][1], matriz[0][2]);
	printf("\t ________________________\n");
	printf("\t     \t|    \t|   \t\n");
	printf("\tL1   %c \t|  %c \t|  %c\t\n", matriz[1][0], matriz[1][1], matriz[1][2]);
	printf("\t ________________________\n");
	printf("\t     \t|    \t|   \t\n");
	printf("\tL2   %c \t|  %c \t|  %c\t\n", matriz[2][0], matriz[2][1], matriz[2][2]);
}
void jogada(char matriz[3][3], int vez){
	int l,c,t=1;
	do{
		printf("Digite a Linha da jogada: \n");
		scanf("%d",&l);
	
		printf("Digite a Coluna da jogada: \n");
		scanf("%d",&c);
		
		if(l<0||l>3||c<0||l>3){
			printf("Linha ou coluna invalida:\n");
			l=0;
			c=0;
			t=1;
		}else{
			if(matriz[l][c]!= ' '){
				printf("\nLocal invalido\n");
				printf("               \n");
				t=1;
				l=0;
				c=0;
			}
			if(matriz[l][c]== ' '){
				if(vez%2==0){
					matriz[l][c]='X';
					t=0;				
				}
				if(vez%2!=0){
					matriz[l][c]='O';
					t=0;
				}
			}
		}
	}while(t==1);
}
int verificacao (char matriz[3][3],char *jogadorA, char *jogadorB){

	int d=0;
	//primeira linha
	if(matriz[0][0]== matriz[0][1] && matriz [0][0]== matriz[0][2] && matriz[0][0]!= ' '){
		if(matriz[0][0] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;
	}
	//segunda linha
	if(matriz[1][0]== matriz[1][1] && matriz [1][0]== matriz[1][2] && matriz[1][0]!= ' '){
		if(matriz[1][0] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;	
	}
	//terceira linha
	if(matriz[2][0]== matriz[2][1] && matriz [2][0]== matriz[2][2] && matriz[2][0]!= ' '){
		if(matriz[2][0] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;
	}
	//primeira coluna
	if(matriz[0][0]== matriz[1][0] && matriz [0][0]== matriz[2][0] && matriz[0][0]!= ' '){
		if(matriz[0][0] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;
	}
	//segunda coluna
	if(matriz[0][1]== matriz[1][1] && matriz [0][1]== matriz[2][1] && matriz[0][1]!= ' '){
		if(matriz[0][1] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;
	}
	//terceira coluna
	if(matriz[0][2]== matriz[1][2] && matriz [0][2] == matriz[2][2] && matriz[0][2]!= ' '){
		if(matriz[0][2] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;
	}
	//diagonal 1
	if(matriz[0][0]== matriz[1][1] && matriz [0][0]== matriz[2][2] && matriz[0][0]!= ' '){
		if(matriz[0][0] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;
	}
	//diagonal 2
	if(matriz[2][0]== matriz[1][1] && matriz [2][0]== matriz[0][2] && matriz[2][0]!= ' '){
		if(matriz[2][0] == 'X'){
			printf("%s Venceu o jogo!\n", jogadorA);
		}else{
			printf("%s Venceu o jogo!\n", jogadorB);
		}
		d=1;
	}
	return d;

}
int jogar_novamente( ){
	int t,novamente;
	
	printf("\nGostaria de jogar novamente?\n1 - Sim\n0 - Nao \n");
	scanf("%d", &novamente);
		
		if(novamente == 1){
			t=1;
		}else{
			if(novamente == 0){
				t=0;
			}
		}
	return t;
}
