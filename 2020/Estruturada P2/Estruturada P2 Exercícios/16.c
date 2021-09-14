#include <stdio.h>
#include <stdlib.h>
void recursivo_fatorial(int numero, int *resultado, int contador);
int factorial(int numero);
int main(){
	int numero,contador=1,resultadoo=1;
	int *resultado;
	resultado=&resultadoo;
	
	printf("Digite o numero: ");
	scanf("%d", &numero);
		
	recursivo_fatorial(numero,resultado,contador);
	
	printf("\nO fatorial de %d e: %d", numero, factorial(numero));
	printf("\nO fatorial de %d e: %d", numero,*resultado);
	
	return 0;
}
//Elias
void recursivo_fatorial(int numero, int *resultado,int contador){
	if(contador <= numero){
		*resultado *= contador;
		contador++;
		recursivo_fatorial(numero,resultado,contador);
	}
}
//Craveiro
int factorial(int numero) {
     if(numero == 1 || numero == 0) return 1;
     return numero * factorial(numero - 1);
}
