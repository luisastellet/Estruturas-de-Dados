//(Q2) menor elemento da árvore: TABB* menor(TABB *a);

#include "TABB.c"
#include <string.h>

TABB * menor(TABB *a){
    if(!a) return NULL;
    TABB * resp = menor(a->esq);
    if(!a->esq) resp = a;
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
