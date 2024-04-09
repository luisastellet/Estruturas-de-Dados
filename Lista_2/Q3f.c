#include "TABB.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q3) uma função em C que, dada uma árvore binária de busca qualquer, retire todos os elementos
// ímpares da árvore original. A função deve ter o seguinte protótipo: TABB*
// retira_impares(TABB* a);

// Essa é a versão mais fácil, me aproveitando da função retira dela

TABB* retira_impares_com_funcao(TABB* a){
    if(!a) return a;
    a->esq = retira_impares_com_funcao(a->esq);
    a->dir = retira_impares_com_funcao(a->dir);
    if(a->info % 2){ //== 1 -> ímpar
        a = TABB_retira(a, a->info);
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

  TABB *resp = retira_impares_com_funcao(a);
  printf("Arvore final, sem impares:\n");
  TABB_imp_ident(resp);
  TABB_libera(a);
  return 0;
} 
