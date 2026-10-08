#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Lista;
struct elemento
{
    int dado;
    struct elemento *prox;
};

Lista *criaLista()
{
    return NULL;
}

void imprimir(Lista *lista)
{
    while (lista != NULL)
    {
        printf("%d ", lista->dado); //aqui mostramos a caixinha atual
        lista = lista->prox;           // e aqui vai pra proxima caixinha
    }
}

int contar(Lista *lista){
    int contador = 0;
    while(lista != NULL){
        contador++;
        lista = lista->prox; // proxima caixinha, se nao fica num loop infinito
    }
    return contador;

}

Lista* buscar(Lista *lista, int valorbuscado){
    while (lista != NULL){
        if(lista->dado == valorbuscado)
            return lista;

        lista = lista->prox;
    } 
        printf("Lista nao encontrada");
        return 0;

}

void inserir(Lista *lista, int valor){





}




int main()
{
    Lista *minhaLista = criaLista();
    int opcao = 0;
    while (opcao != 5)
    {
        printf("\n1 - Inserir Elemento\n");
        printf("2 - Retirar Elemento\n");
        printf("3 - Buscar Elemento\n");
        printf("4 - Imprimir o Conteudo da Lista\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            printf("Saiu do programa\n");
            break;
        default:
            printf("Opcao Invalida\n");
            break;
        }
    }
    return 0;
}
