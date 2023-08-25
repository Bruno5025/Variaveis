#include <stdio.h>

//QUESTAO 8

int main(void)
{
    int salario, percentual;
    int calc;

    printf("Salario: ");
    scanf("%i", &salario);
    printf("Percentual de reajuste: %%");
    scanf("%i", &percentual);

    calc = ((salario / 100) * percentual) + salario;

    printf("Valor do novo salario: %i\n", calc);
}  //Bruno Ribeiro Garcia uc23200609