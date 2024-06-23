#include "TARVBM.c"
#include "TLSE.c"

// função em C que, dada uma árvore qualquer, retire todos os elementos pares da
// árvore original. A função deve ter o seguinte protótipo: TARVBM* retira_pares
// (TARVBM* a);

void achar_pares(TARVBM * a, TLSE ** l){
    if(!a) return;
    int i;
    for(i=0; i<a->nchaves; i++){
        achar_pares(a->filho[i], l);
        if((a->folha) && (a->chave[i] % 2 == 0)){
            (*l) = TLSE_insere((*l), a->chave[i]);
        } 
    }
    achar_pares(a->filho[i], l);
    return;
}

TARVBM * retira_pares (TARVBM * a){
    if(!a) return NULL;
    TLSE * l = NULL;
    achar_pares(a, &l);
    TLSE * p = l;
    TLSE_imp_rec(l);
    while(p){
        a = TARVBM_retira(a, p->info, 2);
        p = p->prox;
    }
    free(l);
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
    TARVBM * resp = retira_pares(arvore);
    printf("A arvore sem pares: \n");
    TARVBM_imprime(arvore);
    //se considerar que não posso fazer esse print assim na main, só colocar ele na função
    //mas como o retorno foi o nó, julguei que a main seria assim
    TARVBM_libera(arvore);
}