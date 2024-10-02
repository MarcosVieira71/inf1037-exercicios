#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void){
    int t; 
    scanf("%d", &t);
    char countries[t][76];
    int i;
    char garb[120];
    for(i = 0; i < t; i++){
        scanf("%s %[^\n]", countries[i], garb);
        }

    for(i = 0; i < t;){
        int j;
        int count = 1;
        for(j = i + 1; strcmp(countries[j], countries[i]) == 0; j++){
            count += 1;
        }
        printf("%s %d\n", countries[i], count);
        i = j;
        }
    return 0;
}
