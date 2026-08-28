#include <stdio.h>
#include <string.h>
#include "aluno.h"

void Inseriraluno(Aluno turma[], int i) {
	getchar();
	printf("Digite o nome do aluno: ");
	fgets(turma[i].nome, 40, stdin);
	turma[i].nome[strcspn(turma[i].nome, "\n")] = 0;
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

void salvar_turma(Aluno turma[], int qtd) {
	FILE *arquivo = fopen(ARQUIVO_ALUNOS, "wb");
	if (arquivo == NULL) {
		printf("erro ao abrir o arquivo para salvar\n");
		return;
	}
	fwrite(turma, sizeof(Aluno), qtd, arquivo);
	fclose(arquivo);
	printf("\ndados salvos\n");
}

int carregar_turma(Aluno turma[]) {
	int qtd = 0;
	FILE *arquivo = fopen(ARQUIVO_ALUNOS, "rb");
	if (arquivo != NULL) {
		qtd = fread(turma, sizeof(Aluno), 40, arquivo);
		fclose(arquivo);
	}
	return qtd;
}

int main() {
	Aluno turma[40];
	int qtdalunos = carregar_turma(turma);
	int numalunos = 0;

	printf("Quantos alunos deseja cadastrar? ");
	scanf("%d", &numalunos);

	for (int i = 0; i < numalunos; i++) {
		if (qtdalunos < 40) {
			printf("Aluno %d\n", qtdalunos + 1);
			Inseriraluno(turma, qtdalunos);
			qtdalunos++;
		} else {
			printf("turma cheia\n");
			break;
		}
	}

	salvar_turma(turma, qtdalunos);

	return 0;
}