// (Q5) Refaça (Q4) para memória principal, recebendo no lugar de nome de arquivo, 
// um vetor e seu tamanho (isto é, int *vet, int n).

#include "../THMP.c"

void uniao(int *vet1, int *vet2, int n){
    TH * tab = (TH*)malloc();
    printf("Qual o tamanho da hash? ");
    int tam;
    scanf("%d", &tam);
    TH_inicializa(*tab, tam);
    for(int i=0; i<n; i++){
        *tab = TH_insere(&tab, tam, vet1[i]);
    }
    
}

int main(void){
    int * vet1 = {1, 2, 3, 4, 10, 11};
    int * vet2 = {5, 6, 7, 3, 8, 2};
    uniao(vet1, vet2, 6);
    return 0;
}