#include <stdio.h>

int main(void)
{
    int idade;
    float salario, altura, peso;

    printf("Quantos anos tem?: ");
    scanf("%i", &idade);
    printf("Qual sua altura em metros?: ");
    scanf("%f", &altura);
    printf("Qual o seu salario?: ");
    scanf("%f", &salario);
    printf("Qual o seu peso?: ");
    scanf("%f", &peso);

    if(idade >= 18)
        printf("Voce tem %i anos\n", idade);
    else
        printf("Voce é menor de idade\n");

    if(altura >= 1.8)
        printf("Voce tem %.2f de altura\n", altura);
    else
        printf("Voce tem menos de 1.8m de altura\n");
    if(salario >= 1300)
        printf("Seu salario é de %.2f reais\n", salario);
    else
        printf("Seu salario é menor que o salário minimo\n");
    if(peso <= 60)
        printf("Voce pesa %.2f quilos\n", peso);
    else
        printf("Voce pesa mais que 60 quilos\n");

}