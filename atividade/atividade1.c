#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[40];
    int matricula;
    float p1, p2, media;
    int faltas;
    char situacao[10];
} Aluno;

void Inseriraluno(Aluno turma[], int i) {
    getchar();
    printf("Digite o nome do aluno: ");
    fgets(turma[i].nome, 40, stdin);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &turma[i].matricula);

    printf("Digite a nota da Prova 1: ");
    scanf("%f", &turma[i].p1);

    printf("Digite a nota da Prova 2: ");
    scanf("%f", &turma[i].p2);

    printf("Digite a quantidade de faltas: ");
    scanf("%d", &turma[i].faltas);

    turma[i].media = (turma[i].p1 + turma[i].p2) / 2.0;

    if (turma[i].media >= 6.0 && turma[i].faltas <= 20) {
        strcpy(turma[i].situacao, "Aprovado");
    } else {
        strcpy(turma[i].situacao, "Reprovado");
    }
}

int main(int argc, char **argv) {
    Aluno turma[40];
    int qtdalunos;

    printf("Quantos alunos deseja cadastrar (max 40)? ");
    scanf("%d", &qtdalunos);

    for (int i = 0; i < qtdalunos; i++) {
        printf("\n--- Cadastrando Aluno %d ---\n", i + 1);
        Inseriraluno(turma, i);
    }

    return 0;
}
