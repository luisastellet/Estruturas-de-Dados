#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

// (3) Exercícios do Facebook (grafos não-orientados).

//      2. Quem são os seguidores de uma determinada pessoa? (função
//      imprime os nomes dos seguidores, caso a flag imprime seja
//      True, e retorna quantidade de seguidores)
//      int seguidores(TGrafo *vertice, char *nome, int imprime);

// como é não orientado, quem luisa segue, segue luisa, basta então ver quem são os vizinhos de luisa

int seguidores(TG *g, char *nome, int flag){
    int cont = 0;
    TG * p = g;
    while(p){
        if(strcmp(nome, p->nome_no) != 0) p = p->prox_no; //diferentes
        else break; //nomes iguais
    }
    if(!p){
        printf("%s nao esta cadastrado", nome);
        return -1; // so para na main saber que nao printo nada
    }
    TVIZ * viz = p->prim_viz;
    if(!viz) printf("%s nao tem seguidor");
    while(viz){
        if(flag) printf("%s segue %s.\n", viz->nome_viz, nome);
        cont++;
        viz = viz->prox_viz;
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

            printf("\n Quer ver os seguidores? [S/N]");
            scanf(" %c", &escolha);
            int flag;
            if('S' == escolha) flag = 1;
            else flag = 0;

            ver = seguidores(grafo,nome,flag);
            if(ver != -1)printf("\n\t %s tem %d seguidores!!!\n", nome, ver);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}