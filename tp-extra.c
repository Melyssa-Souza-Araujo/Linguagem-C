#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAMANHO 15

// Função para exibir o array de caracteres
void exibirArray(char array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

// Função para trocar dois elementos do array
void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Função para realizar a ordenação Bubble Sort
void bubbleSort(char array[], char array_M[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array_M[j] > array_M[j + 1]) {
                trocar(&array[j], &array[j + 1]);
                trocar(&array_M[j], &array_M[j + 1]);
            }
        }
    }
}

// Função para ler uma palavra do usuário
void lerPalavra(char palavra[], char palavra_M[], int tamanho_maximo) {
    printf("Digite uma palavra (até %d caracteres): ", tamanho_maximo);
    fgets(palavra, tamanho_maximo + 1, stdin);
    for (size_t i = 0; i < strlen(palavra); ++i) 
        palavra_M[i] = toupper( palavra[i] );

    // Remove o caractere de nova linha se presente
    palavra[strcspn(palavra, "\n")] = '\0';
}

// Função principal
int main() {
    char palavra[MAX_TAMANHO + 1]; // +1 para o caractere nulo
    int tamanho;
    char palavra_M[MAX_TAMANHO + 1];

    printf("Menu:\n");
    printf("1. Inserir e ordenar uma palavra\n");
    printf("2. Sair\n");
    printf("Escolha uma opção: ");
    
    int opcao;
    scanf("%d", &opcao);
    getchar(); // Limpar o caractere de nova linha do buffer de entrada

    switch (opcao) {
        case 1:
            // Ler a palavra do usuário
            lerPalavra(palavra, palavra_M, MAX_TAMANHO);

            // Calcular o tamanho da palavra
            tamanho = strlen(palavra);

            // Verifica se o tamanho é válido
            if (tamanho > 0 && tamanho <= MAX_TAMANHO) {
                printf("\nPalavra antes da ordenação:\n");
                exibirArray(palavra, tamanho);

                // Ordena a palavra
                bubbleSort(palavra, palavra_M, tamanho);

                printf("\nPalavra após a ordenação:\n");
                exibirArray(palavra, tamanho);
            } else {
                printf("Palavra inválida. O tamanho deve ser de até %d caracteres.\n", MAX_TAMANHO);
            }
            break;

        case 2:
            printf("Saindo do programa.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
    }

    return 0;
}
