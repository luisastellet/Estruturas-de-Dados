#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TAB.c"
#include "TLSE.c"

//usando função insere ordenado na lista final

// USANDO SÓ PONTEIRO

TLSE * insere_ordenado(TLSE * l, int x){
  if((!l) || (l->info > x)) return TLSE_insere(l, x);
  l -> prox = insere_ordenado(l->prox, x); //sei que na TAB não tem elemento igual
  return l;
}

TLSE * percorre_arvore (TAB * a, TLSE * lista){
  if(!a) return lista;
  lista = insere_ordenado(lista, a->info);
  lista = percorre_arvore(a->esq, lista);
  lista = percorre_arvore(a->dir, lista);
  return lista;
}

TLSE * lista_ord (TAB * a){
  if(!a) return NULL;
  TLSE * lista = TLSE_inicializa(); 
  lista = percorre_arvore(a, lista);
  return lista;
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
  TLSE * teste = lista_ord(a);
  printf("lista: ");
  TLSE_imprime(teste);
  printf("\n");
  
  free(teste);
  TAB_libera(a);
  return 0;
}
