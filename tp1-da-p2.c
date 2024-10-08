//TP1 da P2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_ADDRESS 200
#define MAX_ATTRATIVES 200
#define MAX_EMAIL 100

// Estruturas de dados 
typedef struct {
    char nome[MAX_NAME];
    char rg[15];
    char data_nascimento[11];
    char email[MAX_EMAIL];
} Viajante;

typedef struct {
    char nome[MAX_NAME];
    char endereco[MAX_ADDRESS];
} Local;

typedef struct {
    int id;
    Local destino;
    Local origem;
    char atrativos[MAX_ATTRATIVES];
    float valor;
    char data[11]; // Formato DD/MM/AAAA
    Viajante viajante;
    char status[MAX_NAME]; // Ex: "pago", "cancelado", "pendente"
} Viagem;

//Função para inserir dados da viagem
void inserir_viagem(Viagem *viagem) {
    printf("Insira o ID da viagem: ");
    scanf("%d", &viagem->id);
    getchar(); // Limpar o buffer
    
    printf("Insira o nome do local de destino: ");
    fgets(viagem->destino.nome, MAX_NAME, stdin);
    viagem->destino.nome[strcspn(viagem->destino.nome, "\n")] = 0; // Remover nova linha
    
    printf("Insira o endereço do local de destino: ");
    fgets(viagem->destino.endereco, MAX_ADDRESS, stdin);
    viagem->destino.endereco[strcspn(viagem->destino.endereco, "\n")] = 0;
    
    printf("Insira os atrativos: ");
    fgets(viagem->atrativos, MAX_ADDRESS, stdin);
    viagem->atrativos[strcspn(viagem->atrativos, "\n")] = 0;
    
    printf("Insira o nome do local de origem: ");
    fgets(viagem->origem.nome, MAX_ADDRESS, stdin);
    viagem->origem.nome[strcspn(viagem->origem.nome, "\n")] = 0;
    
    printf("Insira o endereço do local de origem: ");
    fgets(viagem->origem.endereco, MAX_ADDRESS, stdin);
    viagem->origem.endereco[strcspn(viagem->origem.endereco, "\n")] = 0;
    
    printf("Insira o valor da viagem: ");
    scanf("%f", &viagem->valor);
    getchar(); // Limpar o buffer
    
    printf("Insira a data da viagem (DD/MM/AAAA): ");
    fgets(viagem->data, 11, stdin);
    viagem->data[strcspn(viagem->data, "\n")] = 0;
    
    printf("Insira o nome do viajante: ");
    fgets(viagem->viajante.nome, MAX_ADDRESS, stdin);
    viagem->viajante.nome[strcspn(viagem->viajante.nome, "\n")] = 0;
    
    printf("Insira o RG do viajante: ");
    fgets(viagem->viajante.rg, 15, stdin);
    viagem->viajante.rg[strcspn(viagem->viajante.rg, "\n")] = 0;
    
    printf("Insira a data de nascimento do viajante (DD/MM/AAAA): ");
    fgets(viagem->viajante.data_nascimento, 11, stdin);
    viagem->viajante.data_nascimento[strcspn(viagem->viajante.data_nascimento, "\n")] = 0;
    
    printf("Insira o e-mail do viajante: ");
    fgets(viagem->viajante.email, MAX_EMAIL, stdin);
    viagem->viajante.email[strcspn(viagem->viajante.email, "\n")] = 0;
    
    printf("Insira o status da viagem: ");
    fgets(viagem->status, MAX_NAME, stdin);
    viagem->status[strcspn(viagem->status, "\n")] = 0;
    
    printf("\nDados da viagem iseridos com sucesso!\n");
}

    // Função para exibir os dados da viagem
    void exibir_viagem(const Viagem *viagem) {
        printf("\n=== Detalhes da Viagem ===\n");
        printf("ID: %d\n", viagem->id);
        printf("Destino: %s\n", viagem->destino.nome);
        printf("Endereço do Destino: %s\n", viagem->destino.endereco);
        printf("Atrativos: %s\n", viagem->atrativos);
        printf("Origem: %s\n", viagem->origem.nome);
        printf("Endereço da Origem: %s\n", viagem->origem.endereco);
        printf("Valor: R$ %.2f\n", viagem->valor);
        printf("Data da Viagem: %s\n", viagem->data);
        printf("Viajante: %s\n", viagem->viajante.nome);
        printf("RG: %s\n", viagem->viajante.rg);
        printf("Data de Nascimento: %s\n", viagem->viajante.data_nascimento);
        printf("Email: %s\n", viagem->viajante.email);
        printf("Status: %s\n", viagem->status);
    }
    
    int main() {
        Viagem viagem;
        
        inserir_viagem(&viagem);
        exibir_viagem(&viagem);
        
        return 0;
    
    }
