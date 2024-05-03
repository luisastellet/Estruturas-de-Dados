#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q2) Implemente um algoritmo que receba como parâmetro de entrada, o nome de um arquivo
// texto, cujo conteúdo são o nome do aluno e as duas notas dos alunos do curso, uma em cada linha, e
// que ordene o arquivo de saída em ordem crescente pela média do aluno. Isto é, se eu tiver como
// entrada o arquivo: "P C/10.0/10.0-J J/3.0/4.0-G G/7.0/7.0-A A/0.5/1.5-I I/5.0/6.0", a
// saída será um arquivo com o seguinte texto: "A A/1.0-J J/3.5-I I/5.5-G G/7.0-P C/10.0" -
// void media(char *ArqEnt, char *ArqSaida).

typedef struct Q2
{
  float nota1;
  float nota2;
  float media;
  char letra1[3];
  char letra2[3];
} DADOS;


void media(char *ArqEnt, char *ArqSaida){
  FILE * fp = fopen(ArqEnt, "r");
  FILE * fs = fopen(ArqSaida, "w");
  if(!fp || !fs) exit(1);

  int r1, r2, linhas = 0;
  DADOS * aluno = (DADOS**)malloc(sizeof(DADOS*)); 

  while(fgets())


  do{
    r = fscanf(fp, " %c %c/%f/%f\n", &aluno->letra1, &aluno->letra2, &aluno->nota1, &aluno->nota2);
    aluno->media = (aluno->nota1+aluno->nota2)/2;
    linhas++;
  }while(r == 3); //enquanto houver coisa no arquivo (estou lendo 3 coisas)
  


}


int main () {
  char dadosEntrada[50], dadosSaida[50], aux[50];

  printf("digite o nome do arquivo de saida: \n");
  scanf("%s", dadosSaida);

  media("entrada-Q1.txt", dadosSaida);

  return 0;
}