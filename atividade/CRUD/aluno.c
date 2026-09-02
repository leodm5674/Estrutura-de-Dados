#include <stdio.h>
#include <string.h>
#include "aluno.h"

int find_aluno(int matricula_alvo, Aluno *a) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    while (fread(a, sizeof(Aluno), 1, arquivo) == 1) {
        if (a->matricula == matricula_alvo) {
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0;
}

int salvar_aluno(const Aluno *aluno, const char *nomedoarquivo) {
    FILE *arquivo = fopen(nomedoarquivo, "ab");
    if (arquivo == NULL) {
        return 1;
    }
    fwrite(aluno, sizeof(Aluno), 1, arquivo);
    fclose(arquivo);
    return 0;
}

int ler_alunos(Aluno turma[]) {
    FILE *arquivo = fopen(ARQUIVO, "rb");
    if (arquivo == NULL) {
        return 0;
    }
    int quantidade = 0;
    while (fread(&turma[quantidade], sizeof(Aluno), 1, arquivo) == 1) {
        quantidade++;
    }
    fclose(arquivo);
    return quantidade;
}

int update_aluno(const Aluno *aluno_atualizado) {
    FILE *arquivo = fopen(ARQUIVO, "r+b");
    if (arquivo == NULL) {
        return 0;
    }
    Aluno temp;
    while (fread(&temp, sizeof(Aluno), 1, arquivo) == 1) {
        if (temp.matricula == aluno_atualizado->matricula) {
            fseek(arquivo, -sizeof(Aluno), SEEK_CUR);
            fwrite(aluno_atualizado, sizeof(Aluno), 1, arquivo);
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0;
}

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

void imprime_aluno(Aluno a) {
    printf("Matricula: %d\n", a.matricula);
    printf("Nome: %s\n", a.nome);
    printf("Prova 1: %.2f\n", a.prova1);
    printf("Prova 2: %.2f\n", a.prova2);
    printf("Media: %.2f\n", a.media);
    printf("Faltas: %d\n", a.faltas);
    printf("Situacao: %s\n", a.situacao);
}

int main() {
    int opcao;
    int matricula;
    Aluno a;
    Aluno turma[40];

    do {
        printf("\n1. Inserir aluno\n");
        printf("2. Listar alunos\n");
        printf("3. Buscar aluno\n");
        printf("4. Alterar aluno\n");
        printf("5. Remover aluno\n");
        printf("6. Alunos aprovados\n");
        printf("7. Alunos reprovados\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Nome: ");
                getchar();
                fgets(a.nome, sizeof(a.nome), stdin);
                a.nome[strcspn(a.nome, "\n")] = 0;

                printf("Matricula: ");
                scanf("%d", &a.matricula);

                printf("Prova 1: ");
                scanf("%f", &a.prova1);

                printf("Prova 2: ");
                scanf("%f", &a.prova2);

                printf("Faltas: ");
                scanf("%d", &a.faltas);

                a.media = (a.prova1 + a.prova2) / 2.0;
                if (a.media >= 6.0 && a.faltas <= 20) {
                    strcpy(a.situacao, "Aprovado");
                } else {
                    strcpy(a.situacao, "Reprovado");
                }

                salvar_aluno(&a, ARQUIVO);
                printf("aluno cadastrado\n");
                break;

            case 2: {
                int quantidade = ler_alunos(turma);
                if (quantidade == 0) {
                    printf("nenhum aluno cadastrado\n");
                } else {
                    for (int i = 0; i < quantidade; i++) {
                        imprime_aluno(turma[i]);
                        printf("\n");
                    }
                }
                break;
            }

            case 3:
                printf("Matricula: ");
                scanf("%d", &matricula);
                if (find_aluno(matricula, &a)) {
                    imprime_aluno(a);
                } else {
                    printf("aluno nao encontrado\n");
                }
                break;

            case 4:
                printf("Matricula: ");
                scanf("%d", &matricula);
                if (find_aluno(matricula, &a)) {
                    printf("Nome: %s\n", a.nome);
                    printf("Prova 1: %.2f\n", a.prova1);
                    printf("Prova 2: %.2f\n", a.prova2);
                    printf("Faltas: %d\n", a.faltas);

                    printf("Nova prova 1: ");
                    scanf("%f", &a.prova1);
                    printf("Nova prova 2: ");
                    scanf("%f", &a.prova2);
                    printf("Novas faltas: ");
                    scanf("%d", &a.faltas);

                    a.media = (a.prova1 + a.prova2) / 2.0;
                    if (a.media >= 6.0 && a.faltas <= 20) {
                        strcpy(a.situacao, "Aprovado");
                    } else {
                        strcpy(a.situacao, "Reprovado");
                    }

                    update_aluno(&a);
                    printf("aluno atualizado\n");
                } else {
                    printf("aluno nao encontrado\n");
                }
                break;

            case 5:
                printf("Matricula: ");
                scanf("%d", &matricula);
                if (remover_aluno(matricula) == 0) {
                    printf("aluno removido\n");
                } else {
                    printf("aluno nao encontrado\n");
                }
                break;

            case 6: {
                int quantidade = ler_alunos(turma);
                for (int i = 0; i < quantidade; i++) {
                    if (strcmp(turma[i].situacao, "Aprovado") == 0) {
                        imprime_aluno(turma[i]);
                        printf("\n");
                    }
                }
                break;
            }

            case 7: {
                int quantidade = ler_alunos(turma);
                for (int i = 0; i < quantidade; i++) {
                    if (strcmp(turma[i].situacao, "Reprovado") == 0) {
                        imprime_aluno(turma[i]);
                        printf("\n");
                    }
                }
                break;
            }

            case 0:
                printf("saindo\n");
                break;

            default:
                printf("opcao invalida\n");
        }

    } while (opcao != 0);

    return 0;
}
