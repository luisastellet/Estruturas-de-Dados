#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

// (3) Exercícios do Facebook (grafos não-orientados).

//      4. Quais são as pessoas que só seguem pessoas mais velhas do
//      que ela própria? (função imprime os nomes das pessoas, caso a
//      flag imprime seja True, e retorna quantidade de pessoas)
//      int segue_mais_velho(TGrafo *g, int imprime);


int segue_mais_velho(TG *g, int flag){
    if(!g) return -1;
    TG * p = g;
    int qtd = 0, ver;
    while(p){
        TVIZ * viz = p->prim_viz;
        if(viz) ver = 1;
        else ver = -1;
        while(viz){
            if(viz->id_viz <= p->id_no){
                ver = 0;
            }
            viz = viz->prox_viz;
        }
        if(ver == 1){
            printf("%s segue so pessoas mais velhas que ela/ele.\n", p->nome_no);
            qtd++;
        }
        p = p->prox_no;
    }
    return qtd;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG * grafo = NULL;
    int resp;
    char nome[31];
    char nome2[31];
    char escolha;

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No no grafo\n\t2 - Inserir Aresta no grafo\n\t3 - Imprimir grafos\n\t4 - Verificar funcao\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o no a ser inserido no grafo e o nome: ");
            scanf("%d %s", &x, &nome);
            printf("\n");
            grafo = TG_ins_no(grafo, x, nome);
            break;
        case 2:
            printf("\n\tDigite o no que deseja inserir a aresta e o nome: ");
            scanf("%d %s", &x, nome);
            printf("\n");
            printf("\n\tDigite o no que deseja conectar com o no inserido e o nome: ");
            scanf("%d %s", &y, nome2);
            printf("\n");
            TG_ins_aresta(grafo,x,y,nome,nome2);
            break;
        case 3:
            printf("\n\tO grafo:\n");
            TG_imp_rec(grafo);
            break;
        case 4:
            printf("\n Quer ver os nomes de qm segue so mais velhos? [S/N] ");
            scanf(" %c", &escolha);
            int flag;
            if('S' == escolha) flag = 1;
            else flag = 0;
            resp = segue_mais_velho(grafo, flag);
            if(resp == -1) printf("Nao temos ninguem no Facebook");
            else printf("\nTemos %d pessoas seguindo so pessoas mais velhas que elas!!!\n", resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}