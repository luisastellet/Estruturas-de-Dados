// (Q9) ache a quantidade de nós folha: int nf(TAB *a);

#include "TAB.c"
#include <string.h>

int nf (TAB *a){
  if(!a) return 0;
  if(!a->esq && !a->dir) return 1;
  return ni(a->esq) + ni(a->dir);
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
  int x = nf(a);
  printf("\n %d nos folha", x);
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
