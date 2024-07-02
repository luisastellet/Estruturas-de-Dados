#include <stdio.h>
#include <stdlib.h>

int pai(int pos){
    if(pos > 0) return (pos-1)/3;
    return -1;
}

int filho1(int pos){
    return pos*3 + 1;
}

int filho2(int pos){
    return pos*3 + 2;
}

int filho3(int pos){
    return pos*3 + 3;

}

void max_heapfy(int * vet, int n, int pos){
    int maior = pos, f1 = filho1(pos), f2 = filho2(pos), f3 = filho3(pos);
    if(f1 < n && vet[f1] > vet[maior]) maior = f1;
    if(f2 < n && vet[f2] > vet[maior]) maior = f2;
    if(f3 < n && vet[f3] > vet[maior]) maior = f3;
    if(maior != pos){
        int tmp = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = tmp;
        max_heapfy(vet, n, maior);
    }
    return;
}

void build_maxheap(int * vet, int n){
    int ult_pai = pai(n-1);
    int i;
    for(i = ult_pai; i>=0; i--){
        max_heapfy(vet, n, i);
    }
    return;
}

void heapsort(int * vet, int n){
    build_maxheap(vet, n);
    int i;
    for(i = n-1; i>0; i--){
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
