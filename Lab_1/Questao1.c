#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAB.c"


//Escrever uma função em C que, dada uma árvore binária qualquer, retorne, 
//num vetor, todos os elementos maiores que N. A função deve ter o seguinte 
//protótipo: int* mN(TAB*a, int N, int *tam);
int tamanho (TAB * a){
    if(!a) return 0;
    int x = tamanho(a->esq);
    int y = tamanho(a->dir);
    return 1+y+x;
}

int maiores_N(TAB* a, int N){
    if(!a) return 0;
    int ver_esq = maiores_N(a->esq, N);
    int ver_dir = maiores_N(a->dir, N);
    if(a->info > N) return (1 + ver_dir + ver_esq);
    return (ver_dir + ver_esq);
}


void preencher_vetor(TAB* a, int * pos, int * vetor, int N){
    if(!a) return;
    if(a->info > N){
        vetor[(*pos)] = a->info;
        (*pos)++;
    }
    preencher_vetor(a->esq, pos, vetor, N);
    preencher_vetor(a->dir, pos, vetor, N);
    return;
}

int* mN(TAB*a, int N, int *tam){
	(*tam) = tamanho(a);
    int qtd = maiores_N(a, N);
    int pos = 0;
    int* vetor = (int*)malloc(sizeof(int)*qtd);
    preencher_vetor(a, &pos, vetor, N); //como já malloquei o vetor, pode ser void, só irei preencher
    return vetor;
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

    int tam;
    int * teste = mN(a, N, &tam);
    for(int i=0; i<tam; i++) printf("%d\t", teste[i]);

    free(teste);
    TAB_libera(a);
    return 0;
}
