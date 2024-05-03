#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DADOS.c"

// (Q2) Implemente um algoritmo que receba como parâmetro de entrada, o nome de um arquivo
// texto, cujo conteúdo são o nome do aluno e as duas notas dos alunos do curso, uma em cada linha, e
// que ordene o arquivo de saída em ordem crescente pela média do aluno. Isto é, se eu tiver como
// entrada o arquivo: "P C/10.0/10.0-J J/3.0/4.0-G G/7.0/7.0-A A/0.5/1.5-I I/5.0/6.0", a
// saída será um arquivo com o seguinte texto: "A A/1.0-J J/3.5-I I/5.5-G G/7.0-P C/10.0" -
// void media(char *ArqEnt, char *ArqSaida).

// media ins_ordenado(media * l, int media){
//   if(!l || (media <= l->media)) return media_insere(l, media);
//   media * ant, * atual = l;
//   //se a media for maior que o primeiro, vai andando até achar
//   if(!atual -> prox){ // se só tiver um elemento
//     media * novo = (media*)malloc(sizeof(media));
//     novo->media = media;
//     atual->prox = novo;
//     novo->prox = NULL:
//   else{
//     ant = l;
//     atual = ant->prox;
//     while(1){
//       if(atual->media < media){
//         ant = atual;
//         atual = atual->prox;
//       }
//       else{
//         media *aux = (media*)malloc(sizeof(media));
//         aux->media = media;
//         ant->prox = aux;
//         novo->prox = atual;
//         break;
//       }
//     }
//   }
// }

DADOS * insere_ordenado(DADOS * l, DADOS * aluno){
  //não preciso alocar o nó, já aloquei ele na outra função
  if((!l) || (l->media >= aluno->media)){
    aluno->prox = l;
    l = aluno;
    return l;
  };
  l -> prox = insere_ordenado(l->prox, aluno);
  return l;
}

void media(char *ArqEnt, char *ArqSaida){
  FILE * fp = fopen(ArqEnt, "r");
  FILE * fs = fopen(ArqSaida, "w");
  if(!fp || !fs) exit(1);
  DADOS * lista = DADOS_inicializa();
  int r;

  while(1){
    DADOS * aluno = (DADOS*)malloc(sizeof(DADOS)); //preciso fazer isso várias vezes
    r = fscanf(fp, " %30[^/]/%f/%f", aluno->nome, &aluno->nota1, &aluno->nota2);
    if(r == 3){
      aluno->media = (aluno->nota1+aluno->nota2)/2;
      lista = insere_ordenado(lista, aluno);
    }else break;
  }

  //Agora estou com a lista preenchida e preciso escrever no arquivo
  DADOS * p = lista;
  while(p){
    r = fprintf(fs, "%s/%.1f/%.1f/ media: %.1f\n", p->nome, p->nota1, p->nota2, p->media);
    //se retornar valor negativo, houve erro
    if(r >= 0) p = p->prox;
    else break;
  }

  DADOS_libera(lista);

  fclose(fp);
  fclose(fs);
  return;
}


int main () {
  char dadosSaida[50];

  printf("digite o nome do arquivo de saida: \n");
  scanf("%s", dadosSaida);

  media("entrada-Q2", dadosSaida);

  return 0;
}