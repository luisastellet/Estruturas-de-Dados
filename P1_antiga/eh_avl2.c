// Descubra se uma TAB é AVL ou não

#include "TAB.c"
#include <string.h>
#include <limits.h>


int altura(TAB *a){
  if(!a) return 0;
  int ver_esq = altura(a->esq);
  int ver_dir = altura(a->dir); 
  if(ver_esq >= ver_dir) return ver_esq + 1;
  return ver_dir + 1;
}

int fb(TAB * a){
    int resp = altura(a->esq) - altura(a->dir);
    if(resp < -1 || resp > 1) return 0;
    return 1;
}

int eh_avl_aux (TAB * a){
  if(!a) return 1;
  if(!fb(a)) return 0; //o fb não prestou (deu 0)
  int r_esq = eh_avl_aux(a->esq);
  int r_dir = eh_avl_aux(a->dir);
  return r_esq && r_dir;
}

int eh_TABB (TAB * a){
  if(!a) return 1;
  if(a->esq && (a->esq->info > a->info)) return 0; //se o da esquerda for maior
  if(a->dir && (a->dir->info < a->info)) return 0; //se o da direita for maior
  int r_esq = eh_TABB(a->esq);
  int r_dir = eh_TABB(a->dir);
  return r_esq && r_dir;
}

int eh_avl (TAB *a){
  if(!a) return 1;
  if(eh_avl_aux(a) && eh_TABB(a)) return 1; //precisa ter resp=1 e precisa ser TABB
  return 0;
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
  int teste = eh_avl(a);
  if(teste) printf("Essa TAB eh uma AVL!!!");
  else printf("Essa TAB NAO eh uma AVL :(");
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
