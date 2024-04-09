#include "TABB.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q2) menor elemento da árvore: TABB* menor(TAB *a);

TABB* menor(TABB *a){
    if(!a) return a;
    TABB * resp = a;
    if(a->esq) resp = menor(a->esq);
    return resp;
}

int main(void){
  TABB *a = TABB_inicializa(); 
  int n;

  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_insere(a, n);
  }
  TABB_imp_ident(a);

  TABB *resp = menor(a);
  printf("O menor numero e %d", resp->info);
  TABB_libera(a);
  return 0;
} 
