#include <stdio.h>
#include <stdlib.h>

int pai(int pos){
    if(pos > 0) return (pos-1)/2;
    return -1;
}

int esq(int pos){
    return 2*pos + 1;
}

int dir(int pos){
    return 2*pos + 2;
}

void max_heapfy(int * vet, int n, int pos){ //n é o tamanho do vet e pos é o indice que está ruim
    int maior = pos, e = esq(pos), d = dir(pos);
    if((e < n) && vet[e] > vet[maior]) maior = e;
    if((d < n) && vet[d] > vet[maior]) maior = d;
    if(maior != pos){
        int tmp = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = tmp;
        max_heapfy(vet, n, maior);
    }
    return;
}

void min_heapfy(int * vet, int n, int pos){
    int menor = pos, e = esq(pos), d = dir(pos);
    if((e < n) && (vet[e] < vet[menor])) menor = e;
    if((d < n) && (vet[d] < vet[menor])) menor = d;
    if(menor != pos){
        int tmp = vet[menor];
        vet[menor] = vet[pos];
        vet[pos] = tmp;
        min_heapfy(vet, n, menor);
    }
    return;
}

void build_maxheap(int * vet, int n){
    int ult_pai = pai(n-1), i;
    for(i = ult_pai; i>=0; i--){
        max_heapfy(vet, n, i);
    }
    return;
}

void build_minheap(int * vet, int n){
    int ult_pai = pai(n-1), i;
    for(i=ult_pai; i>=0; i--){
        min_heapfy(vet, n, i);
    }
    return;
}

void heapsort(int * vet, int n){
    build_maxheap(vet, n);
    int i;
    for(i=n-1; i>0; i--){
        int tmp = vet[0];
        vet[0] = vet[i];
        vet[i] = tmp;
        max_heapfy(vet, i, 0);
    }
    return;
}

int main(void){
  int *vet, n, i = 0;
  printf("Digite o tamanho do vetor de elementos a serem ordenados... ");
  scanf("%d",&n);
  if(n <= 0) return 0;
  vet = (int *) malloc(sizeof(int) * n);

  for(i = 0; i < n; i++) vet[i] = rand() % n;
 
  printf("Antes de ordenar com heapsort...\n");
  for(i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  heapsort(vet, n);

  printf("Depois de ordenar com heapsort...\n");
  for(i = 0; i < n; i++) printf("%d ", vet[i]);
  printf("\n");

  free(vet);
  return 0;
}
