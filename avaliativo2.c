#include <stdio.h>
#include <string.h>
#include <math.h>

int validaQuantidade(int quantidade);
float calculaSalario(int quantidade);
void processaAssalariado();
void classificaSalario(float salario, float salarioMinimo, int *abaixo, int *acima);
void mostraClassifica(int abaixo, int acima);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Modo de uso: ./avaliativo (questao correspondente)\n");
        return 1;
    }

    if (strcmp(argv[1], "questaoum") == 0) {
        int quantidade;
        while (1) {
            printf("Digite a quantidade de peças fabricadas pelo funcionário (ou -1 para sair): ");
            if (scanf("%d", &quantidade) != 1) {
                printf("Entrada inválida. Tente novamente.\n");
                while (getchar() != '\n');
                continue;
            }

            if (quantidade == -1) {
                break;
            }

            if (validaQuantidade(quantidade)) {
                printf("Salário do funcionário: R$ %.2f\n", calculaSalario(quantidade));
            } else {
                printf("Quantidade inválida. Tente novamente.\n");
            }
        }
    }

    if (strcmp(argv[1], "questaodois") == 0) {
        processaAssalariado();
    }

    return 0;
}

int validaQuantidade(int quantidade) {
    return quantidade >= 0;
}

float calculaSalario(int quantidade) {
    const float salarioBase = 600.0;
    const float adicional1 = 0.50;
    const float adicional2 = 0.75;
    const int limite1 = 50;
    const int limite2 = 80;

    float salarioTotal = salarioBase;

    if (quantidade > limite1) {
        salarioTotal += (limite1 * adicional1) + fmin((quantidade - limite1), (limite2 - limite1)) * adicional1 + fmax((quantidade - limite2), 0) * adicional2;
    }

    return salarioTotal;
}

void processaAssalariado() {
    const float salarioMinimo = 1400.0;
    char entrada[10];
    char sexo;
    float salario;
    int abaixoSalario = 0, acimaSalario = 0;

    while (1) {
        printf("Digite o sexo do assalariado (M/F) (ou -1 para sair): ");
        scanf("%s", entrada);

        if (strcmp(entrada, "-1") == 0) {
            break;
        }

        if (strlen(entrada) == 1 && (entrada[0] == 'M' || entrada[0] == 'm' || entrada[0] == 'F' || entrada[0] == 'f')) {
            sexo = entrada[0];
        } else {
            printf("Escolha de sexo inválida. Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Digite o salário do assalariado: ");

        if (scanf("%f", &salario) != 1 || salario <= 1.0) {
            printf("Salário inválido. Tente novamente.\n");

            while (getchar() != '\n');

            continue;
        }

        classificaSalario(salario, salarioMinimo, &abaixoSalario, &acimaSalario);

        printf("Salário: R$ %.2f\n", salario);
        printf("Classificação: ");
        mostraClassifica(abaixoSalario, acimaSalario);
        printf("Sexo: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
    }

    mostraClassifica(abaixoSalario, acimaSalario);
}

void classificaSalario(float salario, float salarioMinimo, int *abaixo, int *acima) {
    if (salario > salarioMinimo) {
        (*acima)++;
    } else {
        (*abaixo)++;
    }
}

void mostraClassifica(int abaixo, int acima) {
    printf("Quantidade de assalariados abaixo do salário mínimo: %d\n", abaixo);
    printf("Quantidade de assalariados acima do salário mínimo: %d\n", acima);
}

