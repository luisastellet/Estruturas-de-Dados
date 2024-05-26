// (Q3) uma função em C que, dada uma árvore binária de busca qualquer, retire todos os elementos
// ímpares da árvore original. A função deve ter o seguinte protótipo: TABB*
// retira_impares(TABB* a);

#include "TABB.c"
#include <string.h>



TABB * retira_impares(TABB *a){
  if(!a) return NULL;
  a->esq = retira_impares(a->esq);
  a->dir = retira_impares(a->dir);

  if(a->info % 2 != 0){
  // if(a->info % 2 != 0){ //elemento ímpar
    if(!a->esq && !a->dir){
        free(a);
        return NULL;
    }
    else if(!a->esq || !a->dir){ //um filho só
      TABB * tmp = a;
      if(!a->esq) a = a->dir;
      else a = a->esq;
      free(tmp);
      return a;
    }
    else{ // dois filhos
      TABB * tmp = a->esq;
      while(tmp->dir) tmp = tmp->dir;
      int aux = tmp->info;
      tmp->info = a->info;
      a->info = aux;
      free(tmp);
      a->esq = retira_impares(a->esq);
    }
  }
  return a;
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
  
  TABB *resp = retira_impares(a);
  printf("Arvore final, sem impares:\n");
  TABB_imp_ident(resp);
  TABB_libera(a);
  return 0;
} 