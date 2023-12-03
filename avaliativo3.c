#include <stdio.h>
#include <stdlib.h>


struct Produto {
    int codigo;
    char descricao[50];
    int quantidade;
    float valor;
};

void inicializarEstoque(struct Produto **estoque, int *tamanho) {
    *estoque = NULL;
    *tamanho = 0;
}

void adicionarProduto(struct Produto **estoque, int *tamanho) {
    (*tamanho)++;
    *estoque = (struct Produto *)realloc(*estoque, (*tamanho) * sizeof(struct Produto));

    printf("Informe o código do produto: ");
    scanf("%d", &(*estoque)[*tamanho - 1].codigo);

    printf("Informe a descrição do produto: ");
    scanf(" %[^\n]s", (*estoque)[*tamanho - 1].descricao);

    printf("Informe a quantidade do produto: ");
    scanf("%d", &(*estoque)[*tamanho - 1].quantidade);

    printf("Informe o valor do produto: ");
    scanf("%f", &(*estoque)[*tamanho - 1].valor);

    printf("Produto cadastrado com sucesso!\n");
}

void gerarRelatorio(struct Produto *estoque, int tamanho) {
    printf("\nRelatório de Produtos:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Código: %d\n", estoque[i].codigo);
        printf("Descrição: %s\n", estoque[i].descricao);
        printf("Quantidade: %d\n", estoque[i].quantidade);
        printf("Valor: R$ %.2f\n\n", estoque[i].valor);
    }
}

void consultarProduto(struct Produto *estoque, int tamanho) {
    int codigo;
    printf("Informe o código do produto para consultar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < tamanho; i++) {
        if (estoque[i].codigo == codigo) {
            printf("\nProduto encontrado:\n");
            printf("Código: %d\n", estoque[i].codigo);
            printf("Descrição: %s\n", estoque[i].descricao);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Valor: R$ %.2f\n", estoque[i].valor);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

void removerProduto(struct Produto **estoque, int *tamanho) {
    int codigo;
    printf("Informe o código do produto a ser removido: ");
    scanf("%d", &codigo);

    int indice = -1;
    for (int i = 0; i < *tamanho; i++) {
        if ((*estoque)[i].codigo == codigo) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < *tamanho - 1; i++) {
            (*estoque)[i] = (*estoque)[i + 1];
        }

        (*tamanho)--;
        *estoque = (struct Produto *)realloc(*estoque, (*tamanho) * sizeof(struct Produto));

        printf("Produto removido com sucesso!\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

int main() {
    struct Produto *estoque = NULL;
    int tamanho = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Gerar Relatório\n");
        printf("3. Consultar Produto\n");
        printf("4. Remover Produto\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&estoque, &tamanho);
                break;
            case 2:
                gerarRelatorio(estoque, tamanho);
                break;
            case 3:
                consultarProduto(estoque, tamanho);
                break;
            case 4:
                removerProduto(&estoque, &tamanho);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    free(estoque); 
    return 0;
}
