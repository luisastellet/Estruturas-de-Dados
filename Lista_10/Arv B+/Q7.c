#include "TARVBM.c"

// quantidade de nós folha: int nf(TARVBM *a);

int nf(TARVBM *a){
    if(!a || a->folha) return 0;
    int cont=0; 
    while(a->filho[0]){ //chegando no primeiro nó folha
        a = a->filho[0];
    }
    //percorrendo os nós folhas
    while(a){
        cont++;
        a = a->prox;
    }
    return cont;
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
    int resp = nf(arvore);
    printf("\nO numero de nos folha eh %d\n", resp);
    TARVBM_libera(arvore);
}
