#include <stdio.h>
#include <cs50.h>
#include <string.h>

int idadem, idadea ,idaded;
int mes_dia, anos_dia;

//QUESTAO 7

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Modo de uso: ./idade (mes ou/ ano ou/ dia)\n");
        return 1;
    }
    if(strcmp(argv[1], "ano") == 0)
    {
        printf("Indique quantos anos voce tem.\n");
        printf("Idade: ");
        scanf("%i", &idadea);
    }
    else if(strcmp(argv[1], "dia") == 0)
    {
        printf("Indique quantos dias de vida voce tem.\n");
        printf("Dias de vida: ");
        scanf("%i", &idaded);
        printf("Idade em dias: %i\n", idaded);
    }
    else if(strcmp(argv[1], "mes") == 0)
    {
        printf("Indique quantos meses de vida voce tem.\n");
        printf("Meses de vida: ");
        scanf("%i", &idadem);
    }


    mes_dia = idadem * 30;
    anos_dia = idadea * 365;

    if(strcmp(argv[1], "ano") == 0)
    {
        printf("Idade em dias: %i\n", anos_dia);
    }
    if(strcmp(argv[1], "mes") == 0)
    {
        printf("Idade em dias: %i\n", mes_dia);
    }
}  //Bruno Ribeiro Garcia uc23200609