#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "TG.c"

//(Q1) descubra a quantidade de nós: int nn(TG *g);
// GRAFO NÃO ORIENTADO E ORIENTADO

int nn(TG *g){
    int tam = 0;
    TG * ponteiro = g;
    while(ponteiro){
        tam++;
        ponteiro = ponteiro -> prox_no;
    }
    return tam;
}

int main(void){
  TG *g = TG_inicializa();
  int n;
  printf("Os nos: ");
  do{
    scanf("%d", &n);
    if(n <= 0) break;
    g = TG_ins_no(g, n);
  }while(1);
  
  printf("As relacoes: ");
  int m;
  do{
    scanf("%d%d", &n, &m);
    if((n <= 0) || (m <= 0)) break;
    TG_ins_aresta(g, n, m);
  }while(1);
  printf("\n");
  TG_imprime(g);
  
  int resp = nn(g);
  printf("O grafo tem %d nos", resp);
  TG_libera(g);
  return 0;
}

