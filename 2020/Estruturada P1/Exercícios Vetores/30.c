#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define tam 40
void ler(int vetor_um[], int vetor_dois[]);
int calculo(int vetor_um[tam], int vetor_dois[tam], int x, int y);

int main(){
	int vetor_um[tam],vetor_dois[tam],x,y;
	
	ler(vetor_um,vetor_dois);

	printf("Digite o valor de x: ");
	scanf("%d", &x);

	printf("Digite o valor de y: ");
	scanf("%d", &y);

	result=calculo(vetor_um,vetor_dois,x,y);
	
	if(result == 1){
		printf("Condicao verdadeira!");
	}else{
		printf("Condicao falsa!");
	}
	return 0;
}
void ler(int vetor_um[], int vetor_dois[]){
	int i;
	
	printf("Digite 40 numeros vetor_um! ");
	for(i=0,i<tam;i++){
		scanf("%d", vetor_um[i]);
	}
    printf("Digite 40 numeros vetor_dois! ");
	for(i=0,i<tam;i++){
		scanf("%d", vetor_dois[i]);
	}
}


int calculo(int vetor_um[tam], int vetor_dois[tam], int x, int y){
	int somatorio=0, produtorio=1;

	for (int i = 0; i < tam-1; ++i)
	{
		if(vetor_um[i] %2 != 0){
			somatorio+= abs(vetor_um[i])*x;
		}
	}

	for (int i = 0; i < tam-1; ++i)
	{
		if(vetor_dois[i] %2 == 0){
			produtorio *= abs(vetor_dois[i])*y;
		}
	}

	if(somatorio <= produtorio){
		return 1;
	}else{
		return 0;
	}
}
