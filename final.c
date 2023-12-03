#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Veiculo {
    char proprietario[50];
    char combustivel[20];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[10];
    struct Veiculo *prox;
};

struct Veiculo *criarVeiculo() {
    struct Veiculo *novoVeiculo = (struct Veiculo *)malloc(sizeof(struct Veiculo));
    novoVeiculo->prox = NULL;
    return novoVeiculo;
}

void adicionarVeiculo(struct Veiculo **inicio, struct Veiculo *novoVeiculo) {
    if (*inicio == NULL) {
        *inicio = novoVeiculo;
    } else {
        struct Veiculo *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoVeiculo;
    }
}

void listarDiesel2010(struct Veiculo *inicio) {
    printf("\nProprietários de carros do ano 2010 ou posterior movidos a diesel:\n");
    while (inicio != NULL) {
        if (inicio->ano >= 2010 && strcmp(inicio->combustivel, "diesel") == 0) {
            printf("%s\n", inicio->proprietario);
        }
        inicio = inicio->prox;
    }
}

void listarPlacasJ(struct Veiculo *inicio) {
    printf("\nPlacas que começam com 'J' e terminam com 0, 2, 4 ou 7 e seus proprietários:\n");
    while (inicio != NULL) {
        if (inicio->placa[0] == 'J' && (inicio->placa[6] == '0' || inicio->placa[6] == '2' ||
                                        inicio->placa[6] == '4' || inicio->placa[6] == '7')) {
            printf("Placa: %s, Proprietário: %s\n", inicio->placa, inicio->proprietario);
        }
        inicio = inicio->prox;
    }
}

void listarModeloCor(struct Veiculo *inicio) {
    printf("\nModelo e cor dos veículos com placas que têm segunda letra vogal e soma numérica par:\n");
    while (inicio != NULL) {
        if ((inicio->placa[1] == 'A' || inicio->placa[1] == 'E' || inicio->placa[1] == 'I' ||
             inicio->placa[1] == 'O' || inicio->placa[1] == 'U') &&
            ((inicio->placa[2] - '0') + (inicio->placa[3] - '0') + (inicio->placa[4] - '0') +
             (inicio->placa[5] - '0') + (inicio->placa[6] - '0')) % 2 == 0) {
            printf("Modelo: %s, Cor: %s\n", inicio->modelo, inicio->cor);
        }
        inicio = inicio->prox;
    }
}

void trocarProprietario(struct Veiculo *inicio, const char *chassi, const char *novoProprietario) {
    while (inicio != NULL) {
        int possuiZero = 0;
        for (int i = 0; i < 7; i++) {
            if (inicio->placa[i] == '0') {
                possuiZero = 1;
                break;
            }
        }

        if (!possuiZero && strcmp(inicio->chassi, chassi) == 0) {
            strcpy(inicio->proprietario, novoProprietario);
            printf("Proprietário alterado com sucesso!\n");
            return;
        }

        inicio = inicio->prox;
    }

    printf("Veículo não encontrado ou a placa possui dígito zero.\n");
}

void mostrarChassiPlaca(struct Veiculo *inicio) {
    printf("\nChassi e Placa dos Veículos:\n");
    while (inicio != NULL) {
        printf("Chassi: %s, Placa: %s\n", inicio->chassi, inicio->placa);
        inicio = inicio->prox;
    }
}

void liberarLista(struct Veiculo *inicio) {
    while (inicio != NULL) {
        struct Veiculo *temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }
}

int main() {
    struct Veiculo *inicio = NULL;

    struct Veiculo *veiculo1 = criarVeiculo();
    strcpy(veiculo1->proprietario, "Jproprietario1");
    strcpy(veiculo1->combustivel, "diesel");
    strcpy(veiculo1->modelo, "Fusca");
    strcpy(veiculo1->cor, "Azul");
    strcpy(veiculo1->chassi, "ABC123");
    veiculo1->ano = 2012;
    strcpy(veiculo1->placa, "JAB0677");
    adicionarVeiculo(&inicio, veiculo1);

    struct Veiculo *veiculo2 = criarVeiculo();
    strcpy(veiculo2->proprietario, "proprietario2");
    strcpy(veiculo2->combustivel, "gasolina");
    strcpy(veiculo2->modelo, "Civic");
    strcpy(veiculo2->cor, "Prata");
    strcpy(veiculo2->chassi, "XYZ456");
    veiculo2->ano = 2015;
    strcpy(veiculo2->placa, "JOZ0347");
    adicionarVeiculo(&inicio, veiculo2);

    listarDiesel2010(inicio);
    listarPlacasJ(inicio);
    listarModeloCor(inicio);

    mostrarChassiPlaca(inicio); 

    char chassiTrocar[20];
    printf("\nInforme o chassi do veículo para trocar o proprietário: ");
    scanf("%s", chassiTrocar);

    char novoProprietario[50];
    printf("Informe o novo proprietário: ");
    scanf(" %[^\n]s", novoProprietario);

    trocarProprietario(inicio, chassiTrocar, novoProprietario);

    liberarLista(inicio);

    return 0;
}
