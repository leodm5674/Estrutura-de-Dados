#ifndef ALUNO_H
#define ALUNO_H
#define ARQUIVO_ALUNOS "alunos.bin"
typedef struct {
	char nome[40];
	int matricula;
	float p1, p2, media;
	int faltas;
	char situacao[10];
} Aluno;
#endif
