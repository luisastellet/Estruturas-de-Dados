// (Q4) verificar se o grafo, passado como parâmetro de entrada, possui todos os nós com grau
// igual a k - int testek(TG *g, int k); e

//grau é numero de vizinhos

#include "TG.c"

int aux(TG *g, int k){
    if(!g) return 1;
    int resp = aux(g->prox_no, k);
    int cont = 0;
    TVIZ * viz = g->prim_viz;
    while(viz){
        cont++;
        viz = viz->prox_viz;
    }
    if(cont != k) return 0;
    return resp && 1; 
}

int testek(TG * g, int k){
    if(!g) return 0;
    return aux(g, k);
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver,a,b;
    TG* grafo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Testar grafo\n");
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
            printf("\n");
            int k;
            printf("Qual o k? ");
            scanf("%d", &k);
            int resp = testek(grafo, k);
            if(resp) printf("\n\tEste grafo so tem nos de grau %d", k);
            else  printf("\n\tEste grafo NAO tem so nos de grau %d", k);
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