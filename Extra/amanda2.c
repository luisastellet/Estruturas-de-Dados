//retornar em uma lista encadeada todos os elementos entre x e y
//é uma TABB

#include "TABB.c"
#include "TLSE.c"
#include <string.h>

TLSE * aux(TABB * a, int x, int y, TLSE * l){
  if(!a) return l;
  l = aux(a->dir, x, y, l);
  if((a->info > x) && (a->info < y)) l = TLSE_insere(l, a->info);
  l = aux(a->esq, x, y, l);
  return l;
}

TLSE * entreXY (TABB * a, int x, int y){
  if(!a) return NULL;
  TLSE * l = TLSE_inicializa();
  l = aux(a, x, y, l);
  return l;
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
  
  int x, y;
  printf("entre quem? ");
  scanf("%d %d", &x, &y);

  TLSE * teste = entreXY(a, x, y);
  TLSE_imprime(teste);
  
  TABB_libera(a);
  return 0;
} 

