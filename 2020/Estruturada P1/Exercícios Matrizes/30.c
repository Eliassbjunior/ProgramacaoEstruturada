#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define L 4
#define C 5

void gerar_matrizes(int matriz_A[][C],int matriz_B[][L]);
int condicao(int matriz_A[][C],int matriz_B[][L]);

int main(){
	int matriz_A[L][C], matriz_B[C][L],resposta=0;
	
	gerar_matrizes(matriz_A,matriz_B);
	resposta=condicao(matriz_A,matriz_B);
	if(resposta == 1){
		printf("Condicao Satisfeita!");
	}else{
		printf("Condicao Nao Satisfeita!");
	}
}
void gerar_matrizes(int matriz_A[][C],int matriz_B[][L]){
	int i,j;
	srand(time(NULL));

	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			matriz_A[i][j]=rand()% 30+1;
		}
	}
	for(i = 0; i < C; i++){
		for(j = 0; j < L; j++){
			matriz_B[i][j]=rand()% 30+1;
		}
	}
}
int condicao(int matriz_A[][C],int matriz_B[][L]){
	int i,j,minimo,somatorio=0,maximo,produtorio=1;
	
	for (j = 0; j < L; ++j)
	{
		for (i = 0; i < C; ++i)
		{
			somatorio+=abs(matriz_A[i][j]);
		}

		if(j == 0){
			minimo=somatorio;
		}else{

			if(somatorio<minimo){
				minimo=somatorio;
			}	
		}
		somatorio=0;
	}
	
	for (i = 0; i < C; ++i)
	{
		for (j = 0; j < L; ++j)
		{
			produtorio*=matriz_B[i][j];
		}
		if(i == 0){
			maximo=produtorio;
		}else{

			if(produtorio>maximo){
				maximo=produtorio;
			}	
		}
		produtorio=0;	
	}
	if(minimo <= maximo){
		return 1;
	}else{
		return 0;
	}
}
	
	
