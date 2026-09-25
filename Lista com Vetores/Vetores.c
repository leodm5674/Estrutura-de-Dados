#include <stdio.h>
#include <string.h>

#define MaxItens 10
#define TamItem 20

typedef char tpLista[MaxItens][TamItem];

void criaLista(tpLista l)
{
    int i;
    for (i=0; i<MaxItens; i++)
        l[i][0] = '\0';
}

void imprimeLista(tpLista l)
{
    int i;
    printf("itens da lista \n");
    for(i=0; i<MaxItens && strlen(l[i])>0; i++)
        printf("\n %s", l[i]);
    
}

int contaLista(tpLista l)
{
    int i;
    for (i = 0; i<MaxItens && strlen(l[i])>0; i++);
    return(i);
}

void insereLista(tpLista l, char *item)
{
    int i;
    for(i=0; i<MaxItens && strlen(l[i])>0; i++);
    if (i<MaxItens)
    {
        strcpy(l[i], item);
        printf("\nitem (%s) inserido ", item);
    }
    else
        printf("\nlista cheia");
}

void retiraLista(tpLista l, char *item)
{
    int i;
    for(i=0; i<MaxItens && strlen(l[i])>0 && (strcmp(l[i],item) != 0); i++);
    if (i<MaxItens && (strcmp(l[i],item) == 0))
    {
        printf("\nItem (%s) encontrado, removendo", item);
        if (i < (MaxItens-1))
        {
            for (; i<(MaxItens-1) && strlen(l[i])>0; i++)
                strcpy(l[i], l[i+1]);
        }
        l[MaxItens-1][0] = '\0';
    }
    else
        printf("\nitem (%s) nao encontrado", item);
}

int main()
{
    tpLista listatopzera;
    int opcao;
    char item[TamItem];

    criaLista(listatopzera); // cria lista antes, pra ter uma tabela autoticamente

    do
    {
        printf("\n1 - Inserir\n");
        printf("2 - Retirar\n");
        printf("3 - Contar\n");
        printf("4 - Exibir\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("item: ");
                scanf("%s", item); 
                insereLista(listatopzera, item);
                break;
            case 2:
                printf("item: ");
                scanf("%s", item); 
                retiraLista(listatopzera, item);
                break;
            case 3:
                printf("\nttotal: %d", contaLista(listatopzera));
                break;
            case 4:
                imprimeLista(listatopzera);
                break;
            case 0:
                break;
            default:
                printf("\nopcao invalida");
                break;
        }
    } while(opcao != 0);

    return 0;
}
