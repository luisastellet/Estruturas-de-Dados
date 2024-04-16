//Testar se duas árvores possuem as mesmas informações - int mi(TAB *a1, TAB *a2).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAB.c"

int tamanho (TAB * a){
    if(!a) return 0;
    int x = tamanho(a->esq);
    int y = tamanho(a->dir);
    return 1+y+x;
}

int buscando(TAB* ref, TAB* aux){
    if(!ref) return 1;
    if(!TAB_busca(aux, ref->info)) return 0;
    return buscando(ref->esq, aux) && buscando(ref->dir, aux);

    // int ver_esq = buscando(ref->esq, aux);
    // if(!ver_esq) return 0; //se já deu merda na esquerda, não preciso olhar a direita
    // int ver_dir = buscando(ref->dir, aux);
}

int mi(TAB *a, TAB *b){
    if(!a && !b) return 1;
    if(tamanho(a) != tamanho(b)) return 0;
    return buscando(a, b);
}

int main(void){
    int no1, no2, pai1, pai2;
    printf("Digite a raiz da arvore... ");
    scanf("%d", &no1);
    TAB *a1 = TAB_cria(no1, NULL, NULL), *resp1;
    char repete1, repete2;
    do{
        char lado1[2];
        printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
        scanf(" %c", &repete1);
        if((repete1 == 'N') || (repete1 == 'n')) break;
        printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
        scanf("%d%d%s", &pai1, &no1, lado1);
        resp1 = TAB_busca(a1, pai1);
        if(!resp1){
        TAB_libera(a1);
        return 0;
        }
        if(strcmp(lado1, "E") == 0) resp1->esq = TAB_cria(no1, NULL, NULL);
        else resp1->dir = TAB_cria(no1, NULL, NULL);
    }while(1);

    printf("ARVORE 2 AGORA EIN\n\n");
    printf("Digite a raiz da arvore... ");
    scanf("%d", &no2);
    TAB *a2 = TAB_cria(no2, NULL, NULL), *resp2;

    do{
        char lado2[2];
        printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
        scanf(" %c", &repete2);
        if((repete2 == 'N') || (repete2 == 'n')) break;
        printf("Digite o pai (que deve existir), o filho a ser inserido na arvore e a posição E(ESQ) ou D(DIR)... ");
        scanf("%d%d%s", &pai2, &no2, lado2);
        resp2 = TAB_busca(a2, pai2);
        if(!resp2){
        TAB_libera(a2);
        return 0;
        }
        if(strcmp(lado2, "E") == 0) resp2->esq = TAB_cria(no2, NULL, NULL);
        else resp2->dir = TAB_cria(no2, NULL, NULL);
    }while(1);

    TAB_imp_ident(a1);
    TAB_imp_ident(a2);

    int x = mi(a1, a2);
    if(x) printf("Sao iguais!");
    else printf("Nao sao iguais!");
    printf("\n");

    TAB_libera(a1);
    TAB_libera(a2);

    return 0;
}

