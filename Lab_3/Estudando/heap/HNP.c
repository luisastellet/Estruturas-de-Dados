#include <stdio.h>
#include <stdlib.h>

int pai(int pos, int qtd_filhos){
    if(pos > 0) /return (pos-1)/qtd_filhos;
    return -1;
}

int filho(int pos, int qtd_filhos, int i){
    //pos é o inidce no vetor
    //qtd_filhos é o N, quantos filhos cada nó tem
    //filho é o iésimo filho
    return pos*qtd_filhos + i;
}

void max_heapfy(int * vet, int tam, int pos, int qtd_filhos){
    int maior = pos, f;
    for(int i=1; i<=qtd_filhos; i++){
        f = filho(pos, qtd_filhos, i);
        if((f < tam) && vet[f] > vet[maior]) maior = f;
    }
    if(maior != pos){
        int tmp = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = tmp;
        max_heapfy(vet, tam, maior, qtd_filhos);
    }
}

void min_heapfy(int * vet, int tam, int pos, int qtd_filhos){
    int menor = pos, i, f;
    for(i=1; i<= qtd_filhos; i++){
        f = filho(pos, qtd_filhos, i);
        if(f < tam && vet[f] < vet[menor]) menor = f;
    }
    if(menor != pos){
        int tmp = vet[menor];
        vet[menor] = vet[pos];
        vet[pos] = tmp;
        min_heapfy(vet, tam, menor, qtd_filhos);
    }
}

void build_maxheap(int * vet, int tam, int qtd_filhos){
    int ult_pai = pai(tam-1, qtd_filhos), i;
    for(i=ult_pai; i>=0; i--){
        max_heapfy(vet, tam, i, qtd_filhos);
    }
    return;
}

void build_minheap(int * vet, int tam, int qtd_filhos){
    int ult_pai = pai(tam-1, qtd_filhos), i;
    for(i = ult_pai; i>=0; i--){
        min_heapfy(vet, tam, i, qtd_filhos);
    }
    return;
}

void heapsort(int * vet, int tam, int qtd_filhos){
    build_maxheap(vet, tam, qtd_filhos);
    int i;
    for(i=tam-1; i>0; i--){
        int tmp = vet[0];
        vet[0] = vet[i];
        vet[i] = tmp;
        max_heapfy(vet, i, 0, qtd_filhos);
    }
    return;
}

int main(void){
    int *vet, n, i = 0, qtd;
    printf("Digite o tamanho do vetor de elementos a serem ordenados... ");
    scanf("%d",&n);
    printf("Digite quantos filhos terá cada no: ");
    scanf("%d", &qtd);
    if(n <= 0) return 0;
    vet = (int *) malloc(sizeof(int) * n);

    for(i = 0; i < n; i++) vet[i] = rand() % n;

    printf("Antes de ordenar com heapsort...\n");
    for(i = 0; i < n; i++) printf("%d ", vet[i]);
    printf("\n");

    heapsort(vet, n, qtd);

    printf("Depois de ordenar com heapsort...\n");
    for(i = 0; i < n; i++) printf("%d ", vet[i]);
    printf("\n");

    free(vet);
    return 0;
}
