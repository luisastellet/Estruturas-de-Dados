#include "TAB.c"
#include <stdio.h>
#include <string.h>
#include <stdio.h>

// (Q6) uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da
// árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* a);

TAB* retira_pares (TAB* a){
    if(!a) return a;
    a->esq = retira_pares(a->esq);
    a->dir = retira_pares(a->dir);
    if(a && (a->info % 2 == 0)){
        if((!a->esq) && (!a->dir)){
            free(a);
            return NULL;
        }
        else if((!a->esq) || (!a->dir)){
            TAB *tmp = a;
            if(!a->esq) a = a->dir;
            if(!a->dir) a = a->esq;
            free(tmp);
            return a;
        }else{
            TAB * trocar = a->esq;
            while(trocar->dir){
                trocar = trocar -> dir;
            }
            int x = a-> info;
            a->info = trocar-> info;
            trocar ->info = x;
            free(trocar);
            a = retira_pares(a); //preciso ver se quem eu coloquei não era par
        }
    }
    return a;
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  TAB * teste = retira_pares(a);
  printf("\n RESULTADO \n");
  TAB_imp_ident(teste);
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
