#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

//(1) Verificar se o grafo, passado como parâmetro de entrada, possui todos os nós com 
//grau igual a k - int testek(TG *g, int k);

int testek(TG *g, int k){
    if(!g) return 0;
    TG * p_no = g;
    while(p_no){
        TVIZ * p_viz = p_no->prim_viz;
        int cont = 0;
        while(p_viz){
            cont++;
            p_viz = p_viz->prox_viz;
        }
        if(cont != k) return 0;
        p_no = p_no->prox_no;
    }
    return 1;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    int k;
    printf("Digite o k: ");
    scanf("%d", &k);
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
            ver = testek(grafo,k);
            if(ver) printf("\n\t Os grafos tem grau k em todos os nos!!!\n");
            if(!ver) printf("\n\t Os grafos nao tem grau k em todos os nos :(\n");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}