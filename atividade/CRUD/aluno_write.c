#include <stdio.h>
#include <string.h>
#include "aluno.h"

int salvar_aluno(const Aluno *aluno, const char *nomedoarquivo) {
    FILE *arquivo = fopen(nomedoarquivo, "ab");
    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }
    fwrite(aluno, sizeof(Aluno), 1, arquivo);
    fclose(arquivo);
    return 0;
}

int main() {
    Aluno a;

    printf("Digite o nome do aluno: ");
    fgets(a.nome, sizeof(a.nome), stdin);
    a.nome[strcspn(a.nome, "\n")] = 0;

    printf("Digite a matricula do aluno: ");
    scanf("%d", &a.matricula);

    printf("Digite a nota da Prova 1: ");
    scanf("%f", &a.prova1);

    printf("Digite a nota da Prova 2: ");
    scanf("%f", &a.prova2);

    printf("Digite a quantidade de faltas: ");
    scanf("%d", &a.faltas);

    a.media = (a.prova1 + a.prova2) / 2.0;

    if (a.media >= 6.0 && a.faltas <= 20) {
        strcpy(a.situacao, "Aprovado");
    } else {
        strcpy(a.situacao, "Reprovado");
    }

    printf("\nsalvando dados em %s\n", ARQUIVO);
    if (salvar_aluno(&a, ARQUIVO) == 0) {
        printf("salvo\n");
    }

    return 0;
}
