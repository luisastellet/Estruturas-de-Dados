//Pegar uma árvore B e inserir em um vetor ordenado valores que estão entre n e m
//Não pode ordenador o vetor, precisa inserir ordenado

#include "../TARVB.c"

int tamanho(TARVB * a, int N, int M){
    if(!a) return 0;
    int i, tam=0;
    for(i=0; i<a->nchaves; i++){
        tam += tamanho(a->filho[i], N, M);
        if(a->chave[i] > N && a->chave[i] < M) tam++;
    }
    tam += tamanho(a->filho[i], N, M);
    return tam;
}

int * preenche(TARVB * a, int N, int M, int * vet, int * indice){
    if(!a) return vet;
    int i;
    for(i=0; i<a->nchaves; i++){
        vet = preenche(a->filho[i], N, M, vet, indice);
        if(a->chave[i] > N && a->chave[i] < M){
            vet[*indice] = a->chave[i];
            (*indice)++;
        }
    }
    vet = preenche(a->filho[i], N, M, vet, indice);
    return vet;


}

int * mn(TARVB * a, int N, int M, int * tam){
    if(!a) return NULL;
    int indice = 0;
    *tam = tamanho(a, N, M);
    int * vet = (int*)malloc(sizeof(int)*(*tam));
    return preenche(a, N, M, vet, &indice);
}

int main(){
    TARVB *arvore = TARVB_Inicializa();
    int t;
    printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
    scanf("%d", &t);
    if(t < 2) t = 2;
    int num = 0, from, to;
    while(num != -1){
        printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
        scanf("%d", &num);
        if(num == -9){
        scanf("%d", &from);
        arvore = TARVB_Retira(arvore, from, t);
        TARVB_Imprime(arvore);
        }
        else if(num == -1){
        printf("\n");
        TARVB_Imprime(arvore);
        // TARVB_Libera(arvore);
        // return 0;
        break;
        }
        else if(!num){
        printf("\n");
        TARVB_Imprime(arvore);
        }
        else arvore = TARVB_Insere(arvore, num, t);
        printf("\n\n");
    }
    int N, M, tam = 0;
    printf("Quais os limites inferiores e superiores? ");
    scanf("%d %d", &N, &M);
    int * resp;
    resp = mn(arvore, N, M, &tam);
    for(int i=0; i<tam; i++) printf("%d ", resp[i]);
    TARVB_Libera(arvore);
    free(resp);
    return 0;
}
