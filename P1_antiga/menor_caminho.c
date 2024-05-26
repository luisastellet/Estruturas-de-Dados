#include "TG.c"
#include <limits.h>
#include <string.h>

//Falar o menor caminho de no1 a no2 de até tamanho k
//criarei uma variável "global" para ser vista em todas as chamadas recursivas
//só substituo essa var se 

int aux(TG * g, int no1, int no2, int k, int * menorzao, int tam){
    if(k<0 || !g) return INT_MAX;
    if(no1 == no2) return 0; // se eu encontrasse na lista de vizinhos seria 1
    TG * no = TG_busca_no(g, no1);
    TVIZ * viz = no->prim_viz;

    while(viz){ //tem que olhar cada vizinho
        tam = 0;
        tam = aux(g, viz->id_viz, no2, k-1, menorzao, tam); //precisa pegar o atual (+1)
        
        if(tam != INT_MAX) tam++; //isso é pra evitar o overflow de INT_MAX + 1
        if((tam < (*menorzao)) && (tam <= k)) (*menorzao) = tam;

        viz = viz->prox_viz;
    }
    return (*menorzao);
}

int viz_direto(TG * g, int no1, int no2){
    if(!g) return 0;
    TG * no = TG_busca_no(g, no1);
    TVIZ * viz = no->prim_viz;
    while(viz){
        if(viz->id_viz == no2) return 1;
        viz = viz->prox_viz;
    }
    return 0;
}

int testek_1(TG * g, int no1, int no2, int k){
    if(!g || !TG_busca_no(g, no1) || !TG_busca_no(g, no2) || k < 0) return 0;
    if((no1 == no2)) return 0;
    int menorzao = INT_MAX;
    int ver = viz_direto(g, no1, no2);
    if(ver && (k >= 1)) return 1; //ele é vizinho direto, caminho é de tam 1
    
    //não é vizinho direto, chamaremos recursao
    return aux(g, no1, no2, k, &menorzao, 0);
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
            printf("Qual o tamanho max do caminho? ");
            scanf("%d", &k);
            int ver = testek_1(grafo, no1, no2, k);
            printf("ver: %d", ver);
            printf("\n\tExiste caminho de tamanho %d do no %d ao no %d", ver, no1, no2);
            if(!ver) printf("\n\tNAO existe caminho de tamanho %d do no %d ao no %d", ver, no1, no2);
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