#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define AL 5
#define AC 4
#define BL 5
#define BC 4
#define BTL 4
#define BTC 5
#define CL 5
#define CC 5
void preencher(int A[AL][], int B[BL][]);
void transposta(int B[BL][], int B_T[BTL][]);
void calcular(int A[AL][], int B_T[BTL][], int C[CL][]);
void imprimir(int C[CL]);

int main(){
	int A[AL][AC], B[BL][BC],B_T[BTL][BTC], C[CL][CC];

	preencher(A,B);
	transposta(B,B_T);
	calcular(A,B_T,C);
	imprimir(C);

	return 0;

}

void preencher(int A[AL][], int B[BL][]){
	
	srand(time(NULL));
	for(int i=0;i<5;i++){
    	for(int j=0;j<4;j++){
      		A[i][j]=rand()%100+1;
      		B[i][j]=rand()%100+1;
    	}
  	}
}

void transposta(int B[BL][], int B_T[BTL][]){

	for(int i=0;i<5;i++){
    	for(int j=0;j<4;j++){
      		B_T[j][i] = B[i][j];
    	}
  	}
}

void calcular(int A[AL][], int B_T[BTL][], int C[CL][]){
	int i,j,k,aux;

	for(i = 0; i < AL i++) {
		for(j = 0; j < BTC; j++) {
			
			C[i][j] = 0;
			for(k = 0; k < BTL; k++) {
				aux +=  A[i][k] * B_T[k][j];
			}

			C[i][j] = aux;
			aux = 0;
		}
	}
}
void imprimir(int C[CL]){
	for(int i = 0; i < CL; i++){
		for(int j = 0; j < CC; j++){
			for (int k = 2; k <= C[i][j]/2; k++) {
				if (C[i][j] % k == 0) {
					printf("%d ", C[i][j]); //Imprime os numeros compostos
					break;
				}
 			}
		}
	}
}