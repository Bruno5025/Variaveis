#include <stdio.h>
#include <string.h>
#include <math.h>

int validaQuantidade(int quantidade);
float calculaSalario(int quantidade);
void processaAssalariado();

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

        printf("Salário: R$ %.2f\n", salario);

        if (salario > salarioMinimo) {
            printf("Classificação: Acima do salário mínimo\n");
        } else if (salario == salarioMinimo) {
            printf("Classificação: Igual ao salário mínimo\n");
        } else {
            printf("Classificação: Abaixo do salário mínimo\n");
        }

        printf("Sexo: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
    }
}
