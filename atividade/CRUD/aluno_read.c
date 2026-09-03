#include <stdio.h>
#include "aluno.h"

int ler_alunos(Aluno turma[], const char *nomedoarquivo) {
    FILE *arquivo = fopen(nomedoarquivo, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    int quantidade = 0;
    while (fread(&turma[quantidade], sizeof(Aluno), 1, arquivo) == 1) {
        quantidade++;
    }
    fclose(arquivo);
    return quantidade;
}

int main() {
    Aluno turma[40];
    int quantidade = ler_alunos(turma, ARQUIVO);

    if (quantidade == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return 0;
    }

    printf("Lista de alunos:\n\n");

    for (int i = 0; i < quantidade; i++) {
        printf("Id: %d\n", turma[i].id);
        printf("Matricula: %d\n", turma[i].matricula);
        printf("Nome: %s\n", turma[i].nome);
        printf("Prova 1: %.2f\n", turma[i].prova1);
        printf("Prova 2: %.2f\n", turma[i].prova2);
        printf("Media: %.2f\n", turma[i].media);
        printf("Faltas: %d\n", turma[i].faltas);
        printf("Situacao: %s\n\n", turma[i].situacao);
    }

    return 0;
}
