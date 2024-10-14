#include <stdio.h>

int busca_binaria(int vetor[], int valor, int tamanho) {
    int baixo = 0;
    int alto = tamanho - 1;
    int meio;

    while (baixo <= alto) {
        meio = (alto + baixo) / 2;

        printf("Baixo %d Meio %d Alto %d\n", baixo, meio, alto);
        
        if (vetor[meio] == valor) {
            return meio;  // Retorna o índice encontrado
        } else if (vetor[meio] > valor) {
            alto = meio - 1;  // Busca na metade inferior
        } else {
            baixo = meio + 1;  // Busca na metade superior
        }
    }

    return -1;  // Retorna -1 se não encontrar
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15}; // Exemplo de vetor ordenado
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valor = 7; // Valor a ser buscado

    int resultado = busca_binaria(vetor, valor, tamanho);

    if (resultado != -1) {
        printf("Valor %d encontrado no índice %d.\n", valor, resultado);
    } else {
        printf("Valor %d não encontrado.\n", valor);
    }

    return 0;
}
