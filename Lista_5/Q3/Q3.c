#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q3) Escreva um procedimento que receba o nome de um arquivo texto, cujo conteúdo são valores
// inteiros e imprima na tela o número de vezes que cada elemento aparece e em quais linhas – void
// resumo(char *Arq).


void resumo(char *Arq){
  FILE *fp = fopen(Arq, "r");
  if (!fp) exit(1);
  int r, referencia, linha_principal = 1, linha_aux = 0;

  while(1){
    r = fscanf(fp, "%d", &referencia);
    if(r != 1) break;
    printf("Numero %d na linha %d.\n", referencia, linha_principal);
  }

  int * vetor = (int)malloc(sizeof(int)*linha);
  rewind(fp); //subindo o cursos pro início

  while(1){
    r = fscanf(fp, "%d", &referencia);
    vetor[indice] = referencia;
    indice++;
    int r1 = 1;
    while(r1 == 1){
      
    }
  }



}

int main () {
  char dadosSaida[50];

  printf("digite o nome do arquivo de saida: \n");
  scanf("%s", dadosSaida);

  media("entrada-Q3");

  return 0;
}