		/*Exercícios de Registros e Manipulação de Arquivos.

1. Implemente um programa para tratar e armazenar as notas dos alunos de uma turma de uma disciplina.

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

5. Sair do programa.*/
#include <stdio.h>
#include <string.h>
    typedef struct {
		char nome[40];
		int matricula;
		float p1, p2, media;
		int faltas;
		char situacao[10];
    	}Aluno;
    	
    	
	void Inseriraluno(Aluno turma[], int *qtd ){
	    if(*qtd < 40){
	    getchar();
		printf("Digite o nome do aluno");
		fgets(turma[*qtd].nome, 40, stdin);
		printf("Digite a matricula do aluno");
		scanf("%d",&turma[*qtd].matricula);
		
		printf("Digite a nota da Prova 1: ");
        scanf("%f", &turma[*qtd].p1);

        printf("Digite a nota da Prova 2: ");
        scanf("%f", &turma[*qtd].p2);

        printf("Digite a quantidade de faltas: ");
        scanf("%d", &turma[*qtd].faltas);
        
        turma[*qtd].media = (turma[*qtd].p1 + turma[*qtd].p2) / 2;        
        if(turma[*qtd].media >= 6.0 && turma[*qtd].faltas <= 20){
            strcpy(turma[*qtd].situacao, "Aprovado");            
        }else{
            strcpy(turma[*qtd].situacao, "Reprovado");
        }
        
        
        (*qtd)++;
		}else{
		    printf("Turma cheia");
		    
		}




int main(int argc, char **argv)
{	
	Aluno turma[40];
	int qtdalunos = 0;
	int opcao;
		do{
			printf("Escolha uma opção");
			scanf("%d",&opcao);
			printf("1-Inserir aluno");
			printf("2-Exibir aluno");
			printf("3-Salvar Dados");
			printf("4-Carrega dados");
			printf("5-Sair do Programa");
			switch(opcao){
				
				
				case 1:
				Inseriraluno(turma, &qtdalunos);
                break;
                case 2:
				
                break;
				
				
				
				
				
				}			
			}
		
	return 0;
}
