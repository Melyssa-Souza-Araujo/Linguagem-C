#include <stdio.h>
 
int main() {
    int linhas, colunas;
 
    printf("Digite o número de linhas e colunas das matrizes: ");
    scanf("%d %d", &linhas, &colunas);
 
    int matrizA[linhas][colunas], matrizB[linhas][colunas], matrizC[linhas][colunas];
 
    printf("\nDigite os elementos da matriz A:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }
 
    printf("\nDigite os elementos da matriz B:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }
 
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
 
    printf("\nA matriz resultante da soma é:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matrizC[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}