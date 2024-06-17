#include "TARVBM.c"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


// sucessor de um elemento na árvore. Se o elemento for o maior da estrutura, sua
// função deve retornar INT_MAX: int suc (TARVBM *a, int elem);

int suc (TARVBM *a, int elem){
    if(!a) return -1;
    TARVBM * aux = TARVBM_busca(a, elem);
    if(!aux) {
        printf("Não tem o elemento!");
        return INT_MAX;
    }
    for(int i =0; i< aux->nchaves; i++){
        if(aux->chave[i] == elem){
            if(i+1 < aux->nchaves) return aux->chave[i+1];
            else{
                if(aux->prox) return aux->prox->chave[0];
            }
        }
    }
    return INT_MAX;
}

int main(int argc, char *argv[]){
    TARVBM *arvore = TARVBM_inicializa();
    int t;
    printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
    scanf("%d", &t);
    if(t < 2) t = 2;
    int num = 0, from, to;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
        scanf("%d", &num);
        if(num == -9){
            scanf("%d", &from);
            arvore = TARVBM_retira(arvore, from, t);
            TARVBM_imprime(arvore);
            printf("\n\n");
        }
        else if(num == -1){
            printf("\n");
            TARVBM_imprime(arvore);
            printf("\n\n");
        }
        else if(!num){
            printf("\n");
            TARVBM_imprime(arvore);
            printf("\n\n");
        }
        else arvore = TARVBM_insere(arvore, num, t);
        printf("\n\n");
    }
    int x, resp;
    printf("Qual elemento? ");
    scanf("%d", &x);
    resp = suc(arvore, x);
    printf("\nO sucessor eh %d\n", resp);
    TARVBM_libera(arvore);
}
