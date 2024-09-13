//somar
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

//subtrair
#include <stdio.h>
 
int main() {
    int linhas, colunas;
 
    printf("Digite o número de linhas e colunas das matrizes: ");
    scanf("%d %d", &linhas, &colunas);
 
    int matriz1[linhas][colunas], matriz2[linhas][colunas], resultado[linhas][colunas];
 
    printf("\nDigite os elementos da primeira matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }
 
    printf("\nDigite os elementos da segunda matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }
 
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = matriz1[i][j] - matriz2[i][j];
        }
    }
 
    printf("\nMatriz resultante da subtração:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}

//multiplicação

#include <stdio.h>
 
#define MAX 10
 
void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    if (columnFirst != rowSecond) {
        printf("Erro: O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda matriz.\n");
        return;
    }
 
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            result[i][j] = 0;
        }
    }
 
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            for (int k = 0; k < columnFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}
 
int main() {
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];
    int rowFirst, columnFirst, rowSecond, columnSecond;
 
    printf("Digite o número de linhas e colunas da primeira matriz: ");
    scanf("%d %d", &rowFirst, &columnFirst);
 
    printf("Digite os elementos da primeira matriz:\n");
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnFirst; j++) {
            scanf("%d", &first[i][j]);
        }
    }
 
    printf("Digite o número de linhas e colunas da segunda matriz: ");
    scanf("%d %d", &rowSecond, &columnSecond);
 
    printf("Digite os elementos da segunda matriz:\n");
    for (int i = 0; i < rowSecond; i++) {
        for (int j = 0; j < columnSecond; j++) {
            scanf("%d", &second[i][j]);
        }
    }
 
    multiplyMatrices(first, second, result, rowFirst, columnFirst, rowSecond, columnSecond);
 
    printf("Matriz resultado:\n");
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < columnSecond; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}