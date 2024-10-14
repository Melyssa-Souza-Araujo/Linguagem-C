#include <stdio.h>

int busca_sequencial(int vetor[], int valor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        // Imprime a tentativa atual
        printf("Tentando índice %d (valor: %d)\n", i, vetor[i]);
        
        if (vetor[i] == valor) {
            return i;  // Retorna o índice encontrado
        }
    }
    return -1;  // Retorna -1 se não encontrar
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15}; // Exemplo de vetor
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 7; // Valor a ser buscado

    int resultado = busca_sequencial(vetor, valor, tamanho);

    if (resultado != -1) {
        printf("Valor %d encontrado no índice %d.\n", valor, resultado);
    } else {
        printf("Valor %d não encontrado.\n", valor);
    }

    return 0;
}
