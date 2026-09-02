#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include "aluno_find.c"

int update_aluno(const Aluno *aluno_atualizado) {
    FILE *arquivo = fopen(ARQUIVO, "r+b");
    if (arquivo == NULL) {
        return 0;
    }

    Aluno temp;

    while (fread(&temp, sizeof(Aluno), 1, arquivo) == 1) {
        if (temp.matricula == aluno_atualizado->matricula) {
            fseek(arquivo, -sizeof(Aluno), SEEK_CUR);
            fwrite(aluno_atualizado, sizeof(Aluno), 1, arquivo);
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

int main() {
    int matricula;
    Aluno aluno;

    printf("Digite a matricula do aluno que deseja alterar: ");
    scanf("%d", &matricula);

    if (find_aluno(matricula, &aluno)) {
        printf("Nome: %s\n", aluno.nome);
        printf("Prova 1: %.2f\n", aluno.prova1);
        printf("Prova 2: %.2f\n", aluno.prova2);
        printf("Faltas: %d\n", aluno.faltas);

        printf("\nNova nota da prova 1: ");
        scanf("%f", &aluno.prova1);

        printf("Nova nota da prova 2: ");
        scanf("%f", &aluno.prova2);

        printf("Nova quantidade de faltas: ");
        scanf("%d", &aluno.faltas);

        aluno.media = (aluno.prova1 + aluno.prova2) / 2.0;

        if (aluno.media >= 6.0 && aluno.faltas <= 20) {
            strcpy(aluno.situacao, "Aprovado");
        } else {
            strcpy(aluno.situacao, "Reprovado");
        }

        update_aluno(&aluno);
        printf("\naluno atualizado\n");

    } else {
        printf("aluno nao encontrado\n");
    }

    return 0;
}
