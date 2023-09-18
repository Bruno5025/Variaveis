#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]){
    if (argc != 2){
        printf("Modo de uso: ./switch (questao correspondente)\n");
        return 1;
    }

    if(strcmp(argv[1], "crescente") == 0){
         int numero;
        printf("Digite um número: ");
        scanf("%i", &numero);

        for(int i = 0; i <= numero ; i++){
            printf("%i ", i);
        }
        printf("\n");
    }
    if(strcmp(argv[1], "decrescente") == 0){
         int numero;
        printf("Digite um número: ");
        scanf("%i", &numero);

        for(int i = numero; i >= 0 ; i--){
            printf("%i ", i);
        }
        printf("\n");
    }
    if(strcmp(argv[1], "impares") == 0){
         int numero;
        printf("Digite um número: ");
        scanf("%i", &numero);

        for(int i = 1; i <= numero ; i++){
            printf("%i ", i);
            i = i + 1;
        }
        printf("\n");
    }
    if(strcmp(argv[1], "multiplos") == 0){
        int numero = 15;
        for(int i = 3; i <= numero; i++){
            printf("%i ", i);
            i = i + 2;
        }
        printf("\n");
    }
    if(strcmp(argv[1], "pares") == 0){
        int soma = 0;
        int contador;

        for(contador = 1 ; contador <= 100 ; contador++){
            if(contador % 2 == 0){
            soma += contador;
            }
        }
        printf("A soma dos primeiros 50 números pares é %i\n", soma);
    }
    if(strcmp(argv[1], "frutas") == 0){
        int quantidade,fruta,a;
        int valortotal = 0;
          do {
        printf("Frutas disponíveis:\n 1. Abacaxi - 5,00/unidade\n 2. Maçã - 1,00/unidade\n 3. Pêra - 4,00/unidade\n");
        scanf("%i", &fruta);

        printf("Quantidade desejada da fruta escolhida: \n");
        scanf("%i", &quantidade);

        switch (fruta) {
            case 1:
                valortotal += 5 * quantidade;
                break;
            case 2:
                valortotal += 1 * quantidade;
                break;
            case 3:
                valortotal += 4 * quantidade;
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

        printf("O valor total da compra é de R$%i\n", valortotal);
        printf("Gostaria de continuar comprando?\n 1. Sim\n 2. Não\n");
        scanf("%i", &a);

    } while (a == 1);

    printf("O valor final da compra é de R$%i\n", valortotal);

    }
    if(strcmp(argv[1], "populacao") == 0){

        int totalHabitantes = 0;
    int totalMulheresCastanhas = 0;

    while (true) {
        char sexo = get_char("Informe o sexo (m/f): ");

        if (sexo != 'm' && sexo != 'f') {
            printf("Sexo inválido. Informe novamente.\n");
            continue;
        }

        int idade = get_int("Informe a idade (-1 para encerrar): ");
        if (idade == -1) {
            break;
        }

        if (idade < 10 || idade > 100) {
            printf("Idade fora do intervalo válido. Informe novamente.\n");
            continue;
        }

        if (sexo == 'f' && idade >= 18 && idade <= 35) {
            char corOlhos = get_char("Informe a cor dos olhos (a/v/c/p): ");

            if (corOlhos == 'c') {
                char corCabelos = get_char("Informe a cor dos cabelos (l/c/p/r): ");

                if (corCabelos == 'c') {
                    float salario = get_float("Informe o salário: ");

                    if (salario < 0) {
                        printf("Salário inválido. Informe novamente.\n");
                        continue;
                    }

                    totalMulheresCastanhas++;
                }
            }
        }

        totalHabitantes++;
    }

    if (totalHabitantes > 0) {
        float percentagem = (float)totalMulheresCastanhas / totalHabitantes * 100;
        printf("A porcentagem de mulheres com idade entre 18 e 35 anos, olhos castanhos e cabelos castanhos é: %.2f%%\n", percentagem);
    } else {
        printf("Nenhum habitante válido foi registrado.\n");
    }
}
}