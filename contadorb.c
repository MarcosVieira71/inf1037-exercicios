#include <stdio.h>
int tamanho(char* s){
    int i;
    for(i = 0; s[i] != 0; i++);
    return i;
}

int contaB(char* s, int* bzinhos){
    *bzinhos = 0;
    int bZoes = 0;
    int n = tamanho(s);
    for(int i = 0; i < n; i++){
        if(*(s + i) == 'b'){
            *bzinhos +=1;
        }
        else if(*(s+i) =='B'){
            bZoes+=1;
        }
    }
    return bZoes;
}

int main(void){
    char bluble[15] = "bbbBBBbbBBBB";
    int bzinhos;
    int Bzoes = contaB(bluble, &bzinhos);
    printf("%d %d\n", bzinhos, Bzoes);
    return 0;
}