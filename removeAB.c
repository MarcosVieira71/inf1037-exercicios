#include <stdio.h>
#include <string.h>

void removedorSequencia(char*s){
    int tamanho = strlen(s);
    for(int i = 0; i < tamanho; i++){
        if(*(s + i) == 'A' &&  *(s+i+1) == 'B'){
            *(s+i) = ' ';
            *(s+1+i) = ' ';
        }
    }
}

int main(void){
    char s[] = "ABABABABAJKKKKBPUTZ\n";
    removedorSequencia(s);
    printf("%s", s);
    return 0;
}