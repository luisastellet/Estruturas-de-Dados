#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

// (3) Exercícios do Facebook (grafos não-orientados).

//       1. Quantas pessoas uma determinada pessoa segue?
//       int numero_seguidos(TGrafo *g, char *nome);

int numero_seguidos(TG *g, char *nome){
    if(!g) return 0;
    TG * p = g;
    while(p){
        if(strcmp(nome, p->nome_no) != 0) p = p->prox_no; //se não forem iguais, continua
        else break; //iguais
    }
    if(!p){
        printf("Esta pessoa nao esta cadastrada!!");
        return -1; //essa pessoa não está cadastrada ai na main eu não printo nada
    }
    TVIZ * viz = p->prim_viz;
    int seguidores = 0;
    while(viz){
        seguidores++;
        viz = viz->prox_viz;
    }
    return seguidores;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    char nome[31];
    char nome2[31];
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
            scanf("%d %s", &x, nome);
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
            printf("\n\tO grafo:");
            printf("\n\tPrimeiro grafo:\n");
            TG_imp_rec(grafo);
            break;
        case 4:
            printf("Qual nome quer procurar? ");
            scanf("%s", nome);
            ver = numero_seguidos(grafo,nome);
            if(ver != -1)printf("\n\t %s segue %d pessoas!!!\n", nome, ver);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}