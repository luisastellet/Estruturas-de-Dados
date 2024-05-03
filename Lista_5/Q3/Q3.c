#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q3) Escreva um procedimento que receba o nome de um arquivo texto, cujo conteúdo são valores
// inteiros e imprima na tela o número de vezes que cada elemento aparece e em quais linhas – void
// resumo(char *Arq).

typedef struct lista{
  int numero;
  int cont;
  struct lista * prox;
}TLSE;

int ja_foi(TLSE * l, int x){ // se for 1, achou, se for 0 não achou
  TLSE * p = l;
  int ver = 0;
  while(p){
    if(p->numero == x) ver = 1;
    p = p->prox;
  }
  return ver;
}

void libera(TLSE * l){
  if(!l) return;
  libera(l->prox);
  free(l);
  return;
}

TLSE * insere(TLSE * lista, int x, int cont){
  TLSE * novo = (TLSE*)malloc(sizeof(TLSE));
  novo->cont = cont;
  novo->numero = x;
  novo->prox = lista;
  lista = novo;
  return lista;
}

void resumo(char *Arq){
  FILE *fp = fopen(Arq, "r");
  FILE *aux = fopen(Arq, "r");
  if (!fp || !aux) exit(1);
  TLSE * lista = NULL;
  int linhas=0, r, referencia, valor;

  while(fscanf(fp, "%d", &referencia) == 1){ //vendo o tamanho de linhas pra usar no for
    linhas++;
  }
  rewind(fp); //subindo o cursor

  for(int i = 1; i<=linhas; i++){ //irá ver cada linha principal
    if(fscanf(fp, "%d", &referencia) == 1){
      if(!ja_foi(lista, referencia)){ //não foi ainda
        lista = insere(lista, referencia, 0);

        rewind(aux);
        for(int j = 1; j<=linhas; j++){ //irá ver as linhas se batem com a linha principal
          fscanf(aux, "%d", &valor);
          if(valor == referencia){
            (lista->cont)++;
            printf("%d aparece na linha %d\n", referencia, j);
          }
        }
        printf("\tO numero %d aparece %d vez(es).\n\n", referencia, lista->cont);
      }else continue;
    }else break;
  }

  fclose(fp);
  fclose(aux);
  libera(lista);

  return;
}

int main () {

  resumo("entrada-Q3");

  return 0;
}