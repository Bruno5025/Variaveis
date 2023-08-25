#include <stdio.h>

//QUESTAO 10

int main(void)
{
    int salariofixo, comissao, carrosvendidos, valortotal, final;

    printf("Salario fixo: ");
    scanf("%i", &salariofixo);
    printf("Quantos carros foram vendidos pelo funcionario?: ");
    scanf("%i", &carrosvendidos);
    printf("Valor da comissao por carro vendido: ");
    scanf("%i", &comissao);
    printf("Valor total de suas vendas: ");
    scanf("%i", &valortotal);

    final = salariofixo + (carrosvendidos * comissao) + ((valortotal / 100) * 5);

    printf("Salario final: %i\n", final);
}  //Bruno Ribeiro Garcia uc23200609