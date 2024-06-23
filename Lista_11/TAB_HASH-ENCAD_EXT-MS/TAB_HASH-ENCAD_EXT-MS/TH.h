#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
  int mat, prox, status;
  float cr;
}TA;

int TH_hash(int mat, int tam);
void TH_inicializa(char *arq, char *dados, int n);
TA* TH_busca(char *tabHash, char *dados, int n, int mat);
float TH_retira(char *tabHash, char *arq, int n, int mat);
void TH_insere(char *tabHash, char *arq, int n, int mat, float cr);
void TH_imprime (char *nome_hash, char *nome_dados, int m);
