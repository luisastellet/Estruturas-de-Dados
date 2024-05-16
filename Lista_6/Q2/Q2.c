#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// (Q2) Escreva um programa em C que receba como entrada um arquivo binário de clientes
// “clientes.bin” e, sem ler todos os registros para memória, permita a consulta dos dados de um
// cliente em função do seu CPF. Considere que o formato de cada registro é dado pelos seguintes
// campos: nome – char (40), CPF – char(11), conta_corrente (int), agencia
// (int), saldo (float).

//0-39 (nome)
//40-50 (cpf)
//51-54 (conta) 3
//55-58 (agencia) 4
//59-62 (saldo) 4
//63-102
//40 endereços pro nome
//11 endereços pro cpf
//4 endereços pra conta_corrente
//4 endereços pra agencia
//4 endereços pro saldo

//na 1 vez pulo 40, nas proximas pulo 52
//quando achar, volta 40 e printa 64 bytes

void clientes(char * Arq){
    FILE * fp = fopen(Arq, "rb");
    if(!fp) exit(1);
    char cpf_ref[12], cpf_arq[12], nome[41];
    char conta[5], agencia[5];
    int r, tam, ver = 0;
    char saldo[5];

    // scanf("%s\n", cpf_ref);
    strcpy(cpf_ref, "12345678901");
    //teste
    // tam = ftell(fp);
    // printf("TAM %d\n", tam);
    // fread(cpf_arq, sizeof(char), 11, fp);
    // tam = ftell(fp);
    // printf("TAMM %d\n", tam);

    //cursor tá no endereço 0
    fseek(fp, 40, SEEK_CUR); //0+40
    r = fread(cpf_arq, sizeof(char), 11, fp); //to na 51
    if(r != 11) exit(1);
    
    while(r == 11){
        if(strcmp(cpf_ref, cpf_arq) == 0){
            ver = 1;
            break;
        } 
        printf("cpf: %s!\n", cpf_arq);
        // printf("tam: %d!!\n", tam);
        fseek(fp, 52, SEEK_CUR); //procuro o proximo cpf;
        r = fread(cpf_arq, sizeof(char), 11, fp);

    }

    //se chegar aqui e o r for 0, não achou, se for diferente, entrou no break
    if(ver){
        //li só o cpf
        fseek(fp, -51, SEEK_CUR); //subo pro inicio pra pegar cada item
        fread(nome, sizeof(char), 40, fp);
        //cpf_arq já tenho
        fread(conta, sizeof(char), 4, fp);
        fread(agencia, sizeof(char), 4, fp);
        fread(saldo, sizeof(char), 4, fp);
        printf("nome: %s\ncpf: %s\nconta: %s\nagencia: %s\nsaldo: %s\n", nome, cpf_arq, conta, agencia, saldo);
    }else printf("Pessoa nao encontrada!");

    fclose(fp);
    return;
}


int main(void){

    clientes("clientes.bin");
    return 0;
}