#include <stdio.h>
#include <stdlib.h>

typedef struct num{
  int num;
  struct num *prox;
  int qtde;
}TNUM;

#define TAM 100
typedef TNUM * TH[TAM];

int TH_hash(int num, int tam);
void TH_inicializa(TH tab, int tam);
TNUM * TH_busca(TH tab, int tam, int num);
TNUM * TNUM_aloca(int num);
TH * TH_retira(TH tab, int tam, int num);
TH * TH_insere(TH * tab, int tam, int num);
void TH_imprime (TH tab, int tam);
TNUM * insere_aux(TNUM * a, int num);
TNUM * retira_aux(TNUM * a, int num);
void TH_libera(TH tab, int tam);