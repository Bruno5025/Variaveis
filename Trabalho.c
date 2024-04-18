#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_NOTAS 10

typedef struct {
    char nome[MAX_NOME];
    float notas[MAX_NOTAS];
    int num_notas;
    char curso[MAX_NOME];
} Aluno;

float calculo_media(Aluno *aluno) {
    float soma = 0;
    int i;
    for (i = 0; i < aluno->num_notas; i++) {
        soma += aluno->notas[i];
    }
    float media = soma / 2;
    if (media >= 7.0) {
        printf("%s, %.2f, APROVADO\n", aluno->nome, media);
    } else {
        printf("%s, %.2f, REPROVADO\n", aluno->nome, media);
    }
    return media;
}

int main() {
    FILE *entrada = fopen("DadosEntrada.csv", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    FILE *saida = fopen("SituacaoFinal.csv", "w");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(entrada);
        return 1;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        Aluno aluno;
        char *token = strtok(linha, ",");
        strcpy(aluno.nome, token);

        token = strtok(NULL, ",");
        strncpy(aluno.curso, token, sizeof(aluno.curso));
        aluno.curso[sizeof(aluno.curso) - 1] = '\0';

        aluno.num_notas = 0;
        while ((token = strtok(NULL, ",")) != NULL) {
            aluno.notas[aluno.num_notas++] = atof(token);
        }

        float media = calculo_media(&aluno);
        fprintf(saida, "%s, %.2f, %s\n", aluno.nome, media, media >= 7.0 ? "APROVADO" : "REPROVADO");
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}
