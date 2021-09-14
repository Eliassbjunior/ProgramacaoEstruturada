#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 20
int recursivo_soma(int vetor[],int j);
int main(){
	int i,vetor[tam],j=0;
	
	srand(time(NULL));
	for(i=0;i<tam;i++) vetor[i]= rand()%50+1;
	
	for(i=0;i<tam;i++) printf("%d ",vetor[i]);
	
	printf("Soma:%d",recursivo_soma(vetor,j));
	
	return 0;
}
int recursivo_soma(int vetor[],int j){
	j++;
	if(j>tam) return 0;
	return vetor[j-1] + recursivo_soma(vetor,j);
}
