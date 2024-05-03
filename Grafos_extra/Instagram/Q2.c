#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

// (3) Exercícios do Instagram (grafos orientados).

//      2. Quem são os seguidores de uma determinada pessoa? (função
//      imprime os nomes dos seguidores, caso a flag imprime seja
//      True, e retorna quantidade de seguidores)
//      int seguidores(TGrafo *vertice, char *nome, int imprime);


int seguidores(TG *g, char *nome, int flag){
    if(!g) return -1;
    TG * p = g;
    int cont = 0;
    while(p){
        if(strcmp(nome, p->nome_no) != 0){
            TVIZ * viz = p->prim_viz;
            while(viz){
                if(strcmp(nome, viz->nome_viz) == 0){
                    if(flag) printf("%s segue %s.\n", p->nome_no, viz->nome_viz);
                    cont++;
                    break;
                }
                viz = viz->prox_viz;
            }
        }
        p = p->prox_no;
    }
    return cont;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
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
            TG_ins_aresta(grafo,x,y,nome2);
            break;
        case 3:
            printf("\n\tO grafo:");
            printf("\n\tPrimeiro grafo:\n");
            TG_imp_rec(grafo);
            break;
        case 4:
            printf("Qual nome quer procurar? ");
            scanf("%s", nome);

            printf("\n Quer ver os seguidores? [S/N] ");
            scanf(" %c", &escolha);
            int flag;
            if('S' == escolha) flag = 1;
            else flag = 0;

            ver = seguidores(grafo,nome,flag);
            if(ver == -1) printf("Nao temos ninguem no Facebook");
            else printf("\n\t %s tem %d seguidores!!!\n", nome, ver);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}