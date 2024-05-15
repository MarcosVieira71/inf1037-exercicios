#include <stdio.h>
#include <string.h>


int palindromo(char *s, int inicio, int fim);

int main(void){
    ///printf("%d\n", palindromo("oimeuNomeehreVieira"));
    printf("%d\n", palindromo("tenet", 0, strlen("tenet")-1));
    return 0;
}

int palindromo(char* s, int inicio, int fim){
    if(inicio >= fim){
        return 1;
    }
    if(s[inicio] != s[fim]) 
        return 0;
    return palindromo(s, inicio+1, fim -1);
}