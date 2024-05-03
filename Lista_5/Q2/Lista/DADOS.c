#include "DADOS.h"

DADOS * DADOS_inicializa(void){
  return NULL;
}

DADOS* DADOS_insere(DADOS *l, int media){
  DADOS *novo = (DADOS *) malloc(sizeof(DADOS));
  novo->prox = l;
  novo->media = media;
  return novo;
}

void DADOS_imprime(DADOS *l){
  DADOS *p = l;
  while(p){
    printf("%f ", p->media);
    p = p->prox;
  } 
}

void DADOS_imp_rec(DADOS *l){
  if(l){
    printf("%f ", l->media);
    DADOS_imp_rec(l->prox);
  }
}

void DADOS_imp_rec_rev(DADOS *l){
  if(l){
    DADOS_imp_rec_rev(l->prox);
    printf("%f ", l->media);
  }
}

void DADOS_libera(DADOS *l){
  DADOS *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

void DADOS_lib_rec(DADOS *l){
  if(l){
    DADOS_lib_rec(l->prox);
    printf("liberando o mediaento %f...\n", l->media);
    free(l);
  }
}

DADOS* DADOS_retira(DADOS *l, int media){
  DADOS *p = l, *ant = NULL;
  while((p) && (p->media != media)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

DADOS* DADOS_retira_rec(DADOS *l, int media){
  if(!l) return l;
  if(l->media == media){
    DADOS *p = l;
    l = l->prox;
    free(p);
  }
  else l->prox = DADOS_retira_rec(l->prox, media);
  return l;
}

DADOS* DADOS_busca(DADOS *l, int media){
  DADOS *p = l;
  while((p) && (p->media != media)) p = p->prox; 
  return p;
}

DADOS* DADOS_busca_rec(DADOS *l, int media){
  if((!l) || (l->media == media)) return l;
  return DADOS_busca_rec(l->prox, media);
}

