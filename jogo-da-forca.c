#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TENTATIVAS 10

int main() {
    char palavras[][20] = {
        "nostalgia", 
        "labirinto", 
        "luminescente", 
        "efemero", 
        "ebulicao", 
        "onomatopeia",
        "eufemismo",
        "animal",
        "boca",
        "cabide",
        "trompete",
        "tartaruga",
        "vermelho",
        "cadeira",
        "caminho",
        "relutancia",
        "continente",
        "aprofundar",
        "rivalidade",
        "bagunceiro",
        "orientacao",
        "estrategia",
        "adrenalina",
        "sobrenome",
        "prolongar",
        "purificar", 
        "corrosivo", 
        "furadeira", 
        "romantico", 
        "desligar", 
        "amaciar",
        "nuclear",
        "ausente",
        "queixar",
        "existo",
        "ordens",
        "status",
        "sushi",
        "anual",
        "culpa",
        "desinstalar",
        "manipulador",
        "falecimento",
        "catolicismo",
        "patrimonial",
        "antissocial",
        "esconderijo",
        "desvantagem",
        "inutilmente",
        "basicamente",
        "brutalmente",
        "domesticavel",
        "imortalidade",
        "extravagante",
        "neuromuscular",
        "otorrinolaringologia",
        "superdotado",
        "desproporcionalmente",
        "desclassificacao",
        "milagrosamente",
        "individualismo",
        "misericordioso",
        "acidentalmente",
        "reinauguracao",
        "anteriormente",
        "azul",
        "marrom",
        "verde",
        "roxo",
        "amarelo",
        "cachorro",
        "gato",
        "tigre",
        "leao",
        "zebra"
    };
    int num_palavras = sizeof(palavras) / sizeof(palavras[0]);
    char palavra_secreta[20];
    char chute;
    int acertou = 0;
    int erros = 0;

    // Semente para números aleatórios
    srand(time(NULL));

    // Escolhe uma palavra aleatória
    int indice_palavra = rand() % num_palavras;
    strcpy(palavra_secreta, palavras[indice_palavra]);

    // Inicializa o vetor de chutes com traços
    char chutes[20];
    for (int i = 0; palavra_secreta[i] != '\0'; i++) {
        chutes[i] = '_';
    }

    // Loop do jogo
    while (erros < MAX_TENTATIVAS && acertou < strlen(palavra_secreta)) {
        printf("Palavra: ");
        for (int i = 0; palavra_secreta[i] != '\0'; i++) {
            printf("%c ", chutes[i]);
        }
        printf("\n");

        printf("Digite uma letra: ");
        scanf(" %c", &chute);

        int achou = 0;
        for (int i = 0; palavra_secreta[i] != '\0'; i++) {
            if (palavra_secreta[i] == chute) {
                chutes[i] = chute;
                achou = 1;
                acertou++;
            }
        }

        if (!achou) {
            erros++;
            printf("Errou!\n");
        }
    }

    if (acertou == strlen(palavra_secreta)) {
        printf("Parabéns, você venceu!\nA palavra era: %s\n", palavra_secreta);
    } else {
        printf("Você perdeu! A palavra era: %s\n", palavra_secreta);
    }

    return 0;
}
