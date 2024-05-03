#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "TG.c"

//(Q5) testar se dois grafos possuem as mesmas informações (não ligando para as ordens) - int ig(TG *g1, TG *g2). 

// AJUSTAR QUESTÃO

int ig_vizinhos(TG * p, TVIZ *v1, TG * g2){
    TVIZ * q = v1;
    while(q){
        if(!TG_busca_aresta(g2, p->id_no, q->id_viz)) return 0;
        //usando o backup pq na função busca dela precisa de toso o grafo
        q = q->prox_viz;
    }
    return 1;
    //o g é pro busca aresta
}

int ig_no (TG *g1, TG *g2){
    if(!g1 && !g2) return 1;
    TG * p = g1;
    while(p){
        if (!TG_busca_no(g2, p->id_no)) return 0; //procuro no g2 o conteúdo de g1
        int x = ig_vizinhos(p, p->prim_viz, g2);
        if(!x) return 0;
        p = p->prox_no;
    }
    return 1;
}

//preciso do backup pq na chamada recursiva, não verei o g2 todo para buscar o nó do g1
int ig(TG *g1, TG *g2){
    printf("retorno na primeira: %d\n", ig_no(g1, g2));
    printf("retorno da segunda: %d\n", ig_no(g2, g1));
    return ig_no(g1, g2) && ig_no(g2, g1); // tem q fazer pros 2, pq não sei quem tem mais nós (poderia fazer uma função para conferir isso)
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
            printf("\nPrimeiro grafo:\n");
            TG_imp_rec(grafo);
            printf("\n");
            printf("\nSegundo grafo:\n");
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