// (Q4) Dados dois arquivos texto que representam conjuntos inteiros (isto é, não há elementos repetidos nos arquivos),
// um elemento por linha, e fazendo SOMENTE uma leitura em cada arquivo, faça cada uma das questões utilizando 
// tabelas hash em memória secundária:
// (a) interseção dos conjuntos: void inter(char* arq1, char* arq2, char* saida);


// typedef struct num{
//   int num, prox, qtde;
// }TNUM;

// int TH_hash(int mat, int tam);
// void TH_inicializa(char *tabHash, int tam);
// TNUM* TH_busca(char *tabHash, char *dados, int tam, int num);
// void TH_retira(char *tabHash, char *dados, int tam, int num);
// void TH_insere(char *tabHash, char *dados, int tam, int num);
// void TH_imprime (char *tabHash, char *dados, int tam);

#include "../TH.c"

void inter(char* arq1, char* arq2, char* saida){
    FILE *f1 = fopen(arq1, "rb");
    FILE *f2 = fopen(arq2, "rb");
    if(!f1 || !f2) exit(1);
    int tam, x, end;
    printf("Qual o tamanho da sua hash? ");
    scanf("%d", &tam);
    TH_inicializa("hash.bin", tam);
    while(fscanf(f1, "%d", &x) == 1){ //pegando cada elemento do arq1
        TH_insere("hash.bin", "dados.bin", tam, x);
    }
    fclose(f1);
    while(fscanf(f2, "%d", &x) == 1){ //pegando cada elemento do arq1
        TH_insere("hash.bin", "dados.bin", tam, x);
    }
    fclose(f2);

    //já preenchi a hash, agr só percorrer
    FILE * hash = fopen("hash.bin", "rb");
    FILE *dados = fopen("dados.bin", "rb");
    FILE * fs = fopen(saida, "at"); //append no arquivo texto
    rewind(hash); //subindo
    TNUM aux;
    while(fread(&end, sizeof(int), 1, hash)){
        if(end != -1){
            fseek(dados, end, SEEK_SET);
            fread(&aux, sizeof(TNUM), 1, dados);
            if(aux.qtde > 1) fprintf(fs, "%d\n", aux.num);
            
            while(aux.prox != -1){
                fseek(dados, aux.prox, SEEK_SET);
                fread(&aux, sizeof(TNUM), 1, dados);
                if(aux.qtde > 1) fprintf(fs, "%d\n", aux.num);
            
            }
        }
    }
    fclose(hash);
    fclose(dados);
    fclose(fs);
    return;
}


int main(){
    // remove("saida1.txt");
    inter("arq1.txt", "arq2.txt", "saida.txt");
    return 0;
}