#include "TARVB.c"
#include "TLSE.c"

// função em C que, dada uma árvore qualquer, retire todos os elementos pares da
// árvore original. A função deve ter o seguinte protótipo: TARVB* retira_pares
// (TARVB* a)

TLSE * achar_pares(TARVB * a, TLSE * l){
    if(!a) return l;
    int i;
    for(i=0; i<a->nchaves; i++){
        l = achar_pares(a->filho[i], l);
        if(a->chave[i] % 2 == 0){
            l = TLSE_insere(l, a->chave[i]);
        } 
    }
    l = achar_pares(a->filho[i], l);
    return l;
}

TARVB* retira_pares (TARVB* a){
    if(!a) return NULL;
    TLSE * l = NULL;
    l = achar_pares(a, l);
    TLSE * p = l;
    TLSE_imp_rec(l);
    while(p){
        a = TARVB_Retira(a, p->info, 2);
        p = p->prox;
    }
    free(l);
    return a;
}


int main(){
    TARVB *arvore = TARVB_Inicializa();
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
        arvore = TARVB_Retira(arvore, from, t);
        TARVB_Imprime(arvore);
        }
        else if(num == -1){
        printf("\n");
        TARVB_Imprime(arvore);
        break;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore);
        }
        else arvore = TARVB_Insere(arvore, num, t);
        printf("\n\n");
    }

    TARVB *aux = retira_pares(arvore);
    printf("Arvore sem os pares:\n");
    TARVB_Imprime(aux);

    TARVB_Libera(aux);

    return 0;
}