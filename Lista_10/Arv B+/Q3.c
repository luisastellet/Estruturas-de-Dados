#include "TARVBM.c"

// menor elemento da árvore: TARVBM* menor(TARVBM *a);

TARVBM* menor(TARVBM *a){
    if(!a) return NULL;
    if(a->folha) return a;
    while(a->filho[0]){
        a = a->filho[0];
    }
    return a;
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
    TARVBM * resp = menor(arvore);
    printf("\nO menor eh %d\n", resp->chave[0]);
    //se considerar que não posso fazer esse print assim na main, só colocar ele na função
    //mas como o retorno foi o nó, julguei que a main seria assim
    TARVBM_libera(arvore);
}
