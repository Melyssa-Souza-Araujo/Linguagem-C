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

    printf("Digite a marca do carro: ");
    scanf("%s", c.marca);
    printf("Digite o ano de fabricação: ");
    scanf("%d", &c.ano_fabricacao);
    printf("Digite a cor do carro: ");
    scanf("%s", c.cor);
    printf("Digite o preço: ");
    scanf("%f", &c.preco);

    printf("\n--- Relatório do Carro ---\n");
    printf("Marca: %s\n", c.marca);
    printf("Ano de Fabricação: %d\n", c.ano_fabricacao);
    printf("Cor: %s\n", c.cor);
    printf("Preço: R$ %.2f\n", c.preco);

    return 0;
}

//questão 3

#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

struct Contato {
    char nome[50];
    char email[50];
    char telefone[15];
};

void adicionarContato(struct Contato contatos[], int *contagem) {
    if (*contagem < MAX_CONTATOS) {
        printf("Digite o nome: ");
        scanf(" %[^\n]", contatos[*contagem].nome);
        printf("Digite o email: ");
        scanf(" %[^\n]", contatos[*contagem].email);
        printf("Digite o telefone: ");
        scanf(" %[^\n]", contatos[*contagem].telefone);
        (*contagem)++;
    } else {
        printf("Agenda cheia!\n");
    }
}

void exibirContatos(struct Contato contatos[], int contagem) {
    if (contagem == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }
    
    printf("\n--- Lista de Contatos ---\n");
    for (int i = 0; i < contagem; i++) {
        printf("Nome: %s\n", contatos[i].nome);
        printf("Email: %s\n", contatos[i].email);
        printf("Telefone: %s\n", contatos[i].telefone);
        printf("--------------------------\n");
    }
}

int main() {
    struct Contato contatos[MAX_CONTATOS];
    int contagem = 0;
    int opcao;

    do {
        printf("\n--- Menu da Agenda ---\n");
        printf("1. Adicionar Contato\n");
        printf("2. Exibir Contatos\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &contagem);
                break;
            case 2:
                exibirContatos(contatos, contagem);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

//questão 4

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    char email[50];
};

void ler_pessoa(struct Pessoa *p) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    printf("Digite o email: ");
    scanf(" %[^\n]", p->email);
}

void mostrar_pessoa(const struct Pessoa *p) {
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Email: %s\n", p->email);
}

int main() {
    struct Pessoa pessoa;

    ler_pessoa(&pessoa);
    mostrar_pessoa(&pessoa);

    return 0;
}

//questão 5

#include <stdio.h>

struct Endereco {
    char rua[100];
    int numero;
    char cidade[50];
};

struct Pessoa {
    char nome[50];
    int idade;
    struct Endereco endereco;  // Estrutura aninhada
};

void ler_pessoa(struct Pessoa *p) {
    printf("Digite o nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    printf("Digite a rua: ");
    scanf(" %[^\n]", p->endereco.rua);
    printf("Digite o número: ");
    scanf("%d", &p->endereco.numero);
    printf("Digite a cidade: ");
    scanf(" %[^\n]", p->endereco.cidade);
}

void mostrar_pessoa(const struct Pessoa *p) {
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Endereço: %s, %d, %s\n", p->endereco.rua, p->endereco.numero, p->endereco.cidade);
}

int main() {
    struct Pessoa pessoa;

    ler_pessoa(&pessoa);
    mostrar_pessoa(&pessoa);

    return 0;
}
