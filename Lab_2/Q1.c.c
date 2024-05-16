//Dado um grafo conectado, verifique se ele pode ser transformado em árvore binária:

#include "TG.c"
#include "TLSE.c"

int cont_filhos(TG * g){
    int cont;
    TG * no = g;
    while(no){
        TVIZ * viz = no->prim_viz;
        cont = 0;
        while(viz){
            cont++;
            viz = viz->prox_viz;
        }
        if(cont > 3) return 0;
        no = no->prox_no;
    }
    return 1;
}

int parentesco(TG * g){
    TG * no = g;
    while(no){
        int pai = no->id_no;
        TVIZ * viz = no->prim_viz;
        TLSE * l = NULL;
        l = TLSE_insere(l, pai); //inseri o pai
        while(viz){
            TG * filho = TG_busca_no(g, viz->id_viz);
            TVIZ * irmaos = filho->prim_viz; //filho existe, entao não estaria fazendo null->prim_viz
            
            while(irmaos){
                if((irmaos->id_viz != pai) && TLSE_busca(l, irmaos->id_viz)) return 0;
                else if((irmaos->id_viz != pai) && !TLSE_busca(l, irmaos->id_viz)){
                    l = TLSE_insere(l, irmaos->id_viz);
                    irmaos = irmaos->prox_viz;
                }
                else if(irmaos->id_viz == pai) irmaos = irmaos->prox_viz;
            }
            l = TLSE_insere(l, viz->id_viz);
            viz = viz->prox_viz;
        }
        no = no->prox_no;
        TLSE_libera(l);
    }
    return 1;
}



int teste(TG * g){
    if(!g) return 1;
    if(!cont_filhos) return 0;
    return parentesco(g);
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
            ver = teste(grafo);
            if(ver) printf("\n\tO grafo pode ser arvore");
            else printf("\n\tO grafo NAO pode ser arvore");
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