// (Q4) Dados dois arquivos texto que representam conjuntos inteiros (isto é, não há elementos repetidos nos arquivos),
//  um elemento por linha, e fazendo SOMENTE uma leitura em cada arquivo, faça cada uma das questões utilizando 
//  tabelas hash em memória secundária:
// (b) diferença simétrica de conjuntos: void dif_sim(char* arq1, char* arq2, char* saida);

#include "../TH.c"

void dif_sim(char* arq1, char* arq2, char* saida){
    FILE * fp1 = fopen(arq1, "rt");
    FILE * fp2 = fopen(arq2, "rt");
    if(!fp1 || !fp2) exit(1);
    int tam;
    printf("Qual o tamanho da hash? ");
    scanf("%d", &tam);
    TH_inicializa("HashB.bin", 5);
    //FILE * fs = fopen(saida, "wt");
    int tmp;
    while(fscanf(fp1, "%d", &tmp) == 1){
        TH_insere("HashB.bin", "dadosB.bin", tam, tmp);
    }
    while(fscanf(fp2, "%d", &tmp) == 1){
        TH_insere("HashB.bin", "dadosB.bin", tam, tmp);
    }
    //hash preenchida
    //analisa a qtd, se for igual a 1, é pq n repetiu, ent escreve em saída
    int i=0;
    FILE * hash = fopen("HashB.bin", "rb");
    while(i<tam){
        //vendo cada idice da hash
        TNUM aux;
        int end;
        fread(&end, sizeof(int), 1, hash);
        if(end != -1){
            FILE * dados = fopen("dadosB.bin", "rb");
            fseek(dados, end, SEEK_SET); //a partir do inicio
            fread(&aux, sizeof(TNUM), 1, dados);
            if(aux.qtde == 1){
                FILE * fs = fopen(saida, "at");
                fprintf(fs, "%d\n", aux.num);
                fclose(fs);
            }
            while(aux.prox != -1){
                fseek(dados, aux.prox, SEEK_SET);
                fread(&aux, sizeof(TNUM), 1, dados);
                if(aux.qtde == 1){
                    FILE * fs = fopen(saida, "at");
                    fprintf(fs, "%d\n", aux.num);
                    fclose(fs);
                }

            }
            fclose(dados);
        }
        i++;
    }
    fclose(hash);


}

int main(){
    remove("saida.txt");
    dif_sim("arq1.txt", "arq2.txt", "saida.txt");
    return 0;
}