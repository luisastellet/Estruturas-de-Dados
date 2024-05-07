#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q1) Escreva um programa em C que leia dois arquivos binários “a.bin” e “b.bin” contendo
// palavras distintas descritas por 10 caracteres e produza um terceiro arquivo c.bin. No arquivo
// “c.bin”, cada um de seus registros contém um par ordenado de palavras, onde a primeira palavra é
// proveniente de “a.bin” e a segunda de “b.bin”. Como resultado do processamento, o arquivo
// “c.bin” deve conter todos os pares ordenados formados por palavras dos dois arquivos de entrada
// (o resultado é o produto cartesiano dos dois conjuntos). Obs.: todo processamento deve ser feito em
// memória secundária.

void pares_ordenados(char * Arq1, char * Arq2, char * Arqsaida){
    FILE * arq1 = fopen(Arq1, "rb");
    FILE * arq2 = fopen(Arq2, "rb");
    FILE * fs = fopen(Arqsaida, "wb");

    char wordA[11], wordB[11];
    if(!arq1 || !arq2 || !fs) exit(1);

    while(fread(wordA, sizeof(char), 10, arq1) == 10){ //lendo palavra do arq1
        while(fread(wordB, sizeof(char), 10, arq2) == 10){
            fwrite(wordA, sizeof(char), 10, fs);
            fwrite(wordB, sizeof(char), 10, fs);
        }
        rewind(arq2); //fseek(arq2, 0L, SEEK_CUR);
    }

    fclose(arq1);
    fclose(arq2);
    fclose(fs);

    return;
}

int main(void){

    FILE * fs = fopen("c.bin", "wb");
    if(!fs) exit(1);
    fclose(fs);

    pares_ordenados("a.bin", "b.bin", "c.bin");
    return 0;
}