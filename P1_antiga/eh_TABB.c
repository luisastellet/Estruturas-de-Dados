// Descubra se uma TAB é AVL ou não

#include "TAB.c"
#include <string.h>
#include <limits.h>


int eh_TABB_aux (TAB * a){
  if(!a) return 1;
  if(a->esq && (a->esq->info > a->info)) return 0; //se o da esquerda for maior
  if(a->dir && (a->dir->info < a->info)) return 0; //se o da direita for maior
  int r_esq = eh_TABB_aux(a->esq);
  int r_dir = eh_TABB_aux(a->dir);
  return r_esq && r_dir;
}

int eh_TABB (TAB *a){
  if(!a) return 1;
  return eh_TABB_aux(a);
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na arvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posicao E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
    TAB_imp_ident(a);
  }while(1);
  TAB_imp_ident(a);
  int teste = eh_TABB(a);
  if(teste) printf("Essa TAB eh uma TABB!!!");
  else printf("Essa TAB NAO eh uma TABB :(");
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
