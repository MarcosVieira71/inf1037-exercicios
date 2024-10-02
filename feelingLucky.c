#include <stdio.h>

int main(void){
    int t;
    scanf("%d", &t);
    int c = 0;
    while(t){
        c += 1;
        int maxRating = 0;
        int ratings[10];
        char webUrls[10][101];
        int i;
        for(i = 0; i < 10; i++){
            scanf("%s %d", webUrls[i], &ratings[i]);
        }
        for(i = 0; i < 10; i++){
            if(ratings[i] > maxRating) maxRating = ratings[i];
        }
        printf("Case #%d:\n", c);
        for(i = 0; i < 10; i++){
            if(ratings[i] == maxRating) printf("%s\n", webUrls[i]);
        }
        t--;
    }
    return 0;
}