#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

//(2) Testar se o grafo é completo - int completo(TG *g);
//Um grafo é dito completo se todos os seus pares de vértices forem adjacentes

/*
    IDEIA
- se eu tiver 5 nós, eu verificando que cada nó possui 4 vizinhos (n-1), já basta para ser completo
- Não importa o id dos vizinhos, pq um nó 5 não poderá ter vizinho 9 se o 9 não é um nó
*/

int vizinhos_completo(int k, TVIZ * vizinho){
    TVIZ * viz = vizinho;
    while(viz){
        k--;
        viz = viz->prox_viz;
    }
    if(k) return 0;
    return 1;
}

int completo(TG *g){
    if(!g) return 1;
    int n_nos = 0;
    TG * p = g;
    while(p){
        n_nos++;
        p = p->prox_no;
    }
    n_nos--; //preciso que todos tenham esse valor de vizinhos
    p = g;
    while(p){
        if(!vizinhos_completo(n_nos, p->prim_viz)) return 0;
        p = p->prox_no;
    }
    return 1;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No no grafo\n\t2 - Inserir Aresta no grafo\n\t3 - Imprimir grafos\n\t4 - Verificar funcao\n");
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
            printf("\n\tO grafo:");
            printf("\n\tPrimeiro grafo:\n");
            TG_imp_rec(grafo);
            break;
        case 4:
            ver = completo(grafo);
            if(ver) printf("\n\t Os grafos eh completo!!!\n");
            if(!ver) printf("\n\t Os grafos nao eh completo :(\n");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}