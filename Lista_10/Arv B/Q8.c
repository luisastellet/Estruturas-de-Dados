#include "TARVB.c"

// cópia de uma árvore: TARVB* copia (TARVB *a);

TARVB* copia (TARVB *a){
    if(!a) return NULL;
    TARVB * aux = TARVB_Cria(2);
    aux ->nchaves = a->nchaves;
    aux->folha = a->folha;
    for(int i=0; i < a->nchaves; i++){ //chaves precisa ser apenas <
        aux->chave[i] = a->chave[i];
    }
    for(int i=0; i <= a->nchaves; i++){ //filhos precisa ser <= porque temos 1 a mais
        aux->filho[i] = copia(a->filho[i]);
    }
    return aux;
}

int main(){
    TARVB *arvore = TARVB_Inicializa();
    int t;
    printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
    scanf("%d", &t);
    if(t < 2) t = 2;
    int num = 0, from, to;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -1 para sair\n");
        scanf("%d", &num);
        if(num == -1){
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

    TARVB *b = NULL;
    b = copia(arvore);

    printf("arvore original: \n");
    TARVB_Imprime(arvore);

    printf("arvore copiada: \n");
    TARVB_Imprime(b);

    TARVB_Libera(arvore);
    TARVB_Libera(b);

    return 0;
}