/*Faça um programa que implemente uma fila com alocação dinâmica, para armazenar números inteiros.

O usuário deve poder incluir quantos elementos desejar na fila.

As opções permitidas para o usuário são:

1 - Inserir um elemento no final da fila

2 - Retirar um elemento do início da fila

3 - Imprimir o conteúdo da fila.

Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.*/

#include <stddef.h>
#include <stdio.h>

struct elemento{
	int dado;
	struct elemento *prox;
	};

typedef struct elemento *ap;

typedef struct
{
	ap ini;
	ap fim;
	
	}Fila;



Fila criaFila(){
	Fila f;
	f.ini = NULL;
	f.fim = NULL;
	return (f);
	
	
	}

Fila InserirFila(){
	
	
	}

Fila RetirarDFila(){
	
	
	}
	
Fila ImprimirFila(){
	
	
	
	}






int main(int argc, char **argv)
{
	Fila f2;
	
	
	
	
	
	
	
	
	return 0;
}

