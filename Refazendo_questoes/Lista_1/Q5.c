// (Q5) uma função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A função
// retorna um se elas são iguais e zero, caso contrário. A função deve obedecer ao seguinte protótipo:
// int igual (TAB* a1, TAB* a2);
#include "TAB.c"
#include <string.h>

int igual (TAB* a, TAB* b){
    if(!a && !b) return 1; //as duas não existem
    else if((!a && b) || (a && !b)) return 0; //uma existe a outra não
    if(a->info != b->info) return 0;
    int ver_esq = igual(a->esq, a->esq);
    int ver_dir = igual(a->dir, b->dir);
    return ver_dir && ver_esq;
}

int main(void){
  int no1, no2, pai1, pai2;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no1);
  TAB *a1 = TAB_cria(no1, NULL, NULL), *resp1;
  char repete1, repete2;
  do{
        char lado1[2];
        printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
        scanf(" %c", &repete1);
        if((repete1 == 'N') || (repete1 == 'n')) break;
        printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
        scanf("%d%d%s", &pai1, &no1, lado1);
        resp1 = TAB_busca(a1, pai1);
        if(!resp1){
        TAB_libera(a1);
        return 0;
        }
        if(strcmp(lado1, "E") == 0) resp1->esq = TAB_cria(no1, NULL, NULL);
        else resp1->dir = TAB_cria(no1, NULL, NULL);
  }while(1);

    printf("ARVORE 2 AGORA EIN\n\n");
    printf("Digite a raiz da arvore... ");
    scanf("%d", &no2);
    TAB *a2 = TAB_cria(no2, NULL, NULL), *resp2;

  do{
        char lado2[2];
        printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
        scanf(" %c", &repete2);
        if((repete2 == 'N') || (repete2 == 'n')) break;
        printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
        scanf("%d%d%s", &pai2, &no2, lado2);
        resp2 = TAB_busca(a2, pai2);
        if(!resp2){
        TAB_libera(a2);
        return 0;
        }
        if(strcmp(lado2, "E") == 0) resp2->esq = TAB_cria(no2, NULL, NULL);
        else resp2->dir = TAB_cria(no2, NULL, NULL);
    }while(1);

  TAB_imp_ident(a1);
  TAB_imp_ident(a2);
  int teste = igual(a1, a2);
  printf("A resposta eh %d\n", teste);
  if(teste) printf("Iguais");
  else printf("Diferentes");
  printf("\n");
  
  TAB_libera(a1);
  TAB_libera(a2);

  return 0;
}
