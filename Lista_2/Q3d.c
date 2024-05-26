#include "TABB.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q3) uma função em C que, dada uma árvore binária de busca qualquer, retire todos os elementos
// ímpares da árvore original. A função deve ter o seguinte protótipo: TABB*
// retira_impares(TABB* a);

// Essa é a versão mais difícil, sem aproveitar a função retira dela

TABB* retira_impares_sem_funcao(TABB* a){
    if(!a) return a;
    // a = TABB_retira(a, a->info);
    a->esq = retira_impares_sem_funcao(a->esq);
    a->dir = retira_impares_sem_funcao(a->dir);
    if(a->info % 2){ //== 1 -> ímpar
        if((!a->dir) && (!a->esq)){ //folha
            free(a);
            a = NULL;
        }
        else if ((!a->esq) || (!a->dir)){ //só tem um filho
            TABB * aux = a;
            if(a->esq) a = a->esq;
            else a = a->dir; //se a->esq não existir, a->dir tem q existir !!!
            free(aux);
        }
        else{ //tem dois filhos
            TABB * aux = a->esq;
            while(a->dir) a = a->dir;
            int tmp = a->info;
            a->info = aux->info;
            aux->info = tmp;
            free(aux);
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
  
  TABB *resp = retira_impares_sem_funcao(a);
  printf("Arvore final, sem impares:\n");
  TABB_imp_ident(resp);
  TABB_libera(a);
  return 0;
} 
