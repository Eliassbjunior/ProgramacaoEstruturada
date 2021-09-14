#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 20
void ler(int vetor_A[]);
void preencher(int vetor_A[],int vetor_B[]);
int fatorial(int vetor_A[],int i);

int main(){
	int vetor_A[tam], vetor_B[tam];

	ler(vetor_A);
	preencher(vetor_A,vetor_B);

	return 0;
}
void ler(int vetor_A[]){
	int i;
	
	srand(time(NULL));

	for (i = 0; i < tam; ++i)
	{
		vetor_A[i]=rand()%11;
	}

}
void preencher(int vetor_A[],int vetor_B[]){
	int i;

	for (i = 0; i < tam; ++i)
	{
		vetor_B[i]=fatorial(vetor_A,i);		
	}
	
}
int fatorial(int vetor_A[],int i){
	int j,resp=0; 

	for (j = 1; j < vetor_A[i]; j++)
	{
		resp+=vetor_A[i]*j;
	}

	return resp;
}
