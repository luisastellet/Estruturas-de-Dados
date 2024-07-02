#include "TARVB.c"
#include <limits.h>

// sucessor de um elemento na árvore. Se o elemento for o maior da estrutura, sua
// função deve retornar INT_MAX: int suc (TARVB *a, int elem);

//sucessor considerando o filho da direita
//se não tivr filhp da direito, tem q ver o pai

void achar(TARVB * a, int elem, int * resp){
    if(!a) return;
    int i=0;
    while(i < a->nchaves && a->chave[i] <= elem){
        i++;
    }
    if(i < a->nchaves){
        if(a->chave[i] > elem && a->chave[i] < *resp) *resp = a->chave[i];
    }
    achar(a->filho[i], elem, resp);
    return;
}

int suc (TARVB *a, int elem){
    if(!a) return -1;
    int resp = INT_MAX;
    achar(a, elem, &resp);
    return resp;
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
        else {
          arvore = TARVB_Insere(arvore, num, t);
        }
        printf("\n\n");
    }
    printf("Escolha um numero: ");
    int n;
    scanf("%d", &n);
    int sucessor = suc(arvore, n);
    printf("o sucessor do elemento escolhido eh %d \n", sucessor);

    TARVB_Libera(arvore);

    return 0;
}