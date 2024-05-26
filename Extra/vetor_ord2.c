#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "TAB.c"

// pegar uma árvore TAB e criar um vetor ordenado sem criar cópia e sem alterar a original
//a função de menor terá dois parâmetros inteiros (ache um número menor que X e maior que Y por exemplo)

int tamanho(TAB * a){
    if(!a) return 0;
    return tamanho(a->esq) + tamanho(a->dir) + 1;
}

int compara (int *vet, int min){
  int resp = INT_MAX;
  for(int i = 0; i < 3; i++){
    if((vet[i] > min) && (vet[i] < resp)){
        resp = vet[i];
    }
  }
  return resp;
}

//menor que algm que vi nos nós anteriores e maior que o último elemento do vetor
int menor_maior(TAB * a, int lim_inferior, int * vet_compara){
  if(!a) return INT_MAX;
  int menorzao = a->info;
  int ver_esq = menor_maior(a->esq, lim_inferior, vet_compara);
  int ver_dir = menor_maior(a->dir, lim_inferior, vet_compara);
  vet_compara[0] = ver_esq;
  vet_compara[1] = menorzao;
  vet_compara[2] = ver_dir;
  return compara(vet_compara, lim_inferior);;
}

void resolve_tudo(TAB * a, int * vetor, int tamanho){ 
    if(!a) return;
    int menor = INT_MIN, indice = 0; //uso lim_inferior só pro while, pq se usar menor 
    int * vet_compara = (int*)malloc(sizeof(int)*3);
    while(menor != INT_MAX){ //não há ninguém maior que INT_MAX
        menor = menor_maior(a, menor, vet_compara);
        if(menor != INT_MAX){
            vetor[indice] = menor;
            indice++;
        }
        else break; //acabou a arvore
    }
    free(vet_compara);
    return;
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

  int n = tamanho(a);
  int * vetor = (int*)malloc(sizeof(int)*n);
  resolve_tudo(a, vetor, n);
  for(int i =0; i<n; i++) printf("%d  ", vetor[i]);

  free(vetor);
  TAB_libera(a);
  return 0;
}
