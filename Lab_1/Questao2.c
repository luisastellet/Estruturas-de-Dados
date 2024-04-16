#include <stdio.h>
#include <stdlib.h>
#include "TAB.h"

// Testar se uma árvore é zigue-zague, isto é, todos os nós internos, exceto a raiz, 
//possuem exatamente uma sub-árvore vazia - int zz(TAB *a);

int resto(TAB *a){
	if(!a) return  1;
	if((a->esq && a->dir)) return 0; //n é zif za 2 filhos
	int ver_esq = resto(a->esq);
	int ver_dir = resto(a->dir);
	if(!ver_esq || !ver_dir) return 0;
	return 1;	
}

int zz(TAB *a){
	if(!a) return 0;
	return resto(a->dir);
}
