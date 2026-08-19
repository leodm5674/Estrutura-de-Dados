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

	void Exibiraluno(Aluno turma[], int qtd){
		for(int i = 0; i < qtd; i++){
			printf("Nome: %s", turma[i].nome);
			
			}
		
		
		}

	int main(int argc, char **argv) {
		Aluno turma[40];
		int qtdalunos = 0;
		int novalote = 0;
		int opcao;

    do {
        printf("\n1-Inserir aluno\n");
        printf("2-Exibir aluno\n");
        printf("3-Salvar Dados\n");
        printf("4-Carrega dados\n");
        printf("5-Sair do Programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Quantos alunos deseja cadastrar? ");
                scanf("%d", &novalote);

                for (int i = 0; i < novalote; i++) {
                    if (qtdalunos < 40) {
                        printf("\n--- Aluno %d ---\n", qtdalunos + 1);
                        Inseriraluno(turma, qtdalunos);
                        qtdalunos++;
                    } else {
                        printf("Turma cheia!\n");
                        break;
                    }
                }
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}

