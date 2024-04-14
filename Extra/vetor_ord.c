#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "TAB.c"

//usando uma copia e retirando cada no depois de achar o menor


int contador(TAB * a){
    if(!a) return 0;
    return contador(a->esq) + contador(a->dir) + 1;
    // int x = contador(a->esq);
    // int y = contador(a->dir);
    // return x+y+1;
}

TAB * copia(TAB * a, TAB * copy){
    if(!a) return a;
    copy = TAB_cria(a->info, NULL, NULL);
    copy->esq = copia(a->esq, copy->esq);
    copy->dir = copia(a->dir, copy->dir);
    return copy;
}

TAB * menor(TAB * a){
    if(!a) return a;
    TAB * menor_esq = menor(a->esq);
    TAB * menor_dir = menor(a->dir);
    TAB * resp = a;
    if((menor_esq) && (menor_esq->info < resp->info)) resp = menor_esq;
    if((menor_dir) && (menor_dir->info < resp->info)) resp = menor_dir;
    return resp;
}

void resolve_tudo(TAB * a, TAB * copy, int * vetor){
    int pos = 0;
    TAB * atual = NULL;
    while(copy){
        atual = menor(copy);
        if(atual->info == INT_MAX) break;
        vetor[pos] = atual->info;
        pos++;
        atual->info = INT_MAX;
    }
    TAB_libera(copy);
    return;
}

int * vetor_ord (TAB * a){
    int qtd = contador(a);
    int * vetor = (int*)malloc(sizeof(int)*qtd);
    TAB * copy = TAB_inicializa();
    copy = copia(a, copy);
    resolve_tudo(a, copy, vetor);
    return vetor;
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

  int * vetor = vetor_ord(a);
  int n = contador(a);
  for(int i =0; i<n; i++) printf("%d  ", vetor[i]);

  free(vetor);
  TAB_libera(a);
  return 0;
}
