#include <stdio.h>
#include "aluno.h"

void salvar_turma(Aluno turma[], int qtd) {
	FILE *arquivo = fopen(ARQUIVO_ALUNOS, "wb"); // wb significa write binary
	if (arquivo == NULL) {
		printf("erro ao abrir o arquivo para salvar\n");//mensagem de verificacao
		return; // Se deu erro, cancela e sai da funçao imediatamente para não travar o programa
	}
	fwrite(turma, sizeof(Aluno), qtd, arquivo); // gravar dados
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

	if (qtdalunos >= 1) {
		salvar_turma(turma, qtdalunos);
	} else {
		printf("Nenhum aluno cadastrado\n");
	}

	return 0;
}