//(Q7) se esta estrutura TAB_cor tivesse um campo cor (int cor), defina uma função em C que, ao
// receber uma árvore binária “sem cor” e totalmente balanceada (isto é, a distância da raiz a qualquer
// folha da árvore é sempre a mesma), retorne esta árvore com os nós coloridos somente de vermelho e
// preto, sendo que o nó pai NUNCA pode ter a mesma cor de seus filhos. A função deve possuir o
// seguinte protótipo: void colore (TAB_cor* arv);

// #include "TAB.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct arvore{
    struct arvore * dir, * esq;
    int info;
    char cor;
}TAB_cor;

TAB_cor *TAB_cor_cria(int raiz, TAB_cor *esq, TAB_cor *dir){
  TAB_cor *novo = (TAB_cor *) malloc(sizeof(TAB_cor));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  novo->cor = 'B';
  return novo;
}

TAB_cor *TAB_cor_busca(TAB_cor *a, int elem){
  if((!a) || (a->info == elem)) return a;
  TAB_cor *resp = TAB_cor_busca(a->esq, elem);
  if(resp) return resp;
  return TAB_cor_busca(a->dir, elem);
}

void TAB_cor_libera(TAB_cor *a){
  if(a){
    TAB_cor_libera(a->esq);
    TAB_cor_libera(a->dir);
    free(a);
  }
}

void imp_cor_aux(TAB_cor *a, int andar){
  int j;
  if(a){
    imp_cor_aux(a->dir, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d:%c\n", a->info, a->cor);
    imp_cor_aux(a->esq, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_cor_imp_ident(TAB_cor *a){
  imp_cor_aux(a, 0);
}

void colore (TAB_cor* a){
    if(!a) return; //NULL não tem seta cor
    if(a->cor == 'B'){
        a->cor = 'V';
        if(a->dir) a->dir->cor = 'P';
        if(a->esq) a->esq->cor = 'P';

    }else if(a->cor == 'V'){
        if(a->dir) a->dir->cor = 'P';
        if(a->esq) a->esq->cor = 'P';

    }else{ //se for preto
        if(a->dir) a->dir->cor = 'V';
        if(a->esq) a->esq->cor = 'V';
    }
    colore(a->esq);
    colore(a->dir);
    return;

}



int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB_cor *a = TAB_cor_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_cor_busca(a, pai);
    if(!resp){
      TAB_cor_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cor_cria(no, NULL, NULL);
    else resp->dir = TAB_cor_cria(no, NULL, NULL);
  }while(1);
  TAB_cor_imp_ident(a);
  colore(a);
  printf("\nRESPOSTA\n");
  TAB_cor_imp_ident(a);
  printf("\n");
  
  TAB_cor_libera(a);
  return 0;
}
