#include <stdio.h>
 
int main() {
 
    while(1){
        int partidas, pilotos;
        scanf("%d %d", &partidas, &pilotos);
        if(pilotos == 0 && partidas == 0) break;;
        int vetPartidas[partidas][pilotos];
        
        for(int i = 0; i < partidas; i++){
            for(int j = 0; j < pilotos; j++){
                scanf("%d", &vetPartidas[i][j]);
            }
        }

        int numSistemas;
        scanf("%d", &numSistemas);
        for(int i = 0; i < numSistemas; i++){
            int vetorPontuacoesPiloto[pilotos];
            for(int j = 0; j < pilotos; j ++){
                vetorPontuacoesPiloto[j] = 0;
            }
            int ganhamPonto; 
            scanf("%d", &ganhamPonto);
            int vetPontosPorPosicao[ganhamPonto];
            for(int q = 0; q<ganhamPonto; q++){ 
                scanf("%d", &vetPontosPorPosicao[q]);
            }
            
            for (int k = 0; k < partidas; k++) {
                for (int j = 0; j < pilotos; j++) {
                    int posicaoPiloto = vetPartidas[k][j] - 1; 
                    if (posicaoPiloto < ganhamPonto) { 
                        vetorPontuacoesPiloto[j] += vetPontosPorPosicao[posicaoPiloto];
                    }
                }
            }

            int maiorPontuacao = 0;
            for (int j = 0; j < pilotos; j++) {
                if (vetorPontuacoesPiloto[j] > maiorPontuacao) {
                    maiorPontuacao = vetorPontuacoesPiloto[j];
                }
            }
            int primeiro = 1;
            for (int j = 0; j < pilotos; j++) {
                if (vetorPontuacoesPiloto[j] == maiorPontuacao) {
                    if (!primeiro) {
                        printf(" ");
                    }
                    printf("%d", j + 1);
                    primeiro = 0; 
                }
            }
            printf("\n");
        }
    }
    return 0;
}