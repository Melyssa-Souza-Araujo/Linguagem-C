#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAMANHO 15

void exibirArray(char array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(char array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                trocar(&array[j], &array[j + 1]);
            }
        }
    }
}

// Função para inicializar o array pré-definido
void inicializarArrayPredefinido(char array[]) {
    char palavraPredefinida[] = "MELYSSA";
    strcpy(array, palavraPredefinida);
}

// Função para ler uma palavra do usuário ou usar a pré-definida
void lerOuUsarPredefinida(char palavra[], int tamanho_maximo) {
    int opcao;
    printf("Deseja usar a palavra predefinida (1) ou inserir uma nova (2)? ");
    scanf("%d", &opcao);
    getchar(); 

    if (opcao == 1) {
        inicializarArrayPredefinido(palavra);
    } else {
        printf("Digite uma palavra (até %d caracteres): ", tamanho_maximo);
        fgets(palavra, tamanho_maximo + 1, stdin);
        palavra[strcspn(palavra, "\n")] = '\0'; 
    }
}

int main() {
    char palavra[MAX_TAMANHO + 1];
    int tamanho;

    lerOuUsarPredefinida(palavra, MAX_TAMANHO);

    tamanho = strlen(palavra);

    for (int i = 0; i < tamanho; i++) {
        palavra[i] = toupper(palavra[i]);
    }

    if (tamanho > 0 && tamanho <= MAX_TAMANHO) {
        printf("\nPalavra antes da ordenação:\n");
        exibirArray(palavra, tamanho);

        bubbleSort(palavra, tamanho);

        printf("\nPalavra após a ordenação:\n");
        exibirArray(palavra, tamanho);
    } else {
        printf("Palavra inválida. O tamanho deve ser de até %d caracteres.\n", MAX_TAMANHO);
    }

    return 0;
}
