#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAB.c"

// Testar se uma árvore é zigue-zague, isto é, todos os nós internos, exceto a raiz, 
//possuem exatamente uma sub-árvore vazia - int zz(TAB *a);

int resto(TAB *a){
	if(!a) return  1;
	if((a->esq && a->dir)) return 0; //n é zif za 2 filhos
  int ver_esq = resto(a->esq);
  int ver_dir = resto(a->dir);
  if(!ver_dir || !ver_esq) return 0;
  
  //if(!resto(a->esq) || !resto(a->dir)) return 0;

	return 1;	
}

int zz(TAB *a){
	if(!a) return 0;
	return resto(a->dir) && resto(a->esq);
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
