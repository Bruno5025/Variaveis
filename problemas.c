#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>

    int valor, valor2 ,frete ,despesas ,venda;
    int soma, sub, mult, dobro;
    double div;
    float conversao ,lucro ,area ,areac;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
// Questao 1 - ./problemas soma ou sub ou mult ou div
// Questao 2 - ./problemas dobro
// Questao 3 - ./problemas sala
// Questao 4 - ./problemas conversao
// Questao 5 - ./problemas mercadoria
// Questao 6 - ./problemas circulo

        printf("Modo de uso: ./problemas (questao correspondente)\n");
        return 1;
    }

    if(strcmp(argv[1], "soma") == 0|| strcmp(argv[1], "sub") == 0 || strcmp(argv[1], "mult") == 0 || strcmp(argv[1], "div") == 0)
    {
         printf("Indique dois valores para efetuar o problema matemático indicado anteriormente\n");

         printf("Valor1: ");
    scanf("%i", &valor);

    printf("Valor2: ");
    scanf("%i", &valor2);
    }
    if(strcmp(argv[1], "dobro") == 0)
    {
        printf("Indique um valor para retornar o seu dobro\n");
        printf("Valor: ");
        scanf("%i", &valor);
    }
    if(strcmp(argv[1], "sala") == 0)
    {
        printf("Base: ");
        scanf("%i", &valor);

        printf("Altura: ");
        scanf("%i", &valor2);
    }
    if(strcmp(argv[1], "conversao") == 0)
    {
        printf("Cotação atual do dolar : 4.95\n");
        printf("Valor em reais: ");
        scanf("%i", &valor);
    }
    if(strcmp(argv[1], "mercadoria") == 0)
    {
        printf("Valor da mercadoria: ");
        scanf("%i", &valor);

        printf("Valor do frete: ");
        scanf("%i", &frete);

        printf("Valor das despesas: ");
        scanf("%i", &despesas);

        printf("Valor de venda: ");
        scanf("%i", &venda);
    }
    if(strcmp(argv[1], "circulo") == 0)
    {
        printf("Raio do Circulo em centimetros: ");
        scanf("%i", &valor);
    }

    soma = (valor + valor2);
    sub = (valor - valor2);
    mult = (valor * valor2);
    div = ((float)valor / (float) valor2);
    dobro = (valor * 2);
    area = ((float)valor * (float)valor2);
    conversao = (valor * 4.95);
    lucro = ((float)venda / ((float)valor + (float)frete + (float)despesas))*100;
    areac = (3.14 * (valor * valor));

        if(strcmp(argv[1], "soma") == 0)
    {
        printf("A soma dos valores é: %i\n", (valor + valor2));
    }
    else if(strcmp(argv[1], "sub") == 0)
    {
        printf("A subtração dos valores é: %i\n", sub);
    }
    else if(strcmp(argv[1], "mult") == 0)
    {
        printf("A multiplicação dos valores é: %i\n", mult);
    }
    else if(strcmp(argv[1], "div") == 0)
    {
        printf("A divisão dos valores é: %.2f\n", div);
    }
    else if(strcmp(argv[1], "dobro") == 0)
    {
        printf("O dobro do valor inserido é: %i\n", dobro);
    }
    else if(strcmp(argv[1], "sala") == 0)
    {
        printf("A area da sala inserida em metros quadrados é: %.2f\n", area);
    }
    else if(strcmp(argv[1], "conversao") == 0)
    {
        printf("O valor em reais inserido convertido para dolares é: %.2f\n", conversao);
    }
    else if(strcmp(argv[1], "mercadoria") == 0)
    {
        printf("A porcentagem de lucro gerada por este produto é de: %.2f %%\n", lucro);
    }
    else if(strcmp(argv[1], "circulo") == 0)
    {
        printf("A area do circulo é de: %.2f centimetros quadrados\n", areac);
    }
    else
    {
        printf("Operação não reconhecida\n");
    }
}
    //Bruno Ribeiro Garcia uc23200609
