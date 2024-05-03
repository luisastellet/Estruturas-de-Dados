#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q3) Escreva um procedimento que receba o nome de um arquivo texto, cujo conteúdo são valores
// inteiros e imprima na tela o número de vezes que cada elemento aparece e em quais linhas – void
// resumo(char *Arq).


void resumo(char *Arq){
  FILE *fp = fopen(Arq, "r");
  if (!fp) exit(1);
  int r, referencia, linhas, indice = 0;

  while(1){
    r = fscanf(fp, "%d", &referencia);
    if(r != 1) break;
    else linhas++;
  }

  int * vetor = (int)malloc(sizeof(int)*linhas);
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

int main(int argc, char **argv){
  int i, x = atoi(argv[1]);
  printf("%d\n", x);
  for(i = 0; i < argc; i++)
    printf("argv[%d] = %s\n", i, argv[i]);
    
  return 0;
}