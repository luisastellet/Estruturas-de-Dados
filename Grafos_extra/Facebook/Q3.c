#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

// (3) Exercícios do Facebook (grafos não-orientados).

//      3. Quantas pessoas temos com o maior número de seguidores?
//      TGrafo *mais_popular(TGrafo *g);

// AJUSTEI A QUESTÃO (para fazer sentido em grafo não-orientado)

int contador(TG * g){
    TG * p = g; int cont = 0;
    while(p){
        cont++;
        p = p->prox_no;
    }
    return cont;
}

int mais_popular(TG *g){
    if(!g) return -1;
    int tam = contador(g);
    int * vetor = (int*)malloc(sizeof(int)*tam); //anotarei os numeros de vizinhos de cada nó do grafo
    //se o maior numero de vizinhos aparecer mais de uma vez, retorno NULL pq nçao temos UM MAIS famoso
    TG * p = g;
    int cont, maior=0, indice=0;
    while(p){
        cont = 0;
        TVIZ * viz = p->prim_viz;
        while(viz){
            cont++;
            viz = viz->prox_viz;
        }
        if(cont > maior){
            maior = cont;
        }
        vetor[indice] = cont;
        indice++;
        p = p->prox_no;
    }
    //achei o maior numero de vizinhos
    //agr olho o vetor pra ver quantas vezes ele aparece
    int famosos = 0;
    for(int i=0; i<tam; i++){
        if(vetor[i] == maior) famosos++;
    }
    free(vetor);
    return famosos;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG * grafo = NULL;
    int resp;
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
            resp = mais_popular(grafo);
            if(resp == -1) printf("Nao temos ninguem no Facebook");
            else printf("\nTemos %d pessoas mais populares (com o maior numero de seguidores)!!!\n", resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}