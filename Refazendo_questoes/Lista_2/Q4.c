// (Q4) uma função em C que, dada uma árvore binária de busca qualquer, retorne, num vetor, todos
// os elementos menores que N. A função deve ter o seguinte protótipo: int* mN(TABB*a, int
// N);

#include "TABB.c"
#include <string.h>

int tamanho (TABB *a){
    if(!a) return 0;
    return tamanho(a->esq) + tamanho(a->dir) + 1;
}

void aux (TABB * a, int * vetor, int N, int * pos){
    if(!a) return;
    aux(a->esq, vetor, N, pos);
    if(a->info < N){
        vetor[(*pos)] = a->info;
        (*pos)++;
    }
    aux(a->dir, vetor, N, pos);
    return;
}

int * mN(TABB *a, int N){
    if(!a) return NULL;
    int tam = tamanho(a);
    int pos = 0;
    int * vetor = (int*)malloc(sizeof(int)*tam);
    aux(a, vetor, N, &pos);
    vetor = realloc(vetor, sizeof(int)*(pos));
    for(int i = 0; i<pos; i++) printf("\n%d  ", vetor[i]);
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

    int * teste = mN(a, valor);
    free(teste);

    TABB_libera(a);
    return 0;
} 
