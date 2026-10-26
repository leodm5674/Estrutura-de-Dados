#include <stdio.h>
#include <stdlib.h>

struct Elemento {
    int numero;
    struct Elemento *proximo; 
};

typedef struct Elemento *PonteiroElemento;

typedef struct {
    PonteiroElemento inicio;
    PonteiroElemento fim;
} EstruturaFila;

EstruturaFila criar_fila_vazia() {
    EstruturaFila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    return fila; 
}

EstruturaFila inserir_na_fila(EstruturaFila fila, int valor) {
    PonteiroElemento novo_bloco = (PonteiroElemento)malloc(sizeof(struct Elemento));
    
    if (novo_bloco == NULL) {
        return fila;
    }

    novo_bloco->numero = valor;
    novo_bloco->proximo = NULL;

    if (fila.inicio == NULL) {
        fila.inicio = novo_bloco;
        fila.fim = novo_bloco;
    } else {
        fila.fim->proximo = novo_bloco;
        fila.fim = novo_bloco;
    }
    return fila;
}

int remover_da_fila(EstruturaFila *fila) {
    if (fila->inicio == NULL) {
        printf("afila esta vazia\n");
        return -1;
    }

    PonteiroElemento bloco_removido = fila->inicio;
    int valor_salvo = bloco_removido->numero;

    fila->inicio = fila->inicio->proximo;
    free(bloco_removido);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return valor_salvo;
}

void imprimir_fila(EstruturaFila fila) {
    PonteiroElemento atual = fila.inicio;
    
    printf("elementos da fila: ");
    while (atual != NULL) {
        printf("%d - ", atual->numero);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    EstruturaFila minha_fila = criar_fila_vazia();
    int item, opcao;
    
    do {
        printf("\n1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d", &item);
                minha_fila = inserir_na_fila(minha_fila, item);
                break;
                
            case 2:
                if (minha_fila.inicio != NULL) {
                    item = remover_da_fila(&minha_fila);
                    printf("valor removido: %d\n", item);
                } else {
                    printf("a fila esta vazia\n");
                }
                break;
                
            case 3:
                if (minha_fila.inicio != NULL) {
                    imprimir_fila(minha_fila);
                } else {
                    printf("a fila esta vazia\n");
                }
                break;
                
            case 4:
                printf("\nsaindo\n");
                break;
                
            default:
                printf("opcao invalida\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
