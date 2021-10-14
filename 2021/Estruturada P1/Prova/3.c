#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define tam 51

void ler_frase(char frase[tam]);

void imprimir(char frase[tam]);

int main(){

  char frase[tam];

  ler_frase(frase);
  imprimir(frase);

  return 0;
}

void ler_frase(char frase[tam]){

  printf("Digite uma frase com espaços: ");
  scanf("%[^\n]s", frase);
}

void imprimir(char frase[tam]){

  int i=0, j, tamanho, prox;
  
  tamanho=strlen(frase);

  prox=tamanho;

  for(i=tamanho;i>=0;i--){
    if(frase[i]==' '||i==0){
      if(i==0){
        printf(" ");  
      } 
      for(j=i;j<prox;j++){
        printf("%c", frase[j]);
      }
      
      
      prox=i;
    }
  }




  

}

