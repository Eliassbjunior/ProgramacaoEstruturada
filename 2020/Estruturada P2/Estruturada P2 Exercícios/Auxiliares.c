void preencher(int vetor[]){
	int i;

	srand(time(NULL));
	for(i = 0 ; i < tam ; i++){
		vetor[i]=rand()%30+1;
	}		
}
void imprimir(int vetor[]){
	int i;

	for(i = 0 ;i < tam; i++){
		printf("%d\n",vetor[i]);
	}
}
void preencher(int vetor[]){
	int i;

	printf("Digite 15 numeros: \n");
	for(i = 0; i < tam; i++){
		scanf("%d", &vetor[i]);
	}		
}
