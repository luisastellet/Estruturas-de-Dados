#include <stdio.h>
#include <stdlib.h>

int pai(int end, int k){
    //return (pos-1)/2
    int pos = end/sizeof(int);
    if(pos >0) return ((pos-1)/k)*sizeof(end);
    return -1;
}

int filho(int end, int k, int filho){
    //return 2*pos + 1
    int pos = end/sizeof(int);
    return (k*pos + filho)*sizeof(int); 
}

void max_heapfy(char * arq, int tam_arq, int end, int k){
    FILE * fp = fopen(arq, "rb+");
    int maior = end, f, i, aux, elem_maior;
    fseek(fp, maior, SEEK_SET);
    fread(&elem_maior, sizeof(int), 1, fp);
    for(i=1; i<=k; i++){
        f = filho(end, k, i);
        if(f < tam_arq){
            fseek(fp, f, SEEK_SET);
            fread(&aux, sizeof(int), 1, fp);
            if (aux > elem_maior){
                maior = f;
                elem_maior = aux;
            }
        }
    }
    if(maior != end){
        fseek(fp, end, SEEK_SET);
        fread(&aux, sizeof(int), 1, fp);
        fseek(fp, end, SEEK_SET);
        fwrite(&elem_maior, sizeof(int), 1, fp);
        fseek(fp, maior, SEEK_SET);
        fwrite(&aux, sizeof(int), 1, fp);
        fclose(fp);
        max_heapfy(arq, tam_arq, maior, k);
    }
    else fclose(fp);
    return;
}

void build_maxheap(char * arq, int k){
    int ult_pai;
    FILE * fp = fopen(arq, "rb");
    if(!fp) exit(1);
    fseek(fp, 0L, SEEK_END);
    int tam = ftell(fp), i;
    ult_pai = pai(tam-sizeof(int), k);
    fclose(fp);
    for(i=ult_pai; i>=0; i-=sizeof(int)){
        max_heapfy(arq, tam, i, k);
    }
    return;
}

void heapsort(char * arq, int k){
    build_maxheap(arq, k);
    FILE * fp = fopen(arq, "rb");
    fseek(fp, 0L, SEEK_END);
    int tam = ftell(fp), i;
    fclose(fp);
    for(i=tam-sizeof(int); i>=sizeof(int); i-=sizeof(int)){
        int ult, primeiro;
        FILE * fp = fopen(arq, "rb+");
        fseek(fp, i, SEEK_SET);
        fread(&ult, sizeof(int), 1, fp);
        rewind(fp);
        fread(&primeiro, sizeof(int), 1, fp);
        rewind(fp);
        fwrite(&ult, sizeof(int), 1, fp);
        fseek(fp, i, SEEK_SET);
        fwrite(&primeiro, sizeof(int), 1, fp);
        fclose(fp);
        max_heapfy(arq, i, 0, k);
    }
}

int main(void){
    char nome_arq[31];
    int qtd;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arq);
    printf("Quantos filhos tem cada nó? ");
    scanf("%d", &qtd);
    int nvet, i = 0, aux;
    printf("Digite o numero de elementos distintos do arquivo: ");
    scanf("%d", &nvet);
    int vet[nvet];
    while (i < nvet){
        scanf("%d", &aux);
        if(aux >= 0){
            int j;
            for(j = 0; j < i; j++) if (vet[j] == aux) break;
            if (j == i) vet[i++] = aux;
        }
    }

    FILE *fp = fopen(nome_arq, "wb");
    if(!fp) exit(1);
    fwrite(&vet, sizeof(int), nvet, fp);
    fclose(fp);

    heapsort(nome_arq, qtd);
    int resp[nvet];
    fp = fopen(nome_arq, "rb");
    if(!fp) exit(1);
    fread(&resp, sizeof(int), nvet, fp);
    fclose(fp);

    printf("\nVerificacao da ordenacao...\n");
    for(i = 0; i < nvet; i++) printf("(%d):\t%d\t%d\n", i + 1, vet[i], resp[i]);

    return 0;
}