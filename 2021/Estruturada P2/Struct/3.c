#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tam 2
struct pontos{
	int x;
	int y;
};
void preencher(struct pontos coord[]);
float distancia(struct pontos coord[]);

int main(){
	struct pontos coord[tam];
	preencher(coord);
	printf("\nA distancia entre os pontos e: %2.f",distancia(coord));
	
	return 0;
}
void preencher(struct pontos coord[]){
	int i;
	printf("Informacao Coordenadas!\n");
	for(i = 0; i < tam; i++){
		printf("%d Ponto \n", i+1);
		
		printf("Coordenada X: \n");
		scanf("%d", &coord[i].x);
		
		printf("Coordenada Y: \n");
		scanf("%d", &coord[i].y);
	}
}
float distancia(struct pontos coord[]){
	float distancia;
	
	distancia= sqrt(powl((coord[1].x - coord[0].x),2) + powl((coord[1].y - coord[0].y),2));
	
	return distancia;
}
