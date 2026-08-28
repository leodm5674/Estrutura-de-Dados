#include <stdio.h>
#include "aluno.h"

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

	printf("%d aluno(s) carregado(s)\n", qtdalunos);

	return 0;
}