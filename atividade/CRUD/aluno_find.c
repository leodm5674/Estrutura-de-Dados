#include <stdio.h>
#include <string.h>
#include "aluno.h"

// procura o aluno pela matricula no arquivo
// se achar, preenche o ponteiro "a" com os dados e retorna 1
// se nao achar, retorna 0
int find_aluno(int matricula_alvo, Aluno *a) {

    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return 0;
    }

    while (fread(a, sizeof(Aluno), 1, arquivo) == 1) {
        if (a->matricula == matricula_alvo) {
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);
    return 0;
}

int main() {
    int matricula_busca;
    Aluno aluno;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &matricula_busca);

    if (find_aluno(matricula_busca, &aluno)) {
        printf("\nAluno encontrado!\n");
        printf("Id: %d\n", aluno.id);
        printf("Matricula: %d\n", aluno.matricula);
        printf("Nome: %s\n", aluno.nome);
        printf("Prova 1: %.2f\n", aluno.prova1);
        printf("Prova 2: %.2f\n", aluno.prova2);
        printf("Media: %.2f\n", aluno.media);
        printf("Faltas: %d\n", aluno.faltas);
        printf("Situacao: %s\n", aluno.situacao);
    } else {
        printf("\nAluno com matricula %d nao encontrado.\n", matricula_busca);
    }
    return 0;
}
