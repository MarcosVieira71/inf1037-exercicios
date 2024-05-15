#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int countWordsUpper(char*s){
    if(*s == 0){
        return 0;
    }
    else{
        if('A' <= *s && *s <= 'Z'){
            return 1 + countWordsUpper(s+1);
        }
        else return 0 + countWordsUpper(s+1);
    }
}

char* lastName(char* s){
    int tamanho = strlen(s);
    int lastSpace;
    if(*(s + tamanho - 1) == ' '){
        for(lastSpace = tamanho-1; lastSpace >= 0; lastSpace--){
        if(*(s+lastSpace) == ' ' && *(s + lastSpace - 1) != ' '){
            *(s+lastSpace) = '\0';
            break;
        }
        }
        int i;
        for(i = lastSpace; *(s + i) != ' '; i--);
        return s+i+1;
    }
    else{
        for(lastSpace = tamanho -1; lastSpace >= 0; lastSpace--){
            if(*(s + lastSpace) == ' '){
                return s+lastSpace+1;
            }
        }
    }
}

void printReverso(char** matriz, int tamanho){
    for(int i = tamanho-1; i>= 0; i--){
        printf("%s", matriz[i]);
    }
}

void libera(char ** matriz, int tamanho){
    for(int i = tamanho-1; i>= 0; i--){
        free(matriz[i]);
    }
    free(matriz);
}

void formataLastName(char* lastName){
    int tamanhoLastName = strlen(lastName);
    int difMaiusculas = 'A' - 'a';
    for(int i = 1; i< tamanhoLastName; i++){
        lastName[i] += difMaiusculas;
    }
}
char* formataIniciais(char* nome){
    int tamanhoNome = strlen(nome);
    int qtdIniciais = countWordsUpper(nome);
    char* iniciais = (char*)malloc(qtdIniciais + qtdIniciais + 1);
    int j = 2;
    qtdIniciais -= 1;
    iniciais[0] = ',';
    iniciais[1] = ' ';
    for(int i = 0; i < tamanhoNome; i++){
            if(*(nome + i) >= 'A' && *(nome + i) <= 'Z'){
            iniciais[j] = *(nome +i);
            j++;
            iniciais[j] = '.';
            j++;
            qtdIniciais-=1;
        }
            if(qtdIniciais==0){
                break;
            }
    iniciais[j] = 0;
    }
    return iniciais;
}

char* formataNome(char*nome){
    char *iniciais = formataIniciais(nome);
    char *ultimoNome = lastName(nome);
    formataLastName(ultimoNome);
    char* nomeFormatado = strcat(ultimoNome, iniciais);
    free(iniciais);
    return nomeFormatado;
}

int main(void){
    char nome[] = "  Marcos Paulo Marinho   Vieira   ";
    char* nomeFormatado = formataNome(nome);
    printf("%s", nomeFormatado);
    return 0;
}