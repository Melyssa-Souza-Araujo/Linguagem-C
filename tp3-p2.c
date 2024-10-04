//tp3 p2 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_PESSOAS 10
#define MAX_NOME 100
#define MAX_RG 15
#define MAX_TELEFONE 15
#define MAX_ENDERECO 200
 
typedef struct {
    char nome[MAX_NOME];
    char rg[MAX_RG];
    char telefone[MAX_TELEFONE];
    char endereco[MAX_ENDERECO];
} Pessoa;
 
void gravar_em_arquivo(Pessoa pessoas[], int count) {
    FILE *file = fopen("dados_pessoas.csv", "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
 
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%s;%s\n", pessoas[i].nome, pessoas[i].rg, pessoas[i].telefone, pessoas[i].endereco);
    }
 
    fclose(file);
}
 
int main() {
    Pessoa pessoas[MAX_PESSOAS];
    int count = 0;
 
    while (1) {
        printf("Digite o nome (ou 'FIM' para finalizar): ");
        fgets(pessoas[count].nome, MAX_NOME, stdin);
        pessoas[count].nome[strcspn(pessoas[count].nome, "\n")] = 0; // Remove nova linha
 
        if (strcmp(pessoas[count].nome, "FIM") == 0 || strcmp(pessoas[count].nome, "fim") == 0) {
            break;
        }
 
        printf("Digite o RG: ");
        fgets(pessoas[count].rg, MAX_RG, stdin);
        pessoas[count].rg[strcspn(pessoas[count].rg, "\n")] = 0;
 
        printf("Digite o telefone: ");
        fgets(pessoas[count].telefone, MAX_TELEFONE, stdin);
        pessoas[count].telefone[strcspn(pessoas[count].telefone, "\n")] = 0;
 
        printf("Digite o endereço: ");
        fgets(pessoas[count].endereco, MAX_ENDERECO, stdin);
        pessoas[count].endereco[strcspn(pessoas[count].endereco, "\n")] = 0;
 
        count++;
 
        if (count == MAX_PESSOAS) {
            gravar_em_arquivo(pessoas, count);
            count = 0; // Limpa o acumulado
        }
    }
 
    // Grava os registros restantes, se houver
    if (count > 0) {
        gravar_em_arquivo(pessoas, count);
    }
 
    printf("Dados gravados com sucesso!\n");
    return 0;
}