#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trataLetraPrimeiraPos(char* linha){
    int tamanho = strlen(linha);
    int i;
    for(i = 0; i < tamanho; i++){
        if(*(linha + i) == '<') break;
    }
    char* linhaNova = (char*)malloc(sizeof(char)* i + 1);
    int j;
    for(j = 0; j < i; j++){
        linhaNova[j] = linha[j];
    }
    linhaNova[j] = '\n';
    linhaNova[j+1]= '\0';
    return linhaNova;
}

char* trataTagPrimeiraPos(char* linha){
    int tamanho = strlen(linha);
    int inicioTag = NULL;
    int fimTag = NULL;

    for(int i = 0; i < tamanho; i++){
        if(linha[i] == '<') inicioTag = i;
        else if(linha[i] == '>') fimTag = i;
        if(inicioTag != NULL && fimTag !=NULL)break;
    }
    if(tamanho == (fimTag - inicioTag + 2)){
        char* linhaNova = (char*)malloc(2);
        linhaNova[0] = '\n';
        linhaNova[1] = '\0';
        return linhaNova;
    }
    else{
        char *linhaNova = trataLetraPrimeiraPos(linha+fimTag+1);
        return linhaNova;
    }
}

char** geraNovoText(FILE* html, int* nLinhas){
    *nLinhas = 0;
    char textProvisorio[100];
    while(fgets(textProvisorio, 100, html) != NULL) (*nLinhas)++;
    char** textoNovo = (char**)malloc(sizeof(char*) * *nLinhas);
    fseek(html, 0, SEEK_SET);
    for(int i = 0; i < *nLinhas; i++){
        textoNovo[i] = (char*)malloc(100 * sizeof(char));
        fgets(textoNovo[i], 100, html);
        if(textoNovo[i][0] != '<'){
            textoNovo[i] = trataLetraPrimeiraPos(textoNovo[i]);
        }
        else if(textoNovo[i][0] == '<'){
            textoNovo[i] = trataTagPrimeiraPos(textoNovo[i]);
        }
        printf("%s", textoNovo[i]);
    }

}

int main(void){
    int nLinhas;
    FILE* html = fopen("dados.txt", "r");
    if(html == NULL) exit(1);
    geraNovoText(html, &nLinhas);
    return 0;
}