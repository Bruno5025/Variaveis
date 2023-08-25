#include <stdio.h>

// QUESTAO 9

int main(void)
{
    int fabrica, final;

    printf("Valor de Fabrica: ");
    scanf("%i", &fabrica);

    final = ((fabrica / 100) * 28) + ((fabrica / 100) * 45) + fabrica;

    printf("Valor para o consumidor: %i\n", final);
}  //Bruno Ribeiro Garcia uc23200609