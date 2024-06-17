#include "TARVB.c"
#include <limits.h>

// sucessor de um elemento na árvore. Se o elemento for o maior da estrutura, sua
// função deve retornar INT_MAX: int suc (TARVB *a, int elem);

//sucessor considerando o filho da direita

int suc (TARVB *a, int elem){
  if(!a) return -1;
  TARVB * aux = TARVB_Busca(a, elem); //nó que guarda o elemento
  if(!aux) return -1;
  int i;
  for(i=0; i<aux->nchaves; i++){
    if(aux->chave[i] == elem) break;
  }
  if(aux->folha){
    if(i == aux->nchaves-1) return INT_MAX; // não tem ngm do lado
    if(aux->nchaves > i+1 ) return aux->chave[i+1];
  }
  if(aux->filho[i+1]){ //não tem filho da direita
    return aux->filho[i+1]->chave[0];
  }
  return INT_MAX;
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
    printf("Escolha um numero: ");
    int n;
    scanf("%d", &n);
    int sucessor = suc(arvore, n);
    printf("o sucessor do elemento escolhido eh %d \n", sucessor);

    TARVB_Libera(arvore);

    return 0;
}