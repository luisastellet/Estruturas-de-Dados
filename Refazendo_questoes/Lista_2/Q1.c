//(Q1) maior elemento da árvore: TABB* maior(TABB *a);

#include "TABB.c"
#include <string.h>

TABB * maior(TABB *a){
    if(!a) return NULL;
    TABB * resp = maior(a->dir);
    if(!a->dir) resp = a;
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
