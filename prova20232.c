#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWordsUpper(char *s);

char* lastName(char *s);

int main(void){
    char nome[] = "  Marcos Paulo    Marinho Vieira  ";
    printf("\n\n%s", lastName(nome));
}



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

void printReverso(char** matriz, int tamanho){
    for(int i = tamanho-1; i>= 0; i--){
        printf(matriz[i]);
    }
}

void libera(char ** matriz, int tamanho){
    for(int i = tamanho-1; i>= 0; i--){
        free(matriz[i]);
    }
    free(matriz);
}