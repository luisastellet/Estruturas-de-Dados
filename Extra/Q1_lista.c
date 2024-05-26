#include "TLSE.c"
#include "TAB.c"
#include <string.h>

TLSE * ins_ord (TLSE * l, int x){
    if(!l || (x < l->info)) return TLSE_insere(l, x);
    l->prox = ins_ord(l->prox, x);
    return l;
}

TLSE * aux (TAB * a, int N, int M, TLSE * l){
    if(!a) return l;
    if((a->info > N) && (a->info < M)) l = ins_ord(l, a->info);
    l = aux(a->esq, N, M, l);
    l = aux(a->dir, N, M, l);
    return l;
}

TLSE * entre (TAB * a, int N, int M){
    if(!a || N==M) return NULL;
    TLSE * l = TLSE_inicializa();
    l = aux(a, N, M, l);
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
    printf("\n");

    printf("Maiores que quem? ");
    int N;
    scanf("%d", &N);
    printf("Menores que quem? ");
    int M;
    scanf("%d", &M);

    TLSE * teste = entre(a, N, M);
    TLSE_imp_rec(teste);

    free(teste);
    TAB_libera(a);
    return 0;
}
