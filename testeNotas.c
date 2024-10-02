#include <stdio.h>
 
int main() {
    int qtdNotas[] = {0,0,0,0,0,0};
    int qtdMoedas[] = {0,0,0,0,0,0};
    float notas[] = {100.00f, 50.00f, 20.00f, 
                    10.00f, 5.00f, 2.00f};
    float moedas[] = {1.00f, 0.50f, 0.25f, 
                    0.10f, 0.05f, 0.01f};
    
    float val = 0;
    scanf("%f", &val);
    int idxMoedas = 0;
    int idxNotas = 0;

    while(val > 0.001f){
        if(idxNotas <= 5){
            if(val >= notas[idxNotas]){
                val -= notas[idxNotas];
                qtdNotas[idxNotas]++;
            }
            else idxNotas++;
        }
        else{
            if(val >= moedas[idxMoedas]){
                val -= moedas[idxMoedas];
                qtdMoedas[idxMoedas]++;
            }
            else idxMoedas++;
        }
    }
    printf("NOTAS:\n");
    for(int i = 0; i <= 5; i++){
        printf("%d nota(s) de R$ %.2f\n", qtdNotas[i], notas[i]);
    }
    
    printf("MOEDAS:\n");
    for(int i = 0; i <= 5; i++){
        printf("%d moeda(s) de R$ %.2f\n", qtdMoedas[i], moedas[i]);
    }
    
    return 0;
}