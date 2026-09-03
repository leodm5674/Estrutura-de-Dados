#ifndef ALUNO_H
#define ALUNO_H

#define ARQUIVO "alunos.bin"

typedef struct {
    int id;
    char nome[41];
    int matricula;
    float prova1;
    float prova2;
    float media;
    int faltas;
    char situacao[10]; 
} Aluno;

#endif
