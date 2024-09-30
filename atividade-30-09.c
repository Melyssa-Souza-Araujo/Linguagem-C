//questão 1
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

//questão 2

#include <stdio.h>

struct Carro {
    char marca[30];
    int ano_fabricacao;
    char cor[20];
    float preco;
};

int main() {
    struct Carro c;

    // Atribuindo valores aos campos
    printf("Digite a marca do carro: ");
    scanf("%s", c.marca);
    printf("Digite o ano de fabricação: ");
    scanf("%d", &c.ano_fabricacao);
    printf("Digite a cor do carro: ");
    scanf("%s", c.cor);
    printf("Digite o preço: ");
    scanf("%f", &c.preco);

    // Imprimindo relatório
    printf("\n--- Relatório do Carro ---\n");
    printf("Marca: %s\n", c.marca);
    printf("Ano de Fabricação: %d\n", c.ano_fabricacao);
    printf("Cor: %s\n", c.cor);
    printf("Preço: R$ %.2f\n", c.preco);

    return 0;
}
