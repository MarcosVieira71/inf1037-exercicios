#include <stdio.h>
#include <stdlib.h>

int conta(char* s) {
    int i;
    for (i = 0; *(s + i) != 0; i++);
    return i;
}

void copia(char* s, char* t) {
    int tamanhoT = conta(t);
    int i;
    for (i = 0; i < tamanhoT; i++) {
    *(s + i) = *(t + i);
    }
    *(s + i) = 0; 
}

char* concatena(char* s, char* t) {
    int tamanhoS = conta(s);
    int tamanhoT = conta(t);
    char* cat = (char*)malloc(tamanhoS + tamanhoT + 1);
    if (cat == NULL) exit(2);
    copia(cat, s);
    int i, j = 0;
    for (i = tamanhoS; i < tamanhoT + tamanhoS; i++) {
    *(cat + i) = *(t + j);
    j++;
    }
    *(cat + i) = 0;
    return cat;
}


char* geraIdentidade(char* nome, char* nomeMae, char* data) {
    int contaEspaco = 0;
    int tamanhoNome = conta(nome);
    for (int i = 0; i < tamanhoNome; i++) {
        if (*(nome + i) == ' ') contaEspaco += 1;
    }
    char* iniciais = (char*)malloc(contaEspaco + 2);
    if (iniciais == NULL) exit(2);
    *(iniciais + contaEspaco + 1) = '\0';
    for (int i = tamanhoNome - 1; i >= 0; i--) {
        if (*(nome + i) == 32) {
        *(iniciais + contaEspaco) = *(nome + i + 1);
        contaEspaco--;
        }
    }
    *iniciais = *nome;


    char* dataSem = (char*)malloc(9);
    if (dataSem == NULL) exit(2);
    int j = 0;
    int tamanhoData = conta(data);
    for (int i = 0; i < tamanhoData; i++) {
        if (*(data + i) != '/') {
        *(dataSem + j) = *(data + i);
        j++;
        }
    }
    *(dataSem + j) = 0;
    char caracteresSpeciais[] = " * ";
    char* identidade = concatena(dataSem,iniciais);
    identidade = concatena(identidade, caracteresSpeciais);
    identidade = concatena(identidade, nomeMae);
    return identidade;
}
char** montaVetor(FILE *fp, int* nCand){
    *nCand = 0;
    char nomeMae[50], nome[50], data[50];
    while(fscanf(fp, " %[^ ] %[^ ] %[^\n]", nomeMae, data, nome) == 3){
        *nCand += 1;
    }
    fseek(fp, 0, SEEK_SET);
    char** vetorNovo = (char**)malloc(sizeof(char*) * *nCand);
    for(int i = 0; i < *nCand; i++){
        fscanf(fp, " %[^ ] %[^ ] %[^\n]", nomeMae, data, nome);
        *(vetorNovo+i) = geraIdentidade(nome, nomeMae, data);
    }
    return vetorNovo;
}


int main(void) {
FILE* fp = fopen("dados.txt", "r");
if (fp == NULL) exit(1);
int nCand;
char** matriz = montaVetor(fp, &nCand);
for(int i = 0; i< nCand; i++){
    printf("%s\n", matriz[i]);
}
return 0;
}

