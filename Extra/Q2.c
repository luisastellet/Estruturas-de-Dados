#include "TG.c"

//Falar se existe um caminho de no1 a no2 de tamanho k

//pq isso funciona no caso ?? e a repetição circular?
//no1 = 1   no2 = 4   k = 2
// 1: 2 3
// 2: 1 4

int aux(TG * g, int no1, int no2, int k){
    if(k<0) return 0;
    if((no1 == no2) && k == 0) return 1;
    TG * no = TG_busca_no(g, no1);
    TVIZ * viz = no->prim_viz;
    while(viz){ //tem que olhar cada vizinho
        int ver = aux(g, viz->id_viz, no2, k-1);
        if(ver) return 1;
        viz = viz->prox_viz;
    }
    return 0;
}


int testek_1(TG *g, int no1, int no2, int k){
    if(!g || !TG_busca_no(g, no1) || !TG_busca_no(g, no2) || k<0) return 0;
    if((no1 == no2) && k == 0) return 1;
    return aux(g, no1, no2, k);
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver;
    TG* grafo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Verificador Arvore\n");
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

        case 3:
            printf("\n\tO grafo eh: ");
            TG_imp_rec(grafo);
            printf("\n");
            break;
        case 4:
            printf("Qual no1 e qual no2? ");
            int no1, no2, k;
            scanf("%d", &no1);
            scanf("%d", &no2);
            printf("Qual o tamanho do caminho? ");
            scanf("%d", &k);
            int ver = testek_1(grafo, no1, no2, k);
            printf("ver: %d", ver);
            if(ver) printf("\n\tExiste caminho de tamanho %d do no %d ao no %d", k, no1, no2);
            else printf("\n\tNAO existe caminho de tamanho %d do no %d ao no %d", k, no1, no2);
            printf("\n");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TG_libera(grafo);
    return 0;
}