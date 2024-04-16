#include "TABB.c"
#include "TLSE.c"
#include <stdio.h>
#include <stdlib.h>

//Retornar todos os ancestrais de um nó na árvore de busca binária, da raiz da árvore até o elemento passado como parâmetro, usando a biblioteca de lista encadeada - TLSE* ancestrais(TABB *a, int elem);

//    Vai colocando enquanto desce, então fica ao contrário
//    Ai na outra função deveria inserir o primeiro antes de chamar a recursão
// TLSE * insere_ancestrais(int elem, TLSE * lista, TABB * a){
//   if(!a) return lista;
//   lista = TLSE_insere(lista, a->info);
//   if(elem > a->info) lista = insere_ancestrais(elem, lista, a->dir);	
//   else if(elem < a->info) lista = insere_ancestrais(elem, lista, a->esq);
//   return lista;
// }

//    Desce tudo e coloca, então fica na ordem
//    Ai na outra função tem q colocar por ultimo, depois de chamara  recursão
TLSE * insere_ancestrais(int elem, TLSE * lista, TABB * a){
  if(!a) return lista;
  if(a->info != elem){
    if(elem > a->info) lista = insere_ancestrais(elem, lista, a->dir);
    else if(elem < a->info) lista = insere_ancestrais(elem, lista, a->esq);
  }
  return TLSE_insere(lista, a->info);
}

TLSE * ancestrais(TABB *a, int elem){
	TLSE * lista = TLSE_inicializa();
	if(TABB_busca(a, elem)){
		if(elem > a->info) lista = insere_ancestrais(elem, lista, a->dir); //se o elemento ta la, chamo
		if(elem < a->info) lista = insere_ancestrais(elem, lista, a->esq);
		lista = TLSE_insere(lista, a->info);
	}
	return lista;
}


int main(void){
  TABB *a = TABB_inicializa(); 
  int n;

  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_insere(a, n);
  }
  TABB_imp_ident(a);
  
  int elem;
  printf("qual elem? ");
  scanf("%d", &elem);

  TLSE * teste = ancestrais(a, elem);
  TLSE_imprime(teste);
  
  TABB_libera(a);
  return 0;
} 
