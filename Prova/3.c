#include<stdio.h>
#include<stdlib.h>
#define AL 3
#define AC 5
#define BL 4
#define BC 5
#define BTL 5
#define BTC 4
#define CL 3
#define CC 4
void preencher(int A[][AC], int B[][BC]);
void transposta(int B[][BC], int B_T[][BTC]);
void calcular(int A[][AC], int B_T[][BTC], int C[][CC]);
void imprimir(int C[][CC]);
int numero_primo(int numero);

int main(){
	int A[AL][AC], B[BL][BC], B_T[BTL][BTC], C[CL][CC];

	preencher(A,B);
	transposta(B,B_T);
	calcular(A,B_T,C);
	imprimir(C);

	return 0;
}
void preencher(int A[][AC], int B[][BC]){

	FILE *arqA = fopen("MatrizA.txt","r");
	FILE *arqB = fopen("MatrizB.txt","r");

	for(int i = 0; i < AL; i++){
		for(int j = 0; j < AC; j++){
			fscanf(arqA,"%d", &A[i][j]);
		}
	}


	for(int i = 0; i < BL; i++){
		for(int j = 0; j < BC; j++){
			fscanf(arqB,"%d", &B[i][j]);
		}
	}
	fclose(arqA);
	fclose(arqB);
}
void transposta(int B[][BC], int B_T[][BTC]){
	for (int i = 0; i < BL; ++i)
	{
		for (int j = 0; j < BC; ++j)
		{
			B_T[j][i] = B[i][j];
		}
	}
}
void calcular(int A[][AC], int B_T[][BTC], int C[][CC]){
	int i,j,k,aux;

	for(i = 0; i < AL; i++){
		for(j = 0; j < BTC; j++){
			C[i][j] = 0;
			for(k = 0; k < BTL; k++){
				aux += A[i][k] * B_T[k][j];
			}

			C[i][j] = aux;
			aux = 0;
		}
	}
}
void imprimir(int C[][CC]){
	int quantidade = 0, auxiliar = 0;

	for(int i = 0; i < CL;i++){
		for(int j = 0; j < CC; j++){
			auxiliar = numero_primo(C[i][j]);
			if(auxiliar == 0){
				quantidade++;
			}
			
		}
	}

	printf("\nEssa matriz possui %d numeros primos\n", quantidade);
}
int numero_primo(int numero){

	for(int k = 2; k <= numero/2; k++){
		if(numero % k == 0){
			return 1;
		}
	}

	return 0;
}
