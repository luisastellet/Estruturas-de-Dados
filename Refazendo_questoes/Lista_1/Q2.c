// (Q2) espelho de uma árvore (o que está a esquerda na árvore original, estará a direita no espelho, e
// vice-versa): TAB* espelho (TAB *a);
#include "TAB.c"
#include <string.h>

TAB * espelho (TAB *a){
    if (!a) return a;
    TAB * copy = TAB_cria(a->info, NULL, NULL);
    copy->esq = espelho(a->dir);
    copy->dir = espelho(a->esq);
    return copy;
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
  printf("\naa\n");
  TAB * teste = espelho(a);
  TAB_imp_ident(teste);
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
