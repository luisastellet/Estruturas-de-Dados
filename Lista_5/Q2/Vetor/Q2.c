#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Q2
{
  float nota1;
  float nota2;
  float media;
  char nome[31];
} DADOS;

// (Q2) Implemente um algoritmo que receba como parâmetro de entrada, o nome de um arquivo
// texto, cujo conteúdo são o nome do aluno e as duas notas dos alunos do curso, uma em cada linha, e
// que ordene o arquivo de saída em ordem crescente pela média do aluno. Isto é, se eu tiver como
// entrada o arquivo: "P C/10.0/10.0-J J/3.0/4.0-G G/7.0/7.0-A A/0.5/1.5-I I/5.0/6.0", a
// saída será um arquivo com o seguinte texto: "A A/1.0-J J/3.5-I I/5.5-G G/7.0-P C/10.0" -
// void media(char *ArqEnt, char *ArqSaida).

int compara(const void * media1, const void * media2){ //sempre precisa de um ponteiro
    DADOS * a = (DADOS*)media1; //ponteiro para vet[i]
    DADOS * b = (DADOS*)media2;

    if(a->media < b->media) return -1;
    else if(a->media > b->media) return 1;
    return 0;
}

void media(char *ArqEnt, char *ArqSaida){
    FILE * fp = fopen(ArqEnt, "r");
    FILE * fs = fopen(ArqSaida, "w");
    if(!fp || !fs) exit(1);

    //DADOS * aluno = (DADOS*)malloc(sizeof(DADOS));
    //if(!aluno) exit(1);
    DADOS aluno;

    int cont = 0;
    while(fscanf(fp, "%30[^/]/%f/%f\n", aluno.nome, &aluno.nota1, &aluno.nota2) == 3){
        cont++;
    }

    DADOS * vetor = (DADOS*)malloc(sizeof(DADOS)*cont);
    rewind(fp);
    // if(!vetor) exit(1);
    // fclose(fp);
    // fp = fopen(ArqEnt, "r");
    // if(!fp) exit(1);

    int i = 0;
    while(fscanf(fp, "%30[^/]/%f/%f\n", aluno.nome, &aluno.nota1, &aluno.nota2) == 3){
        strcpy(vetor[i].nome, aluno.nome);
        vetor[i].nota1 = aluno.nota1;
        vetor[i].nota2 = aluno.nota2;
        vetor[i].media = (aluno.nota1 + aluno.nota2)/2;
        i++;
    }

    qsort(vetor, cont, sizeof(DADOS), compara);
    // for(int j = 0; j<cont; j++){
    //     printf("%s/%.1f/%.1f/ media %.1f", vetor[j].nome, vetor[j].nota1, vetor[j].nota2, vetor[j].media);
    // }

    //while(!feof(fp)) tem q usar um fprintf ou fscanf dentro, pq ele não anda ocm o cursor
    
    for(int j=0; j<cont; j++){
        fprintf(fs, "%s/%.1f/%.1f/ media: %.1f\n", vetor[j].nome, vetor[j].nota1, vetor[j].nota2, vetor[j].media);
    }

    fclose(fp);
    fclose(fs);
    free(vetor);
    return;
}


int main () {
  char dadosSaida[50];

  printf("digite o nome do arquivo de saida: \n");
  scanf("%s", dadosSaida);

  media("entrada-Q2", dadosSaida);

  return 0;
}