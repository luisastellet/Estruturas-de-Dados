#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q1) Desenvolva um procedimento que receba o nome de um arquivo texto e retire deste texto
// palavras consecutivas repetidas. O seu programa deve retornar, no arquivo de saída, informado
// como parâmetro dessa função, a resposta desta questão. Por exemplo, se o conteúdo de um arquivo
// texto for: "Isto e um texto texto repetido repetido repetido . Com as repeticoes
// repeticoes fica fica sem sem sentido . Sem elas elas elas melhora melhora um um
// pouco .", a saída do seu programa será um arquivo com o seguinte texto: "Isto e um texto
// repetido . Com as repeticoes fica sem sentido . Sem elas melhora um um pouco ."
// - void RetRepet(char *ArqEnt, char *ArqSaida).

void RetRepet(char *ArqEnt, char *ArqSaida){
    FILE *fp = fopen(ArqEnt, "r");
    FILE *fs = fopen(ArqSaida, "w");
    if (!fp || !fs) exit(1);
    char anterior[50];
    char atual[50];

    strcpy(anterior, "init");
    int r = 1; // vai acompanhar se o arquivo ainda tem coisa 
    while(r == 1){ //enquanto tiver coisa no arquivo
        r = fscanf(fp, "%s ", atual); //não coloco &atual pq atual é string
        // retorna -1 se anterior for menor
        // retorna 0 se forem iguais
        // retorna 1 se anterior for maior
        if(strcmp(anterior, atual) != 0){ //são diferentes
            fprintf(fs, "%s ", atual);
        }
        strcpy(anterior, atual); //é destino, origem
    }

    fclose(fp);
    fclose(fs);
    return;
}

// int main(int argc, char **argv){
//     int i, x = atoi(argv[1]);
//     printf("%d\n", x);
//     for(i = 0; i < argc; i++)
//         printf("argv[%d] = %s\n", i, argv[i]);

//     return 0;
// }

int main () {
    char dadosEntrada[50], dadosSaida[50], aux[50];
    int valor;

    printf("digite quantas palavras deseja digitar no arquivo: \n");
    scanf("%d", &valor);

    printf("digite o nome do arquivo de entrada: \n");
    scanf("%s", dadosEntrada);
 
    printf("digite o nome do arquivo de saida: \n");
    scanf("%s", dadosSaida);

    FILE *arqDados = fopen(dadosEntrada, "w");
    if(!arqDados) exit(1);

    for(int i = 0; i < valor; i++){
        scanf("%s", aux);
        fprintf(arqDados, "%s ", aux);
    }

    fclose(arqDados);

    RetRepet(dadosEntrada, dadosSaida);

    return 0;
}