#include "TABB.h"

void pv(TABB *a, int *resp, int *pos){
  if(!a) return;
  pv(a->esq, resp, pos);
  resp[(*pos)++] = a->info;
  pv(a->dir, resp, pos);
}

int nn(TABB *a){
  if(!a) return 0;
  return 1 + nn(a->esq) + nn(a->dir);
}

int* abb2vet(TABB *a){
  if(!a) return NULL;
  int n = nn(a), pos = 0;
  int *resp = (int *) malloc(sizeof(int) * n);
  //int resp[n]; ERRO: retorno de endereço de variávl local!
  pv(a, resp, &pos);
  return resp;
}

int main(void){
  TABB *a = TABB_inicializa(); 
  int n, cont = 0;

  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_insere(a, n);
    cont++;
  }
  TABB_imp_ident(a);

  int *resp = abb2vet(a), i;
  for(i = 0; i < cont; i++) printf("resp[%d] = %d\n", i, resp[i]);
  free(resp); 
  TABB_libera(a);
  return 0;
} 
