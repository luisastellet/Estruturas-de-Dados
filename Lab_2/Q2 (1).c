// Dados um grafo, dois nós x e y, retorne um caminho qualquer entre x e y. 
// Se não tiver caminho, o retornoé NULL: TLSE * caminho (TG * g, int x, int y)

#include "TG.c"
#include "TLSE.c"

// Não pode ser iterativo !!!
TLSE * acha_caminho(TG * no, TG * grafo, TLSE * l, int origem, int dest){
    if(!no) return NULL;
    TVIZ * viz = no->prim_viz;
    if(viz->id_viz == dest){
        return TLSE_insere(l, dest);
    }else{
        while(viz){
            if(viz->id_viz != origem) l = acha_caminho(TG_busca_no(grafo, viz->id_viz), grafo, l, no->id_no, dest);
            if(l) return TLSE_insere(l,viz->id_viz);
            viz = viz->prox_viz;
        }
    }
    return NULL;
}

TLSE * testa_vizinhos(TG * g, TG * no, int origem, int dest, TLSE * l){
    TVIZ * viz = no->prim_viz;
    while(viz){
        if(viz->id_viz == dest){
            l = TLSE_insere(l, origem);
            l = TLSE_insere(l, dest);
            return l;
        }
        viz = viz->prox_viz;
    }
    return NULL;
}


TLSE * caminho (TG * g, int x, int y){
    if(!g) return NULL;
    if(!TG_busca_no(g, x) || !TG_busca_no(g, y)) return NULL; //não há um dos nós, então não terá caminho
    TLSE * l = TLSE_inicializa();
    TG * no = TG_busca_no(g, x); // do X pro Y
    l = testa_vizinhos(g, no, x, y, l);
    if(l) return l; //se l for NULL, não achei vizinho direto
    l = acha_caminho(no, g, l, x, y);
    if(l) l = TLSE_insere(l, x);
    return l;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, y,ver,a,b;
    TG* grafo = NULL;
    TLSE* resp = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir No\n\t2 - Inserir Aresta\n\t3 - Imprimir grafo\n\t4 - Acha caminho\n");
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
            printf("\n\tDigite o no que deseja usar como origem: ");
            scanf("%d", &a);
            printf("\n");
            printf("\n\tDigite o no que deseja usar como destino: ");
            scanf("%d", &b);
            printf("\n");
            resp = caminho(grafo,a,b);
            if(!resp) printf("\n\tNao ha caminho do no %d para o no %d",a,b);
            else printf("\n\tO caminho existe e eh: ");
            TLSE_imprime(resp);
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