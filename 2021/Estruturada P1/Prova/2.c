// 2 - Existe dois arquivos com 10 numeros aleatórios, gerar terceiro arquivo com os números em ordem não crescente. (ordem crescente sem numeros repetidos)

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define X 10
#define Y 20
void preencher(int A[]);
void ordenar(int A[]);
void devolver(int A[]);
int main(){
	int A[Y];

	preencher(A);
	ordenar(A);
	devolver(A);

	return 0;
}

void preencher(int A[]){
	int j = 0;
	FILE *arqA = fopen("A.txt", "r");
	FILE *arqB = fopen("B.txt", "r");

	for(int i = 0; i < 20; i++){
		if(i < 10){
			fscanf(arqA,"%d", &A[i]);
		}else{
			fscanf(arqB,"%d", &A[i]);
			
		}
		
	}

	
}
void ordenar(int C[]){
	int k = 0, j, aux;

    while(k < Y){
        for (j = 0; j < Y - 1; j++) {

            if (C[j] > C[j + 1]) {
                aux = C[j];
                C[j] = C[j + 1];
                C[j+1] = aux;
            }
        }
        k++;
    }

}
void devolver(int C[]){
	FILE *arqC = fopen("C.txt", "w");

	for(int i = 0; i < Y; i++){
		fprintf(arqC, "%d ", C[i]);
	}

	fclose(arqC);
}