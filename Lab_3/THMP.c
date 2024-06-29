#include "THMP.h"

int TH_hash(int num, int tam){
    return num % tam;
}

void TH_inicializa(TH tab, int tam){
    int i;
    for(i=0; i<tam; i++) tab[i] = NULL;
    return;
}

TNUM * TNUM_aloca(int num){
    TNUM * novo = (TNUM*)malloc(sizeof(TNUM));
    novo->num = num;
    novo->prox = NULL;
    novo->qtde = 1;
    return novo;
}

void TH_imprime (TH tab, int tam){
    int i = 0;
    while(i<tam){
        TNUM * p = tab[i];
        while(p){
            printf("%d -> ", p->num);
            p = p->prox;
        }
        printf("\n");
        i++;
    }
    return;
}

TNUM* TH_busca(TH tab, int tam, int num){
    int h = TH_hash(num, tam);
    TNUM * p = tab[h];
    while(p){
        if(p->num == num) return p;
        p = p->prox;
    }
    return NULL;
}

TNUM * insere_aux(TNUM * a, int num){
    if(num == a->num){
        a->qtde++;
        return a;
    }
    if(a->num < num) a->prox = insere_aux(a->prox, num);
    else{
        TNUM * aux = TNUM_aloca(num);
        aux->prox = a;
        return aux;
    }
    return a;
}

TH * TH_insere(TH * tab, int tam, int num){
    int h = TH_hash(num, tam);
    *tab[h] = insere_aux(*tab[h], num);
    return;
}

TNUM * retira_aux(TNUM * a, int num){
    if(num == a-> num){
        TNUM * tmp = a;
        a = a->prox;
        free(tmp);
        return a;
    }
    a->prox = retira_aux(a->prox, num);
    return a;
}


TH * TH_retira(TH tab, int tam, int num){
    int h = TH_hash(num, tab);
    tab[h] = retira_aux(tab[h], num);
    return tab;
}

void TH_libera(TH tab, int tam){
    int i = 0;
    while(i<tam){
        TNUM * p = tab[i];
        while(p){
            TNUM * tmp = p;
            p = p->prox;
            free(tmp);
        }
        i++;
    }
    return;
}