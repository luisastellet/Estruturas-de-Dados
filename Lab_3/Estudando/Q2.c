// (Q2) Retornar todas as informações ancestrais de um nó na árvore B, da raiz da 
// árvore até o elemento passado como parâmetro, usando a biblioteca de 
// lista encadeada - TLSEINT* misc(TARVB *a, int elem), onde:

// typedef struct lseint{
//   int lim_inf, lim_sup;
//   struct lseint *prox;
// } TLSEINT;

#include "../TLSEINT.c"
#include "../TARVB.c"
#include <limits.h>

TLSEINT * aux(TARVB * a, int elem, TLSEINT * l){
    if (!a) return l;
    int i;
    int menor = INT_MIN, maior = INT_MIN;
    for(i=0; i<a->nchaves; i++){
        if(a->chave[i] < elem) continue;
        l = aux(a->filho[i], elem, l);
        if(a->chave[i] == elem){
            if(i-1 >= 0) menor = a->chave[i-1];
            if(i+1 < a->nchaves) maior = a->chave[i+1];
            l = TLSEINT_insere(l, menor, maior);
            return l;
        }
    }
    l = aux(a->filho[i], elem, l);
    menor = INT_MIN, maior = INT_MIN;
    for(i=0; i<a->nchaves; i++){
        if(a->chave[i] < elem) continue;
        if(i-1 >= 0) menor = a->chave[i-1];
        if(i+1 < a->nchaves) maior = a->chave[i+1];
        l = TLSEINT_insere(l, menor, maior);
        
    }
    return l;
}

TLSEINT* misc(TARVB *a, int elem){
    if(!a) return NULL;
    TLSEINT * l = NULL;
    l = aux(a, elem, l);
    return l;
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
    TLSEINT * l = NULL;
    int x;
    printf("Qual elemento quer achar? ");
    scanf("%d", &x);
    l = misc(arvore, x);
    TLSEINT_imprime(l);
    TLSEINT_libera(l);
    TARVB_Libera(arvore);

    return 0;
}