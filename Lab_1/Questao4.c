#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAB.c"

//Verificar se uma árvore é estritamente binária, isto é, os nós dessa árvore possuem 
//ou zero ou dois filhos - int estbin(TAB *a);

//se algm tive q filho só, retorna 0

int estbin(TAB *a){
    if(!a) return 1;
    if((!a->dir && a->esq) || (a->dir && !a->esq)) return 0;
    //return estbin(a->dir) && estbin(a->esq);
    int ver_esq = estbin(a->esq);
    int ver_dir = estbin(a->dir);
    return ver_esq && ver_dir;
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
  printf("\n");

  int x = estbin(a);
  if(x) printf("E estritamente binaria!");
  else printf("Nao e estritamente binaria!");

  TAB_libera(a);
  return 0;
  }
