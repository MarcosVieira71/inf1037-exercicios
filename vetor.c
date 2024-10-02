#include <stdio.h>
 
int main() {
    int v[20];
    for(int i = 0; i < 20; i++){
        scanf("%d", &v[i]);
    }
    int fim = 19;
    for(int i = 0; i < 10; i++){
        int temp = v[i];
        v[i] = v[fim];
        v[fim] = temp;
        fim = fim - 1;
    }
    for(int i = 0; i < 20; i++){
        printf("N[%d] = %d", i, v[i]);
    }
    return 0;
}