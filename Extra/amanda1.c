//retornar em uma lista encadeada todos os elementos entre x e y
//é uma TAB

#include "TAB.c"
#include "TLSE.c"
#include <string.h>

TLSE * ins_ordenado(TLSE * l, int x){
  if(!l || (l->info > x)) return TLSE_insere(l, x);
  l->prox = ins_ordenado(l->prox, x);
  return l;
}

TLSE * aux(TAB * a, int x, int y, TLSE * l){
  if(!a) return l;
  if((a->info > x) && (a->info < y)) l = ins_ordenado(l, a->info);
  l = aux(a->esq, x, y, l);
  l = aux(a->dir, x, y, l);
  return l;
}

TLSE * entreXY (TAB * a, int x, int y){
  if(!a) return NULL;
  TLSE * l = TLSE_inicializa();
  l = aux(a, x, y, l);
  return l;
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na arvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posicao E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
    TAB_imp_ident(a);
  }while(1);
  TAB_imp_ident(a);
  
  int x, y;
  printf("entre quem? ");
  scanf("%d %d", &x, &y);

  TLSE * teste = entreXY(a, x, y);
  TLSE_imprime(teste);
  
  TAB_libera(a);
  return 0;
} 
