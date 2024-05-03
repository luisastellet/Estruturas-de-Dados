#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "TG.c"

//(Q2) ache a quantidade de arestas: int na(TG *g)
// GRAFO NÃO ORIENTADO

int na_nao_orientado(TG *g){
    int resp = 0;
    TG * p_no = g;
    while(p_no){
        TVIZ * p_viz = p_no->prim_viz;
        while(p_viz){
            resp++;
            p_viz = p_viz->prox_viz;
        }
        p_no = p_no->prox_no;
    }
    return (resp/2);
}

//GRAFO ORIENTADO

int na_orientado(TG *g){
    int resp = 0;
    TG * p_no = g;
    while(p_no){
        TVIZ * p_viz = p_no->prim_viz;
        while(p_viz){
            resp++;
            p_viz = p_viz->prox_viz;
        }
        p_no = p_no->prox_no;
    }
    return resp;
}

int main(void){
  TG *g = TG_inicializa();
  int n;
  printf("Os nos: ");
  do{
    scanf("%d", &n);
    if(n <= 0) break;
    g = TG_ins_no(g, n);
  }while(1);
  
  printf("As relacoes: ");
  int m;
  do{
    scanf("%d%d", &n, &m);
    if((n <= 0) || (m <= 0)) break;
    TG_ins_aresta(g, n, m);
  }while(1);
  printf("\n");
  TG_imprime(g);
  
  int resp = na_nao_orientado(g);
//int resp = na_orientado(g);

  printf("O grafo tem %d arestas", resp);
  TG_libera(g);
  return 0;
}

