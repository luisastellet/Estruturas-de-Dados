#include "TARVB.c"

// função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A
// função retorna um se elas são iguais e zero, caso contrário. A função deve
// obedecer ao seguinte protótipo: int igual (TARVB* a1, TARVB* a2);

void igual_aux(TARVB * a1, TARVB * a2, int * resp){
    if(!a1) return;
    if((a1->nchaves != a2->nchaves) || (a1->folha != a2->folha)){
        (*resp) = 0;
        return;
    }
    for(int i = 0; i<a1->nchaves; i++){
        if(a1->chave[i] != a2->chave[i]){
            (*resp) = 0;
            return;
        }
    }
    for(int i = 0; i<=a1->nchaves; i++){
        igual_aux(a1->filho[i], a2->filho[i], resp);
    }
    return;
}

int igual (TARVB* a1, TARVB* a2){
    if(!a1 && !a2)  return 1;
    if(!a1 || !a2) return 0;
    int resp1 = 1, resp2 = 1;
    igual_aux(a1, a2, &resp1);
    igual_aux(a2, a2, &resp2);
    return resp1 && resp2;
}

int main(){
    TARVB *arvore1 = TARVB_Inicializa();
    TARVB *arvore2 = TARVB_Inicializa();
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
        TARVB_Imprime(arvore1);
        // TARVB_Libera(arvore1);
        // return 0;
        break;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore1);
        }
        else arvore1 = TARVB_Insere(arvore1, num, t);
        printf("\n\n");
    }
    printf("Agora a segunda arvore: \n");
    num = 0;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -1 para sair\n");
        scanf("%d", &num);
        if(num == -1){
        printf("\n");
        TARVB_Imprime(arvore2);
        // TARVB_Libera(arvore2);
        // return 0;
        break;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore2);
        }
        else arvore2 = TARVB_Insere(arvore2, num, t);
        printf("\n\n");
    }

    int x = igual(arvore1, arvore2);
    if(x) printf("As arvores sao iguais!!!\n");
    else printf("As arvores NAO sao iguais :(\n");

    TARVB_Libera(arvore1);
    TARVB_Libera(arvore2);

    return 0;
}