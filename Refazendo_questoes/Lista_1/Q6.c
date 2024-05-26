// (Q6) uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da
// árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* a);
#include "TAB.c"
#include <string.h>

TAB * retira_pares(TAB * a){
    if(!a) return a;
    a->esq = retira_pares(a->esq);
    a->dir = retira_pares(a->dir);
    if(a && a->info % 2 == 0){ //par
        if(!a->dir && !a->esq){ //sou folha
            free(a);
            return NULL;
        }
        else if(!a->dir){ //existe filho da esq
            TAB * tmp = a;
            a = a->esq;
            free(tmp);
            return a;
        }
        else if(!a->esq){ //existe filho da dir
            TAB * tmp = a;
            a = a->dir;
            free(a); 
            return a;
        }
        else{
            TAB * tmp = a->esq;
            while(tmp->dir){ //pra não chegar em NULL
                tmp = tmp->dir;
            }
            int aux = tmp->info;
            tmp->info = a->info;
            a->info = aux;
            free(tmp);
            a = retira_pares(a);
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
