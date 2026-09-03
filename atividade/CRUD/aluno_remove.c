#include <stdio.h>
#include "aluno.h"

int remover_aluno(int matricula_alvo) {
    FILE *arquivo_original = fopen(ARQUIVO, "rb");
    if (arquivo_original == NULL) {
        return 1;
    }

    FILE *arquivo_temp = fopen("temp.bin", "wb");
    if (arquivo_temp == NULL) {
        fclose(arquivo_original);
        return 1;
    }

    Aluno a;
    int encontrou = 0;

    while (fread(&a, sizeof(Aluno), 1, arquivo_original) == 1) {
        if (a.matricula != matricula_alvo) {
            fwrite(&a, sizeof(Aluno), 1, arquivo_temp);
        } else {
            encontrou = 1;
        }
    }

    fclose(arquivo_original);
    fclose(arquivo_temp);

    if (encontrou) {
        remove(ARQUIVO);
        rename("temp.bin", ARQUIVO);
        return 0;
    } else {
        remove("temp.bin");
        return 2;
    }
}

int main() {
    int matricula;

    printf("Digite a matricula do aluno que deseja remover: ");
    scanf("%d", &matricula);

    int status = remover_aluno(matricula);

    if (status == 0) {
        printf("aluno removido\n");
    } else if (status == 2) {
        printf("aluno nao encontrado\n");
    } else {
        printf("erro ao remover\n");
    }

    return 0;
}
