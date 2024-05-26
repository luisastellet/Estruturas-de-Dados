//(Q5) testar se dois grafos são iguais - int ig(TG *g1, TG *g2).

#include "TG.c"

int ver_viz (TG * no1, TG * g2){
    TVIZ * viz_no1 = no1->prim_viz;
    while(viz_no1){
        if(!TG_busca_aresta(g2, no1->id_no, viz_no1->id_viz)) return 0;
        viz_no1 = viz_no1->prox_viz;
    }
    return 1;
}

int ver_nos (TG * no1, TG * g2){ //recursiva e chama outra função
    if(!no1) return 1;
    if(!TG_busca_no(g2, no1->id_no)) return 0;
    //achei o nó igual, verei os vizinhos
    if(!ver_viz(no1, g2)) return 0;
    int resp = ver_nos(no1->prox_no, g2);
    return resp;
}

int ig(TG * g1, TG * g2){
    if(!g1 && !g2) return 1;
    if((!g1 && g2) || (g1 && !g2)) return 0;
    if(!ver_nos(g1, g2) || !ver_nos(g2, g1)) return 0;
    return 1;
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