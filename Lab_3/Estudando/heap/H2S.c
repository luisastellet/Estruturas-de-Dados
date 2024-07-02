#include <stdio.h>
#include <stdlib.h>

int pai(int end){
    // return (pos-1)/2
    int pos = end/sizeof(int);
    if(pos > 0) return ((pos-1) / 2) * sizeof(int);
    return -1;
}

int esq(int end){
    //return 2*pos + 1
    int pos = end/sizeof(int);
    return (2*pos + 1) * sizeof(int);
}

int dir(int end){
    //return 2*pos + 1
    int pos = end/sizeof(int);
    return (2*pos + 2) * sizeof(int);
}

//considerei n como o n° de elementos no vetor, n o endereço final do arq
void max_heapfy(char * arq, int tam_arq, int end){
    int maior = end, e = esq(end), d = dir(end);
    FILE * fp = fopen(arq, "rb+");
    if(!fp) exit(1);
    fseek(fp, maior, SEEK_SET); //indo pro end
    int maior_elem, aux;
    fread(&maior_elem, sizeof(int), 1, fp);
    if(e < tam_arq){
        fseek(fp, e, SEEK_SET);
        fread(&aux, sizeof(int), 1, fp);
        if(aux > maior_elem){
            maior = e;
            maior_elem = aux;
        }
    }
    if(d < tam_arq){
        fseek(fp, d, SEEK_SET);
        fread(&aux, sizeof(int), 1, fp);
        if(aux > maior_elem){
            maior = d;
            maior_elem = aux;
        }
    }
    if(maior != end){ //houve mudança
        fseek(fp, end, SEEK_SET);
        fread(&aux, sizeof(int), 1, fp);
        fseek(fp, maior, SEEK_SET);
        fwrite(&aux, sizeof(int), 1, fp);
        fseek(fp, end, SEEK_SET);
        fwrite(&maior_elem, sizeof(int), 1, fp);
        fclose(fp);
        //if((tamarq - maior) > 4)
        max_heapfy(arq, tam_arq, maior);
    }else fclose(fp);
    return;
}

void build_maxheap(char * arq){
    FILE * fp = fopen(arq, "rb");
    if(!fp) exit(1);
    fseek(fp, 0L, SEEK_END);
    int end = ftell(fp);
    int ult_pai = pai(end- sizeof(int)), i;
    fclose(fp);
    for(i=ult_pai; i>=0; i -= sizeof(int)){
        max_heapfy(arq, end, i);
    }
    return;
}

void heapsort(char * arq){
    build_maxheap(arq);
    FILE * fp = fopen(arq, "rb+");
    fseek(fp, 0L, SEEK_END);
    int tam_arq = ftell(fp);
    fclose(fp);
    int i;
    for(i= tam_arq - sizeof(int); i>0; i-=sizeof(int)){
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
        max_heapfy(arq, i, 0);
    }
}

int main(void){
    char nome_arq[31];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arq);
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

    heapsort(nome_arq);
    int resp[nvet];
    fp = fopen(nome_arq, "rb");
    if(!fp) exit(1);
    fread(&resp, sizeof(int), nvet, fp);
    fclose(fp);

    printf("\nVerificacao da ordenacao...\n");
    for(i = 0; i < nvet; i++) printf("(%d):\t%d\t%d\n", i + 1, vet[i], resp[i]);

    return 0;
}