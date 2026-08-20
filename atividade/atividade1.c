/*1. Implemente um programa para tratar e armazenar as notas dos alunos de uma turma de uma disciplina.

- A turma pode ter até 40 alunos.

- Para cada aluno, é preciso armazenar:

a) Nome (até 40 caracteres)

b) Matrícula (inteiro)

c) Notas:

- Prova 1 (real)

- Prova 2 (real)

- Média (real, calculada pelo programa)

d) Faltas (inteiro)

e) Situação (aprovado (se média >=6 e faltas <= 20) ou reprovado (se média < 6 ou faltas > 20))

O programa deve oferecer as seguintes opções ao usuário:

1. Inserir alunos. Função que lê os dados do aluno (nome, matrícula, notas e faltas), calcula a média e a situação, e mantém armazenados no vetor da turma.

2. Exibir alunos. Função que imprime na tela os dados de todos os alunos da turma.

3. Salvar dados. Função que grava em arquivo os dados dos alunos.

4. Carrega dados. Função que lê o arquivo de dados dos alunos e armazena em memória, na estrutura de alunos.

5. Sair do programa.


Postar arquivo com o código fonte em C.*/
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
			printf("\nNome: %s \n", turma[i].nome);
			printf("Matricula: %d\n", turma[i].matricula);
			printf("Nota 1: %.2f\n", turma[i].p1);
			printf("Nota 2: %.2f\n", turma[i].p2);
			printf("Falta: %d\n", turma[i].faltas);
			printf("Média %.2f \n",turma[i].media);
			
			}
		
		
		}

	int main(int argc, char **argv) {
		Aluno turma[40];
		int qtdalunos = 0;
		int numalunos = 0;
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
                scanf("%d", &);

                for (int i = 0; i < numalunos; i++) {
                    if (qtdalunos < 40) {
                        printf("Aluno %d\n", qtdalunos + 1);
                        Inseriraluno(turma, qtdalunos);
                        qtdalunos++;
                    } else {
                        printf("Turma cheia!\n");
                        break;
                    }
                }
                break;

            case 2:
				Exibiraluno(turma,qtdalunos);
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

