#include "TARVBM.c"

// cópia de uma árvore: TARVBM* copia (TARVBM *a);

TARVBM* copia (TARVBM *a){
    if(!a) return NULL;
    TARVBM * aux = TARVBM_cria(2);
    aux->nchaves = a->nchaves;
    aux->folha = a->folha;
    aux->prox = a->prox;
    for(int i=0; i<a->nchaves; i++){
        aux->chave[i] = a->chave[i];
    }
    for(int i=0; i<=a->nchaves; i++){
        aux->filho[i] = copia(a->filho[i]);
    }
    return aux;
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
    TARVBM * resp = copia(arvore);
    TARVBM_imprime(resp);

    TARVBM_libera(arvore);
    TARVBM_libera(resp);
}

