#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAB.c"

// Testar se uma árvore é zigue-zague, isto é, todos os nós internos, exceto a raiz, 
//possuem exatamente uma sub-árvore vazia - int zz(TAB *a);

int aux (TAB * a){
    if(!a) return 1;
    int r_esq = aux(a->esq);
    int r_dir = aux(a->dir);
    if(a->esq && a->dir) return 0;
    return r_esq && r_dir;
}

int zz(TAB * a){
    if(!a) return 0;
    return aux(a->esq) && aux(a->dir);
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
  
  int x = zz(a);
  if(x) printf("E zig-zag!\n");
  else printf("Nao e zig-zag!\n");

  TAB_libera(a);
  return 0;
}
