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
    Lista *cabecalho = (Lista *)malloc(sizeof(Lista));
    cabecalho->prox = NULL;
    return cabecalho;
}

void imprimir(Lista *lista)
{
    Lista *p = lista->prox;
    while (p != NULL)
    {
        printf("%d ", p->dado); // aqui mostramos a caixinha atual
        p = p->prox;            // e aqui vai pra proxima caixinha
    }
    printf("\n");
}

int contar(Lista *lista)
{
    int contador = 0;
    Lista *p = lista->prox;
    while (p != NULL)
    {
        contador++;
        p = p->prox; // proxima caixinha, se nao fica num loop infinito
    }
    return contador;
}

Lista *buscar(Lista *lista, int valorbuscado)
{
    Lista *p = lista->prox;
    while (p != NULL)
    {
        if (p->dado == valorbuscado)
            return p;

        p = p->prox;
    }
    printf("Lista nao encontrada\n");
    return NULL;
}

void inserir(Lista *lista, int valor)
{
    // cria uma caixinha na memoria e guarda o valor
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->dado = valor;

    Lista *ant = lista;
    Lista *atual = lista->prox;

    while (atual != NULL && atual->dado < valor)
    {
        ant = atual;         // ant vai parar ondeo atual ta  agora
        atual = atual->prox; // atual vai para proxima casa da frente
    }

    novo->prox = atual;
    ant->prox = novo;
}

void remover(Lista *lista, int valor)
{
    Lista *ant = lista;
    Lista *atual = lista->prox;

    while (atual != NULL && atual->dado != valor)
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        printf("valor %d nao encontrado\n", valor);
        return;
    }

    ant->prox = atual->prox; 
    free(atual);            
}

int main()
{
    Lista *minhaLista = criaLista();
    int opcao = 0;
    int valor = 0;

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
            printf("Digite o valor para inserir: ");
            scanf("%d", &valor);
            inserir(minhaLista, valor);
            break;
        case 2:
            printf("Digite o valor para remover: ");
            scanf("%d", &valor);
            remover(minhaLista, valor);
            break;
        case 3:
            printf("Digite o valor para buscar: ");
            scanf("%d", &valor);
            if (buscar(minhaLista, valor) != NULL)
            {
                printf("elemento %d encontrado na lista\n", valor);
            }
            break;
        case 4:
            printf("conteudo da lista: ");
            imprimir(minhaLista);
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
