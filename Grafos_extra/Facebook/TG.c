#include "TG.h"

TG* TG_inicializa(){
  return NULL;
}


void TG_imprime(TG *g){
  while(g){
    printf("Vizinhos do No %d %s:\n", g->id_no, g->nome_no);
    TVIZ *v = g->prim_viz;
    while(v){
      printf("%d %s ", v->id_viz, v->nome_viz);
      v = v->prox_viz;
    }
    printf("\n");
    g = g->prox_no;
  }
}

void TG_imp_rec(TG *g){
  if(g){
    printf("%d %s: ", g->id_no, g->nome_no);
    TVIZ *v = g->prim_viz;
    while(v){
      printf("%d %s | ", v->id_viz, v->nome_viz);
      v = v->prox_viz;
    }
    printf("\n");
    TG_imp_rec(g->prox_no);
  }
}

void TG_libera_viz(TVIZ *v){
  while(v){
    TVIZ *temp = v;
    v = v->prox_viz;
    free(temp);
  }
}

void TG_libera_viz_rec(TVIZ *v){
  if(!v) return;
  TG_libera_viz_rec(v->prox_viz);
  free(v);
}

void TG_libera(TG *g){
  while(g){
    TG_libera_viz(g->prim_viz);
    TG *temp = g;
    g = g->prox_no;
    free(temp);
  }
}

void TG_libera_rec(TG *g){
  if(g){
    TG_libera_viz(g->prim_viz);
    TG_libera_rec(g->prox_no);
    free(g);
  }
}

TG* TG_busca_no(TG* g, int x){
  if((!g) || (g->id_no == x)) return g;
  return(TG_busca_no(g->prox_no, x));
}

TVIZ* TG_busca_aresta(TG *g, int no1, int no2){
  TG *p1 = TG_busca_no(g,no1), *p2 = TG_busca_no(g,no2);
  if((!p1) || (!p2)) return NULL;
  TVIZ *resp = p1->prim_viz;
  while((resp) && (resp->id_viz != no2)) resp = resp->prox_viz;
  return resp;
}

TG* TG_ins_no(TG *g, int x, char * nome){
  TG *p = TG_busca_no(g, nome);
  if(!p){
    p = (TG*) malloc(sizeof(TG));
    p->id_no = x;
    p->prox_no = g;
    strcpy(p->nome_no, nome);
    p->prim_viz = NULL;
    g = p;
  }
  return g;
}

void TG_ins_um_sentido(TG *g, int no1, int no2, char * nome){
  TG *p = TG_busca_no(g, no1), *q = TG_busca_no(g, no2);
  if((!p) || (!q)) return;
  TVIZ *aresta = TG_busca_aresta(g, no1, no2);
  if(aresta) return;
  aresta = (TVIZ *) malloc(sizeof(TVIZ));
  aresta->id_viz = no2;
  strcpy(aresta->nome_viz, nome);
  aresta->prox_viz = p->prim_viz;
  p->prim_viz = aresta;
}

void TG_ins_aresta(TG *g, int no1, int no2, char * nome, char * nome2){
  TG_ins_um_sentido(g, no1, no2, nome2);
  TG_ins_um_sentido(g, no2, no1, nome);
}

 void TG_retira_um_sentido(TG *g, int no1, int no2){
  TG *p = TG_busca_no(g, no1);
  if(!p) return;
  TVIZ *ant = NULL, *atual = p->prim_viz;
  while((atual) && (atual->id_viz != no2)){
    ant = atual;
    atual = atual->prox_viz;
  }
  if(!atual) return;
  if(!ant) p->prim_viz = atual->prox_viz;
  else ant->prox_viz = atual->prox_viz;
  free(atual);
}

void TG_retira_aresta(TG *g, int no1, int no2){
  TG_retira_um_sentido(g, no1, no2);
  TG_retira_um_sentido(g, no2, no1);
}

TG* TG_retira_no(TG *g, int no){
  TG *p = g, *ant = NULL;
  while((p)&& (p->id_no != no)){
    ant = p;
    p = p->prox_no;
  }
  if(!p) return g;
  TVIZ *v = p->prim_viz, *t;
  while(v){
    TG_retira_um_sentido(g, v->id_viz, no);
    t = v;
    v = v->prox_viz;
    free(t);
  }
  if(!ant) g = g->prox_no;
  else ant->prox_no = p->prox_no;
  free(p);
  return g;
}
