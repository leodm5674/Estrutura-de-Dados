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
    printf("\nItens da lista\n");
    for(i=0; i<MaxItens && strlen(l[i])>0; i++)
        printf("\n%s", l[i]);
    printf("\n");
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
        printf("\nItem (%s) inserido ", item);
    }
    else
        printf("\nLista cheia");
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
        printf("\nItem (%s) nao encontrado", item);
}

int main()
{
    tpLista l1;
    int opcao;
    char item[TamItem];

    criaLista(l1);

    do
    {
        printf("\n1. Inserir\n");
        printf("2. Retirar\n");
        printf("3. Contar\n");
        printf("4. Exibir\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                printf("Item: ");
                scanf("%s", item); 
                insereLista(l1, item);
                break;
            case 2:
                printf("Item: ");
                scanf("%s", item); 
                retiraLista(l1, item);
                break;
            case 3:
                printf("\nTotal: %d", contaLista(l1));
                break;
            case 4:
                imprimeLista(l1);
                break;
            case 0:
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    } while(opcao != 0);

    return 0;
}
