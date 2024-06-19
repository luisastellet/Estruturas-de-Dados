#include "TARVB.c"

// função em C que, dada uma árvore qualquer, retire todos os elementos pares da
// árvore original. A função deve ter o seguinte protótipo: TARVB* retira_pares
// (TARVB* a);

TARVB *retira_pares(TARVB *a){
    if(!a) return NULL;
    int i;
    for(i=0; i<a->nchaves; i++){
        a->filho[i] = retira_pares(a->filho[i]);
        if(a->chave[i] % 2 == 0){
            a = TARVB_Retira(a, a->chave[i], 2);
            i = 0;
        }
    }
    a->filho[i] = retira_pares(a->filho[i]);
    if(a->chave[i] % 2 == 0){
        a = TARVB_Retira(a, a->chave[i], 2);
        i = 0;
    }
    return a;
}


// TARVB* retira_pares (TARVB* a){
//     if(!a) return NULL;
//     int i = 0;
//     while(i < a->nchaves){
//         if(a->chave[i] % 2 == 0){
//             a = TARVB_Retira(a, a->chave[i], 2);
//         }else i += 1; //so incrementa o i se não tirou ngm, se tirou tem q ver de novo o nó
//     }
//     if(!a->folha){
//         i = 0;
//         while(i <= a->nchaves){
//             a->filho[i] = retira_pares(a->filho[i]);
//             i++;
//         }
//     }
//     return a;
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
    TARVB_Imprime(aux);

    TARVB_Libera(aux);

    return 0;
}