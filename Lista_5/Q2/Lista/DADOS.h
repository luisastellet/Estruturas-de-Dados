#include <stdio.h>
#include <stdlib.h>

typedef struct Q2
{
  float nota1;
  float nota2;
  float media;
  char nome[31];
  struct Q2 * prox; 
} DADOS;

DADOS * DADOS_inicializa(void);
DADOS* DADOS_insere(DADOS *l, int media);
void DADOS_imprime(DADOS *l);
void DADOS_libera(DADOS *l);
DADOS* DADOS_retira(DADOS *l, int media);
DADOS* DADOS_busca(DADOS *l, int media);

void DADOS_imp_rec(DADOS *l);
void DADOS_imp_rec_rev(DADOS *l);
void DADOS_lib_rec(DADOS *l);
DADOS* DADOS_busca_rec(DADOS *l, int media);
DADOS* DADOS_retira_rec(DADOS *l, int media);

