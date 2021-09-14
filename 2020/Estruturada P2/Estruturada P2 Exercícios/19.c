#include <stdio.h>
#include <stdlib.h>
int recursivo_fibonacci(int numero);
int main(){
	int	posicao,i;
	
	printf("Digite a posicao: ");
	scanf("%d", &posicao);
	
	printf("%d ",recursivo_fibonacci(posicao));

	return 0;
}
int recursivo_fibonacci(int numero){
	if(numero == 1 ) return 1;
	if(numero == 2) return 1;
	return recursivo_fibonacci(numero-1) + recursivo_fibonacci(numero-2);
}
