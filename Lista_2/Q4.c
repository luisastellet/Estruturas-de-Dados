#include "TABB.c"
#include <stdio.h>
#include <stdlib.h>

// (Q4) uma função em C que, dada uma árvore binária de busca qualquer, retorne, num vetor, todos
// os elementos menores que N. A função deve ter o seguinte protótipo: int* mN(TABB*a, int
// N);

int qtd_menores_N(TABB * a, int N){
    if(!a) return 0;
    int i_esq = qtd_menores_N(a->esq, N);
    int i_dir = qtd_menores_N(a->dir, N);
    if(a->info < N) return (1 + i_esq + i_dir);
    return (i_esq + i_dir); // é pq é maior, ai só não inclui o nó atual
    //depois tem q ver o da raiz pra somar 1
}

void preencher_vetor(TABB * a, int N, int * vetor, int* indice){
    if(!a) return;
    // printf("indice = %d\n (*indice) = %d\n &indice = %d\n\n", indice, (*indice), &indice); usado no debug
    if(a->info < N) { //OK
        vetor[(*indice)] = a->info;
        (*indice) = (*indice) + 1;
        // printf("NUMERO: %d\t", vetor[(*indice)]);
    }
    // printf("INDICE: %d\n", indice);
    preencher_vetor(a->esq, N, vetor, indice); //não passo &indice pq dentro dauqi, indice já é um endereço, só na mN que era um inteiro
    preencher_vetor(a->dir, N, vetor, indice);
    return;
}

int* mN(TABB*a, int N){
    int quantidade = qtd_menores_N(a, N);
    // printf("Voce tem %d numeros menores que %d", quantidade, N); // só pra testar se rolou a função de qtd_menores_N
    int * vetor = (int*)malloc(sizeof(int)*quantidade);
    int indice = 0;
    preencher_vetor(a, N, vetor, &indice); // mexendo com ponteiros, o valor já se altera, não precisa de retorno
    return vetor;
}

int main(void){
    TABB *a = TABB_inicializa(); 
    int n, valor;

    printf("Qual o valor de referencia? ");
    scanf("%d", &valor);

    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        a = TABB_insere(a, n);
    }
    TABB_imp_ident(a);

    int tam = qtd_menores_N(a, valor);
    int * teste = (int*)malloc(sizeof(int)*tam);
    teste = mN(a, valor);
    printf("O vetor e:");
    for(int i = 0; i<tam; i++) printf("\n%d  ", teste[i]);

    free(teste);

    TABB_libera(a);
    return 0;
    } 
