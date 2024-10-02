#include <stdio.h>

int main(void){
    int t;
    int puta = 1;

    scanf("%d", &t);
    while(t){
        int max = -1;
        int n;
        while(scanf("%d", &n)){
            if(n > max) max = n;
            char c;
            scanf("%c", &c);
            if(c == '\n') break;
        }
        printf("Case %d: %d\n", puta, max);
        puta++;
        t--;
    }
    return 0;
}