#include <stdio.h>
#include <stdlib.h>
#define L 5
#define C 6
void preencher(int matriz[][C]);
void verificar(int matriz[][C]);

int main(){
	
	int matriz[L][C];
	
	preencher(matriz);
	verificar(matriz);
	
	return 0;
}
void preencher(int matriz[][C]){
	int i,j,auxiliar=0;
	
	printf("Digite 30 numeros naturais: \n");
	for(i = 0; i < L; i++){
		for(j = 0 ; j < C; j++){
			
			scanf("%d", &auxiliar);
			
			if(auxiliar >= 1 ){
				matriz[i][j]=auxiliar;
				auxiliar=0;
			}else{
				while(auxiliar < 1){
					printf("Numero nao natural!\n");
					
					printf("Digite um numero natural: \n");
					scanf("%d", &auxiliar);
				}
				matriz[i][j]=auxiliar;
				auxiliar=0;
			}
		}
	}
}
void verificar(int matriz[][C]){
	int i,j,k,primo=0,d=0;
	for(i = 0; i < L; i++){
		for(j = 0 ; j < C; j++){
			for(k = 1;k <= matriz[i][j]; k++){
				if(matriz[i][j]%k == 0){
					d++;
				}
			}
			if(d == 2){
				primo++;
				d=0;
			}else{
				d=0;
			}
		}
	}
	if(primo < 1){
		printf("Nao tem numeros primos!");
	}else{
		if(primo == 1){
			printf("Tem %d numero primo!",primo);
		}else{
			printf("Tem %d numeros primos!",primo);
		}
		
	}	
}

