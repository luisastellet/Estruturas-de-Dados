#include "TARVB.c"

// quantidade de nós internos: int ni(TARVB *a);

void ni_aux(TARVB * a, int * cont){
    if(!a) return;
    if(a->folha){
        return;
    }
    for(int i =0; i<=a->nchaves; i++){
        ni_aux(a->filho[i], cont);
    }
    (*cont)++;
    return;

}

int ni(TARVB *a){
    if(!a) return 0;
    if(a->folha) return 1;
    int cont=0;
    ni_aux(a, &cont);
    return cont;
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

    printf("nos internos: %d \n", ni(arvore));

    TARVB_Libera(arvore);

    return 0;
}