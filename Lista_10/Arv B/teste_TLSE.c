#include "TLSE.h"

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  TLSE_imprime(l);
  printf("\n");

  return 0;
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_insere(l, x);
  }while(1);
  printf("A lista original: ");
  TLSE_imprime(l);
  printf("\n");

  printf("Agora o resultado da funcao criada: ");
  //TLSE_imprime(CHAMAR A FUNÇÃO AQUI);
  TLSE_libera(l);

  return 0;
}

//duas listas
int main(void){
    TLSE *l1 = TLSE_inicializa();
    TLSE *l2 = TLSE_inicializa();

    int x;
    printf("Preencha a lista 2: ");
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l1 = TLSE_insere(l1, x);
    }while(1);

    printf("Preencha a lista 2: ");
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l2 = TLSE_insere(l2, x);
    }while(1);
    
    printf("A lista 1: ");
    TLSE_imprime(l1);
    printf("\n");
    printf("A lista 2: ");
    TLSE_imprime(l2);
    printf("\n");

    printf("Agora o resultado da funcao criada: ");
    printf("*** %d ***", igual(l1, l2));
    TLSE_libera(l1);
    TLSE_libera(l2);
    return 0;
}