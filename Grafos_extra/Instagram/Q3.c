#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TG.c"

// (3) Exercícios do Instagram (grafos orientados).

//      3. Quem é a pessoa mais popular? (tem mais seguidores)
//      TG *mais_popular(TG *g);

int contador(TG * g){
    TG * p = g; int cont = 0;
    while(p){
        cont++;
        p = p->prox_no;
    }
    return cont;
}

TG *mais_popular(TG *g){
    if(!g) return NULL;
    int * vetor = (int*)malloc(sizeof(int)*contador(g)); //anotarei os numeros de vizinhos de cada nó do grafo
    //se o maior numero de vizinhos aparecer mais de uma vez, retorno NULL pq não temos UM MAIS famoso
    TG * p = g, *p_maior = NULL;
    int cont, maior=0, indice=0;
    while(p){
        cont = 0;
        TG * outros = g;
        while(outros){
            if(strcmp(p->nome_no, outros->nome_no) != 0){ // se forem igausi, não olho né, ngm se auto segue
                if(TG_busca_aresta(g, outros->id_no, p->id_no)) cont ++;
            }
            outros = outros->prox_no;
        } 
        if(cont > maior){
            maior = cont;
            p_maior = p;
        }
        vetor[indice] = cont;
        indice++;
        p = p->prox_no;
    }

    int ver = 0;
    for(int i = 0; i<contador(g); i++){
        if(vetor[i] == maior) ver++;
    }
    free(vetor);
    if(ver == 1) return p_maior;
    else return NULL;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG * grafo = NULL;
    TG * resp;
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
            TG_ins_aresta(grafo,x,y,nome2);
            break;
        case 3:
            printf("\n\tO grafo:\n");
            TG_imp_rec(grafo);
            break;
        case 4:
            resp = mais_popular(grafo);
            if(!resp) printf("Nao temos alguem mais famoso que os outros.");
            else printf("\n%s eh a pessoa mais popular (com o maior numero de seguidores)!!!\n", resp->nome_no);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}