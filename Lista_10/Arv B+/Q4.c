#include "TARVBM.c"

// função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A
// função retorna um se elas são iguais e zero, caso contrário. A função deve
// obedecer ao seguinte protótipo: int igual (TARVBM* a1, TARVBM* a2);


//Como na B+ as infos só estão na base, vou analisar só a base para ver se são iguais

int igual_aux(TARVBM * a1, TARVBM * a2){
    //primeiro chego na menor folha de ambas
    while(a1->filho[0]){
        a1 = a1->filho[0];
    }
    while(a2->filho[0]){
        a2 = a2->filho[0];
    }
    while(a1){
        for(int i=0; i<a1->nchaves; i++){
            if(a1 && a2){
            if(a1->chave[i] != a2->chave[i]) return 0;
            }else return 0; //tem nó em um e não tem no outro
        }
        a1 = a1->prox;
        a2 = a2->prox;
    }
    return 1;
}

int igual (TARVBM* a1, TARVBM* a2){
    if(!a1 && !a2) return 1;
    if(!a1 || !a2) return 0;
    return igual_aux(a1, a2) && igual_aux(a2, a1);
}

int main(int argc, char *argv[]){
    TARVBM *arvore = TARVBM_inicializa();
    TARVBM *arvore2 = TARVBM_inicializa();
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
    num = 0;
    printf("Agora a segunda arvore:\n");
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
        scanf("%d", &num);
        if(num == -9){
            scanf("%d", &from);
            arvore2 = TARVBM_retira(arvore2, from, t);
            TARVBM_imprime(arvore2);
            printf("\n\n");
        }
        else if(num == -1){
            printf("\n");
            TARVBM_imprime(arvore2);
            printf("\n\n");
        }
        else if(!num){
            printf("\n");
            TARVBM_imprime(arvore2);
            printf("\n\n");
        }
        else arvore2 = TARVBM_insere(arvore2, num, t);
        printf("\n\n");
    }
    int resp = igual(arvore, arvore2);
    if(resp) printf("As arvores sao iguais !!!\n");
    else printf("As arvores NAO sao iguais :(\n");
    TARVBM_libera(arvore);
    TARVBM_libera(arvore2);
}
