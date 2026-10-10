/*Faça um programa que implemente uma pilha com alocação dinâmica, para armazenar números inteiros.

O usuário deve poder incluir quantos elementos desejar na pilha.

As opções permitidas para o usuário são:

1 - Empilhar um elemento (inserir na pilha)

2 - Desempilhar um elemento (retirar o elemento do topo da pilha)

3 - Imprimir o conteúdo da pilha.

Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

	typedef struct elemento {
		
		int dado;
		struct elemento *prox;
		} *Pilha;
	
	Pilha criaPilha(){
		return NULL;
		}
	
	int pilhaVazia(Pilha p)
	{
		if (p == NULL)
		return (TRUE);
		else
		return (FALSE);
}
	
	Pilha empilhaPilha(Pilha p, int valor){
		Pilha novo;
		
		novo = malloc(sizeof(struct elemento));
		novo -> dado = valor;
		novo -> prox = p;
		return (novo);
		
		
		
		}

	
	void imprimePilha(Pilha p){
		Pilha ap;
		
		printf("Itens da Pilha \n");
		ap = p;
		while(ap != NULL){
			
			printf("%d \n", ap->dado);
			ap = ap->prox;
		
		
		}
	}
	
	Pilha desempilha (Pilha p, int *valor){
		
		Pilha ap;
		
		if(!pilhaVazia(p))
		{
			*valor = p -> dado;
			
			ap = p;
			
			p = p->prox;
			
			free(ap);
			printf("Desimpilhado com sucesso");
			}
		else
		{
			*valor = -1;
			printf("Pilha esta vazia\n");
			}
		return (p);
		
		
		
		}
	
	
	
	

int main()
{	
	Pilha p;
	p = criaPilha();
	
	
	
    int opcao = 0;
	int valor = 0;
    while (opcao != 4)
    {
        printf("\n1 - Empilhar elemento\n");
        printf("2 - Desimpilhar Elemento\n");
        printf("3 - Imprimri Elemento\n");
        printf("4 - Sair");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        printf("Digite o valor a ser empilhado\n");
        scanf("%d", &valor);
        
        p = empilhaPilha(p, valor);
            break;
        case 2:
        p = desempilha(p,&valor);
            break;
        case 3:
             imprimePilha(p);
            break;
		case 4: 
			printf("Saiu do Programa\n");
			break;
        }
    }
    return 0;
}
