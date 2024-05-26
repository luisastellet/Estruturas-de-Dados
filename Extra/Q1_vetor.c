#include "TLSE.c"
#include "TABB.c"
#include <string.h>

int tamanho (TABB * a){
    if(!a) return 0;
    return (tamanho(a->esq) + tamanho(a->dir) + 1);
}

void aux (TABB * a, int * vetor, int N, int M, int * pos){
    if(!a) return;
    aux(a->esq, vetor, N, M, pos);
    if((a->info > N) && (a->info < M)){
        vetor[(*pos)] = a->info;
        (*pos)++;
    }
    aux(a->dir, vetor, N, M, pos);
    return;
}

int * entre (TABB * a, int N, int M){
    if(!a || N==M) return NULL;
    int tam = tamanho(a);
    int pos = 0;
    int * vetor = (int*)malloc(sizeof(int)*tam);
    aux(a, vetor, N, M, &pos);
    vetor = realloc(vetor, sizeof(int)*(pos+1));

    //colocando o print aqui pra não ter que mudar os parâmetros e conseguir usar a main
    for(int i = 0; i<pos; i++){
        printf("%d ", vetor[i]);
    }
    return vetor;
}

int main(void){
    TABB *a = TABB_inicializa(); 
    int n;

    while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_insere(a, n);
    }
    TABB_imp_ident(a);

    printf("Maiores que quem? ");
    int N;
    scanf("%d", &N);
    printf("Menores que quem? ");
    int M;
    scanf("%d", &M);

    int * vetor = entre(a, N, M);
    
    TABB_libera(a);
    return 0;
} 
