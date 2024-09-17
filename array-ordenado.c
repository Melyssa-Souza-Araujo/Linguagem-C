#include <stdio.h>

void imprimirArray(char arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void trocar(char *xp, char *yp) {
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(char arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    char arr[] = {'m', 'e', 'l', 'y', 's', 's', 'a'};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    imprimirArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    imprimirArray(arr, n);

    return 0;
}