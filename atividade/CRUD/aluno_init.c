#include <stdio.h>
#include <string.h>
#include <time.h>
#include "aluno.h"

int gerar_id() {
    return (int)time(NULL);
}

void inicializa_arquivo() {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo != NULL) {
        fclose(arquivo);
        return;
    }

    printf("Criando arquivo de alunos...\n");
    arquivo = fopen(ARQUIVO, "wb");
    if (arquivo == NULL) {
        printf("erro ao criar o arquivo\n");
        return;
    }

    Aluno a1 = {gerar_id(), "Joao Silva", 101, 8.0, 7.0, 7.5, 5, "Aprovado"};
    Aluno a2 = {gerar_id() + 1, "Maria Souza", 102, 4.0, 5.0, 4.5, 25, "Reprovado"};

    fwrite(&a1, sizeof(Aluno), 1, arquivo);
    fwrite(&a2, sizeof(Aluno), 1, arquivo);

    fclose(arquivo);
    printf("arquivo criado com alunos de exemplo\n");
}

int main() {
    inicializa_arquivo();
    return 0;
}
