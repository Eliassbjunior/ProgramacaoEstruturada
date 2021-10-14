//3 - Digitar uma frase com espaços e imprimir invertido. EX: Eu estudo no IFF -> IFF no estudo Eu
#include<stdio.h>
#include <string.h>
int main(){
	char frase[30];

	preencher(frase);
	inverter(frase);

	return 0;
}
void preencher(char frase[], char frase_invertida){
	printf("Digite a frase: ");
	scanf(" %[^/n]s");
}
void inverter(char frase[]){

}