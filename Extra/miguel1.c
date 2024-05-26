//Em um grafo, crie uma fonte e um sumidouro
//fonte um nó que aponta para todos os outros
//sumidouro um que é apontado por todos os outros.

//OBS: A fonte não aponta para o sumidouro!!!
//id da fonte: -inf
//id do sumidouro: +inf 

#include<limits.h>
#include "TG.c"

#define fonte INT_MIN
#define sumidouro INT_MAX

TG* cria_fs(TG* g){
    if(!g) return NULL;
    g = TG_ins_no(g, fonte);
    g = TG_ins_no(g, sumidouro);

    TG * no = g;

    //fazendo o nó fonte
    while(no){
        //fonte
        if((no->id_no != sumidouro) && (no->id_no != fonte)){
            //coloco a relação fonte->no
            TG_ins_aresta(g, fonte, no->id_no);
            //crio a relação no->sumidouro
            TG_ins_aresta(g, no->id_no, sumidouro);
        }
        no = no->prox_no;
    }
    return g;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,z;
    TG* grafo = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Criar fonte e sumidouro\n");
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
            grafo = cria_fs(grafo);
            printf("\n\tO grafo ficou: ");
            TG_imp_rec(grafo);
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