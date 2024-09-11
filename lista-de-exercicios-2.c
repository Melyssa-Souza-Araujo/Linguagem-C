//exercício 1

//while
#include <stdio.h>

int main() {
    int numero;
    int soma = 0;
    int contador = 0;
    
    while (1) {
        printf("Digite um número (0 para terminar): ");
        scanf("%d", &numero);
        
        if (numero == 0) {
            break;
        }
        
        if (numero % 2 == 0) {//colocar os números primeiro e depois coloque 0 para somar
            soma += numero;
            contador++;
        }
    }
    
    if (contador > 0) {
        double media = (double)soma / contador;
        printf("A média dos números pares digitados é: %.2f\n", media);
    } else {
        printf("Nenhum número par foi digitado.\n");
    }
    
    return 0;
}

//for
#include <stdio.h>

int main() {
    int numero;
    int soma = 0;
    int contador = 0;

    for (;;) {
        printf("Digite um número (0 para terminar): ");
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (numero % 2 == 0) {//colocar os números primeiro e depois coloque 0 para somar
            soma += numero;
            contador++;
        }
    }

    if (contador > 0) {
        double media = (double)soma / contador;
        printf("A média dos números pares digitados é: %.2f\n", media);
    } else {
        printf("Nenhum número par foi digitado.\n");
    }

    return 0;
}

// exercício 2

//while
#include <stdio.h>

int main() {
    int a, b, c, soma = 0, i;

    printf("Digite três números inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a <= 1) {
        printf("O valor do primeiro número deve ser maior que 1.\n");
        return 1; 
    }

    i = b;
    while (i <= c) {
        if (i % a == 0) {
            soma += i;
        }
        i++;
    }

    printf("A soma dos números entre %d e %d que são divisíveis por %d é: %d\n", b, c, a, soma);

    return 0;
}

//for

#include <stdio.h>

int main() {
    int a, b, c, soma = 0;

    printf("Digite três números inteiros: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a <= 1) {
        printf("O valor do primeiro número deve ser maior que 1.\n");
        return 1;
    }

    for (int i = b; i <= c; i++) {
        if (i % a == 0) {
            soma += i;
        }
    }

    printf("A soma dos números entre %d e %d que são divisíveis por %d é: %d\n", b, c, a, soma);

    return 0;
}

// ecercicio 3

//while

#include <stdio.h>

int main() {
    int numeros[3], i = 2;

    printf("Digite três números: ");
    for (int j = 0; j < 3; j++) {
        scanf("%d", &numeros[j]);
    }

    printf("Números na ordem inversa:\n");
    while (i >= 0) {
        printf("%d\n", numeros[i]);
        i--;
    }

    return 0;
}

//for

#include <stdio.h>

int main() {
    int numeros[3];

    printf("Digite três números: ");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Números na ordem inversa:\n");
    for (int i = 2; i >= 0; i--) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}