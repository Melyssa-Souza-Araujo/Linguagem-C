#include <stdio.h>
#include <string.h>
//armazenar valores que NÃO podem ser mudados durante o programa
#define MAX_ALUNOS 50

int main() {
    char nomes[MAX_ALUNOS][50];
    float notas[MAX_ALUNOS], soma = 0, media;
    int num_alunos, i, abaixo_media = 0, acima_media = 0;

    printf("Digite o número de alunos (máximo 50): ");
    scanf("%d", &num_alunos);
    if (num_alunos <= 0 || num_alunos > MAX_ALUNOS) {
        printf("Número de alunos inválido.\n");
        return 1;
    }

    for (i = 0; i < num_alunos; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%s", nomes[i]);
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / num_alunos;

    printf("\nRelatório:\n");
    printf("Quantidade total de alunos: %d\n", num_alunos);
    printf("Nota média da classe: %.1f\n", media);

    printf("\nAlunos com nota abaixo da média:\n");
    for (i = 0; i < num_alunos; i++) {
        if (notas[i] < media) {
            printf("%s (%.1f)\n", nomes[i], notas[i]);
            abaixo_media++;
        }
    }
    printf("Quantidade de alunos com nota abaixo da média: %d\n", abaixo_media);

    printf("\nAlunos com nota maior ou igual à média:\n");
    for (i = 0; i < num_alunos; i++) {
        if (notas[i] >= media) {
            printf("%s (%.1f)\n", nomes[i], notas[i]);
            acima_media++;
        }
    }
    printf("Quantidade de alunos com nota maior ou igual à média: %d\n", acima_media);

    return 0;
}