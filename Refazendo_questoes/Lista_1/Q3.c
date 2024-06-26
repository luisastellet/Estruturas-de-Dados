// (Q3) maior elemento da árvore: TAB* maior(TAB *a);
#include "TAB.c"
#include <string.h>

TAB * maior (TAB * a){
  if(!a) return a;
  TAB * m_esq = maior(a->esq);
  TAB * m_dir = maior(a->dir);
  TAB * resp = a;
  if((m_esq) && (m_esq->info > resp->info)) return m_esq;
  else if ((m_dir) && (m_dir->info > resp->info)) return m_dir;
  return resp;
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
  TAB * teste = maior(a);
  printf("  %d  ", teste->info);
  printf("\n");
  
  TAB_libera(a);
  return 0;
}
