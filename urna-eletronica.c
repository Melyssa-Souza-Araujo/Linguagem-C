#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEITORES 100
#define MAX_CANDIDATOS 10
#define MAX_SECOES 5
#define BIO_SIZE 5

typedef struct {
    int id;
    int biometria[BIO_SIZE];
    int votou;
} Eleitor;

typedef struct {
    int id;
    char nome[50];
    int votos;
} Candidato;

typedef struct {
    int id;
    Eleitor eleitores[MAX_ELEITORES];
    int totalEleitores;
} Secao;

Secao secoes[MAX_SECOES];
Candidato candidatos[MAX_CANDIDATOS];
int totalCandidatos = 0;

// Declarações das funções
int selecionarSecao();
void cadastrarEleitor();
void cadastrarCandidato();
void votar();
void apurarVotos();

int selecionarSecao() {
    int secaoId;
    do {
        printf("Digite o número da seção (1 a %d): ", MAX_SECOES);
        scanf("%d", &secaoId);
        if (secaoId < 1 || secaoId > MAX_SECOES) {
            printf("Seção inválida. Tente novamente.\n");
        }
    } while (secaoId < 1 || secaoId > MAX_SECOES);
    return secaoId - 1;
}

void cadastrarEleitor() {
    int secaoIndex = selecionarSecao();
    Secao *secao = &secoes[secaoIndex];
    Eleitor e;
    e.id = secao->totalEleitores + 1;
    printf("Digite as 5 coordenadas biométricas para o eleitor %d: ", e.id);
    for (int i = 0; i < BIO_SIZE; i++) {
        scanf("%d", &e.biometria[i]);
    }
    e.votou = 0;
    secao->eleitores[secao->totalEleitores++] = e;
}

void cadastrarCandidato() {
    if (totalCandidatos >= MAX_CANDIDATOS) {
        printf("Número máximo de candidatos atingido.\n");
        return;
    }

    Candidato c;
    c.id = totalCandidatos + 1;
    printf("Digite o nome do candidato %d: ", c.id);
    scanf("%s", c.nome);
    c.votos = 0;
    candidatos[totalCandidatos++] = c;
}

void votar() {
    int secaoIndex = selecionarSecao();
    Secao *secao = &secoes[secaoIndex];
    int biometria[BIO_SIZE];
    printf("Digite suas 5 coordenadas biométricas: ");
    for (int i = 0; i < BIO_SIZE; i++) {
        scanf("%d", &biometria[i]);
    }
    int eleitorIndex = -1;
    for (int i = 0; i < secao->totalEleitores; i++) {
        int igual = 1;
        for (int j = 0; j < BIO_SIZE; j++) {
            if (secao->eleitores[i].biometria[j] != biometria[j]) {
                igual = 0;
                break;
            }
        }
        if (igual) {
            eleitorIndex = i;
            break;
        }
    }

    if (eleitorIndex == -1 || secao->eleitores[eleitorIndex].votou) {
        printf("Eleitor não encontrado ou já votou.\n");
        return;
    }

    printf("Escolha um candidato:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        printf("%d - %s\n", candidatos[i].id, candidatos[i].nome);
    }
    printf("Digite 0 para voto em branco ou -1 para voto nulo.\n");

    int voto;
    scanf("%d", &voto);
    if (voto == 0) {
        printf("Voto em branco.\n");
    } else if (voto == -1) {
        printf("Voto anulado.\n");
    } else if (voto > 0 && voto <= totalCandidatos) {
        candidatos[voto - 1].votos++;
        printf("Voto computado para %s.\n", candidatos[voto - 1].nome);
    } else {
        printf("Candidato inválido.\n");
        return;
    }
    secao->eleitores[eleitorIndex].votou = 1;
}

void apurarVotos() {
    printf("Resultados:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        printf("%s: %d votos\n", candidatos[i].nome, candidatos[i].votos);
    }
}

int main() {
    int opcao;
    do {
        printf("\n1. Cadastrar Eleitor\n2. Cadastrar Candidato\n3. Votar\n4. Apurar Votos\n5. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarEleitor();
                break;
            case 2:
                cadastrarCandidato();
                break;
            case 3:
                votar();
                break;
            case 4:
                apurarVotos();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}
