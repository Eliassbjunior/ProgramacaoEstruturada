#include<stdio.h>
#include<stdlib.h>
#define n 30
void preencher(int v[]);
int expressao(int v[], int k);
int main(){
	int v[n],k = 0, maior=0;

	preencher(v);

	printf("Digite o valor de K(Entre 1 e 4): \n");
	scanf("%d", &k);
	
	while((k < 1)|| (k > 4)){
		printf("\nValor invalido, insira novamente: \n");
		scanf("%d", &k);
	}
	maior = expressao(v,k);

	printf("\n%d\n", maior);
	
}

void preencher(int v[]){	
	printf("Digite 30 numeros: \n");
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		
	}

}

int expressao(int v[], int k){
	int somatorio=0, vetor[n-k],maior=0;

	for(int i = 0; i <= n-k; i++){ 
		for(int j = i; j < i+k;j++){
			somatorio+=v[j];

		}
		vetor[i]=somatorio;
		somatorio=0;
	}

	for(int i = 0; i <= n-k;i++){
		if(vetor[i]>maior){
			maior=vetor[i];
		}
	}
	return maior;
}