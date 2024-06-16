#include "TARVB.c"

// maior elemento da árvore: TARVB* maior(TARVB *a);

TARVB* maior(TARVB *a){
    if(!a) return NULL;
    TARVB * resp = maior(a->filho[a->nchaves]);
    if(!resp) return a;
    if(a->chave[a->nchaves-1] > resp->chave[resp->nchaves-1]) return a;
    return resp;
}

// TARVB *maior(TARVB *a){
//     if(!a) return a;
//     if(a->folha) return a;
//     return maior(a->filho[a->nchaves]);
// }


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

    TARVB *aux = maior(arvore);
    printf("Maior:\n");
    TARVB_Imprime(aux);

    TARVB_Libera(arvore);
    TARVB_Libera(aux);

    return 0;
}