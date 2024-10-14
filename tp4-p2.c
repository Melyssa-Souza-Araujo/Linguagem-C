#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define TAM_VETOR 20
 
void gerar_vetor_aleatorio(int vetor[], int tamanho) {
    int num;
    int i = 0;
    int encontrado;
    srand(time(NULL)); 
    
    while (i < tamanho) {
        num = rand() % 1001;
        encontrado = 0;
        for (int j = 0; j < i; j++) {
            if (vetor[j] == num) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            vetor[i] = num;
            i++;
        }
    }
}
 
int busca_sequencial(int vetor[], int valor, int tamanho, int *iteracoes) {
    for (int i = 0; i < tamanho; i++) {
        (*iteracoes)++;
        printf("Busca Sequencial: Tentando índice %d (valor: %d)\n", i, vetor[i]);
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}
 
int busca_binaria(int vetor[], int valor, int tamanho, int *iteracoes) {
    int baixo = 0;
    int alto = tamanho - 1;
    int meio;
 
    while (baixo <= alto) {
        (*iteracoes)++;
        meio = (alto + baixo) / 2;
        printf("Busca Binária: Baixo %d, Meio %d (valor: %d), Alto %d\n", baixo, meio, vetor[meio], alto);
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] > valor) {
            alto = meio - 1;
        } else {
            baixo = meio + 1;
        }
    }
 
    return -1; 
}
 
void ordenacao_selecao(int vetor[], int tamanho, int *iteracoes) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            (*iteracoes)++;
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        
        int temp = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = temp;
        printf("Ordenação: Troca entre %d e %d\n", vetor[i], vetor[menor]);
    }
}
 
int main() {
    int vetor[TAM_VETOR];
    gerar_vetor_aleatorio(vetor, TAM_VETOR);
 
    printf("Vetor gerado:\n");
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
 
    int iteracoes_seq = 0;
    int valor_busca = vetor[rand() % TAM_VETOR]; /
    printf("\nBuscando %d com busca sequencial...\n", valor_busca);
    int resultado_seq = busca_sequencial(vetor, valor_busca, TAM_VETOR, &iteracoes_seq);
    if (resultado_seq != -1) {
        printf("Busca Sequencial: Valor %d encontrado no índice %d.\n", valor_busca, resultado_seq);
    } else {
        printf("Busca Sequencial: Valor %d não encontrado.\n", valor_busca);
    }
    printf("Total de iterações na busca sequencial: %d\n", iteracoes_seq);
 
    int iteracoes_ord = 0;
    ordenacao_selecao(vetor, TAM_VETOR, &iteracoes_ord);
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nTotal de iterações na ordenação: %d\n", iteracoes_ord);
 
    int iteracoes_bin = 0;
    printf("\nBuscando %d com busca binária...\n", valor_busca);
    int resultado_bin = busca_binaria(vetor, valor_busca, TAM_VETOR, &iteracoes_bin);
 
    if (resultado_bin != -1) {
        printf("Busca Binária: Valor %d encontrado no índice %d.\n", valor_busca, resultado_bin);
    } else {
        printf("Busca Binária: Valor %d não encontrado.\n", valor_busca);
    }
    printf("Total de iterações na busca binária: %d (incluindo iterações de ordenação: %d)\n", iteracoes_bin + iteracoes_ord, iteracoes_ord);
 
    clock_t start, end;
    double tempo_seq, tempo_bin;
    start = clock();
    busca_sequencial(vetor, valor_busca, TAM_VETOR, &iteracoes_seq);
    end = clock();
    tempo_seq = ((double)(end - start)) / CLOCKS_PER_SEC;
    start = clock();
    busca_binaria(vetor, valor_busca, TAM_VETOR, &iteracoes_bin);
    end = clock();
    tempo_bin = ((double)(end - start)) / CLOCKS_PER_SEC;
 
    printf("\nTempo da busca sequencial: %.6f segundos\n", tempo_seq);
    printf("Tempo da busca binária: %.6f segundos\n", tempo_bin);
 
    if (tempo_seq < tempo_bin) {
        printf("Busca Sequencial foi mais eficiente em termos de tempo.\n");
    } else {
        printf("Busca Binária foi mais eficiente em termos de tempo.\n");
    }
 
    return 0;
}