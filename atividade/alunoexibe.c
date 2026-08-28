#include <stdio.h>
#include "aluno.h"

void Exibiraluno(Aluno turma[], int qtd) {
	for(int i = 0; i < qtd; i++) {
		printf("\nNome: %s \n", turma[i].nome);
		printf("Matricula: %d\n", turma[i].matricula);
		printf("Nota 1: %.2f\n", turma[i].p1);
		printf("Nota 2: %.2f\n", turma[i].p2);
		printf("Média: %.2f \n", turma[i].media);
		printf("Falta: %d\n", turma[i].faltas);
		printf("Situacao: %s\n", turma[i].situacao);
	}
}

int carregar_turma(Aluno turma[]) {
	int qtd = 0;
	FILE *arquivo = fopen(ARQUIVO_ALUNOS, "rb");
	if (arquivo != NULL) { // testa se o arquivo existe
		qtd = fread(turma, sizeof(Aluno), 40, arquivo);
		fclose(arquivo);
	}
	return qtd;
}

int main() {
	Aluno turma[40];
	int qtdalunos = carregar_turma(turma);

	if (qtdalunos >= 1) {
		Exibiraluno(turma, qtdalunos);
	} else {
		printf("Nenhum aluno cadastrado\n");
	}

	return 0;
}