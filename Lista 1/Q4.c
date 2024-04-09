#include "TAB.c"
#include <stdio.h>
#include <string.h>
#include <stdio.h>

//(Q4) menor elemento da árvore: TAB* maior(TAB *a);


TAB *TAB_menor(TAB *a){
  if(!a) return a;
  TAB *menor_esq = TAB_menor(a->esq);
  TAB *menor_dir = TAB_menor(a->dir);
  TAB *resp = a;
  if((menor_esq) && (menor_esq->info < resp->info)) resp = menor_esq;
  if((menor_dir) && (menor_dir->info < resp->info)) resp = menor_dir;
  return resp;
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
  TAB * teste = TAB_menor(a);
  printf("O menor e -> %d", teste->info);
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
