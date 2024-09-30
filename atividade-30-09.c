#include <stdio.h>
#include <string.h>

struct Funcionario {
    int registro;
    float salario;
    char nome[30];
};

int main() {
    struct Funcionario f;

    printf("Digite o registro: ");
    scanf("%d", &f.registro);
    printf("Digite o salario: ");
    scanf("%f", &f.salario);
    printf("Digite o nome: ");
    scanf(" %[^\n]", f.nome); 

    printf("\nRegistro: %d\n", f.registro);
    printf("Salario: %.2f\n", f.salario);
    printf("Nome: %s\n", f.nome);

    return 0;
}
