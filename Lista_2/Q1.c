#include "TABB.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q1) maior elemento da árvore: TABB* maior(TABB *a);

TABB* maior(TABB *a){
    if(!a) return a;
    TABB * resp = a;
    if(a->dir) resp = maior(a->dir);
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

  TABB *resp = maior(a);
  printf("O maior numero e %d", resp->info);
  TABB_libera(a);
  return 0;
} 
