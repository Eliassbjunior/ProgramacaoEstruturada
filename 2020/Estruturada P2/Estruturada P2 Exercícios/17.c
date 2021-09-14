#include <stdio.h>
#include <stdlib.h>
void recursivo_pontencia(int a, int b, int contador, int *resultado);
int potencia(int a,int b,int contador);
int main(){
	
	int a,b,contador,resultadoo;
	int *resultado;
	
	resultado= &resultadoo;
	contador=1;
	
	printf("Insira o valor A: ");
	scanf("%d", &a);
	
	printf("\nInsira o valor B: ");
	scanf("%d", &b);
	
	resultadoo = a;
	printf("\n%d elevado a %d potencia e igual a:%d", a , b, potencia(a,b,contador));
	recursivo_pontencia(a,b,contador,resultado);
	
	printf("\n%d elevado a %d potencia e igual a:%d", a , b, resultadoo);
	
	return 0;
}
void recursivo_pontencia(int a, int b, int contador, int *resultado){
	if(contador <= b-1){
		*resultado *= a;
		contador++;
		recursivo_pontencia(a,b,contador,resultado);
	}
}
int potencia(int a,int b,int contador){
	contador++;
	if(contador>b) return a;
	return a * potencia(a,b,contador);
}
