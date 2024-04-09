#include <stdio.h>
#include <stdlib.h>

//não fiz pra genéria, fiz para relembrar as antigas

typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE * TLSE_inicializa(void){
    return NULL;
}

TLSE * TLSE_ins_ini(TLSE * l, int x){
    TLSE * novo = (TLSE*)malloc(sizeof(TLSE));
    novo->prox = l;
    l = novo;
    novo->info = x;
    return l;
}

TLSE * TLSE_ins_fim(TLSE * l, int x){
    if(!l) return TLSE_ins_ini(l, x);
    l->prox = TLSE_ins_fim(l->prox, x);
    return l;
}

TLSE * TLSE_retira(TLSE * l, int x){
    if(!l) return l;
    if(l->info != x) l->prox = TLSE_retira(l->prox, x);
    TLSE * p = l;
    l = l->prox;
    free(p);
    return l;
}

TLSE * TLSE_busca(TLSE * l, int x){
    //if(!l) return l;
    //if(l->info == x){
    if((!l) || (l->info == x)) return l;
    return TLSE_busca(l->prox, x);
}

TLSE * TLSE_ins_ord(TLSE * l, int x){
    if(!l) return TLSE_ins_ini(l, x);
    if(l->info < x) l->prox = TLSE_ins_ord(l->prox, x);
    else return TLSE_ins_ini(l, x);
    return l;
}

void TLSE_imprime(TLSE * l){
    if(l){
        printf("%d\n", l->info);
        TLSE_imprime(l->prox);
    }
}

void TLSE_imprime_rev(TLSE * l){
    if(l){
        TLSE_imprime(l->prox);
        printf("%d\n", l->info);
    }
}

void TLSE_libera(TLSE *l){
    if(!l) return;
    TLSE_libera(l->prox);
    free(l);
}


int main(void){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        //l = TLSE_ins_fim(l, x);
    }while(1);
    printf("A lista original: ");
    TLSE_imprime(l);
    printf("\n");

    printf("Agora o resultado da funcao criada: \n");
    //TLSE_imprime_rev(l);
    TLSE_libera(l);

    return 0;
}