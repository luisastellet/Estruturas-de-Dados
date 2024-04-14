#include "TAB.c"
#include <stdio.h>
#include <string.h>
#include <stdio.h>

//(Q1) cópia de uma árvore: TAB* copia (TAB *a);


// TAB* copia (TAB *a){
//     TAB *aux = TAB_inicializa();
//     if(!a) return a;
//     //jeito mais fácil de entender
//     TAB * x = copia(a->esq);
//     TAB * y = copia(a->dir);
//     aux = TAB_cria(a->info, x, y);
//     return aux;

//     //jeito mais complexo, mas que entendi depois
//     // aux = TAB_cria(a->info, copia(a->esq), copia(a->dir));
//     // return aux;
// }

TAB* copia (TAB *a){
  TAB *aux = TAB_inicializa();
  if(!a) return a;
  //jeito mais fácil de entender
  aux = TAB_cria(a->info, NULL, NULL);
  aux->esq = copia(a->esq);
  aux->dir = copia(a->dir);
  return aux;
}


int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  TAB * teste = copia(a);
  TAB_imp_ident(teste);
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
