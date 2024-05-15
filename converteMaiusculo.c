#include <stdio.h>

void maiusculo(char*s, char c){
    if(*s == 0){
        return;
    }
    else{
        if (*s != c){
            maiusculo(s+1, c);
        }
        else{
            int dif = 'A' - 'a';
            *s += dif;
            maiusculo(s+1, c);
            }
        }
    }

int main(void){
    char s[11] = "testeTeste";
    maiusculo(s, 't');
    printf("%s\n", s);
    return 0;
}