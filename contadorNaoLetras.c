#include <stdio.h>

int contaNaoLetras(char* s){
    if(*s == 0)return 0;
    else{
        if((*s > 'z' || 'a' > *s) && (*s > 'Z' || *s < 'A')) return 1 + contaNaoLetras(s+1);
        return contaNaoLetras(s+1);
    }
    }

int main(void){
    char s[11] = "T@CaLLIOPE9";
    printf("%d\n", contaNaoLetras(s));
    return 0;
}