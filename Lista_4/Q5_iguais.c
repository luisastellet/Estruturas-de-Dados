#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "TG.c"

//(Q5) testar se dois grafos são iguais - int ig(TG *g1, TG *g2). 

int ig_no (TG *g1, TG *g2){
    TG * p_no1 = g1;
    TG * p_no2 = g2;
    while(p_no1){
        if((p_no1->id_no != p_no2->id_no) || !p_no2) return 0; //vendo os nós
        TVIZ * viz_no1 = p_no1->prim_viz;
        TVIZ * viz_no2 = p_no2->prim_viz;
        while(viz_no1){
            if((viz_no1->id_viz != viz_no2->id_viz) || !viz_no2) return 0; //vendo os vizinhos de cada nó
            viz_no1 = viz_no1->prox_viz;
            viz_no2 = viz_no2->prox_viz;
        }
        if(viz_no2->prox_viz) return 0; // se viz2 ainda tiver coisa e em viz1 não tem, retorna 0 pq não são iguais
        p_no1 = p_no1->prox_no;
        p_no2 = p_no2->prox_no;
    }
    if(p_no2->prox_no) return 0; // se ainda tiver nó no g2, mas g1 já acabou, retorna 0 pq não são iguais
    return 1;
}

// TENTAR FAZER RECURSIVO
int ig_no (TG *g1, TG *g2){
    TG * p_no1 = g1;
    TG * p_no2 = g2;
    while(p_no1){
        if((p_no1->id_no != p_no2->id_no) || !p_no2) return 0; //vendo os nós
        TVIZ * viz_no1 = p_no1->prim_viz;
        TVIZ * viz_no2 = p_no2->prim_viz;
        while(viz_no1){
            if((viz_no1->id_viz != viz_no2->id_viz) || !viz_no2) return 0; //vendo os vizinhos de cada nó
            viz_no1 = viz_no1->prox_viz;
            viz_no2 = viz_no2->prox_viz;
        }
        if(viz_no2->prox_viz) return 0; // se viz2 ainda tiver coisa e em viz1 não tem, retorna 0 pq não são iguais
        p_no1 = p_no1->prox_no;
        p_no2 = p_no2->prox_no;
    }
    if(p_no2->prox_no) return 0; // se ainda tiver nó no g2, mas g1 já acabou, retorna 0 pq não são iguais
    return 1;
}

int ig(TG *g1, TG *g2){
    return ig_no(g1, g2);
    //não preciso chamar duas vezes porque dentro do meu código faço verificações paa garantir que não existem mais coisas no g2 além do g1
}


int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    TG* segundo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No no primeiro\n\t2 - Inserir Aresta no primeiro\n\t3 - Inserir No no segundo\n\t4 - Inserir Aresta no segundo\n\t5 - Imprimir grafos\n\t6 - Verificar igualdade\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o no a ser inserido no grafo: ");
            scanf("%d", &x);
            printf("\n");
            grafo = TG_ins_no(grafo,x);
            break;
        case 2:
            printf("\n\tDigite o no que deseja inserir a aresta: ");
            scanf("%d", &x);
            printf("\n");
            printf("\n\tDigite o no que deseja conectar com o no inserido: ");
            scanf("%d", &y);
            printf("\n");
            TG_ins_aresta(grafo,x,y);
            break;
        case 3:
            printf("\n\tDigite o no a ser inserido no grafo: ");
            scanf("%d", &x);
            printf("\n");
            segundo = TG_ins_no(segundo,x);
            break;
        case 4:
            printf("\n\tDigite o no que deseja inserir a aresta: ");
            scanf("%d", &x);
            printf("\n");
            printf("\n\tDigite o no que deseja conectar com o no inserido: ");
            scanf("%d", &y);
            printf("\n");
            TG_ins_aresta(segundo,x,y);
            break;
        case 5:
            printf("\n\tOs grafos:");
            printf("\n\tPrimeiro grafo:\n");
            TG_imp_rec(grafo);
            printf("\n");
            printf("\n\tSegundo grafo:\n");
            TG_imp_rec(segundo);
            printf("\n");
            break;
        case 6:
            ver = ig(grafo,segundo);
            if(ver) printf("\n\t Os grafos sao iguais!!!\n");
            if(!ver) printf("\n\t Os grafos nao sao iguais :(\n");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    TG_libera(segundo);
    return 0;
}