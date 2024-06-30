// (Q1) Uma função em C que, dada uma árvore B qualquer, retorne, numa lista, todos
// os elementos maiores que N. A função deve ter o seguinte protótipo: 
// TLSE* mN(TARVB*a, int N);

// tem a->nchaves filho
// tem a->nchaves - 1 chave

#include "TARVB.c"
#include "TLSE.c"

TLSE * aux(TARVB * a, int N, TLSE * l){
    if(!a) return l;
    int i;
    for(i=0; i<a->nchaves; i++){ //chaves
        if(a->chave[i] > N){
            l = TLSE_insere(l, a->chave[i]);
        } 
    }
    for(i=0; i<=a->nchaves; i++){ //filhos
        l = aux(a->filho[i], N, l);
    }
    return l;
}

TLSE * mN (TARVB *a, int N){
    if(!a) return NULL;
    TLSE * lista = NULL;
    lista = aux(a, N, lista);
    return lista;
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
        // TARVB_Libera(arvore);
        // return 0;
        break;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore);
        }
        else arvore = TARVB_Insere(arvore, num, t);
        printf("\n\n");
    }
    TLSE * l = NULL;
    int n;
    printf("Qual o valor de N? ");
    scanf("%d", &n);
    l = mN(arvore, n);
    TLSE_imprime(l);

    TARVB_Libera(arvore);

    return 0;
}