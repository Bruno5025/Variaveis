#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]){
    if (argc != 2)
    {
        printf("Modo de uso: ./switch (questao correspondente)\n");
        return 1;
    }

    if(strcmp(argv[1], "DDD") == 0)
    {
        int ddd;
    printf("Digite o seu DDD: ");
    scanf("%i", &ddd);

    switch(ddd)
    {
        case 61:
        printf("Você mora em Brasília\n");
        break;
    case 71:
        printf("Você mora em Salvador\n");
        break;
    case 11:
        printf("Você mora em São Paulo\n");
        break;
    case 21:
        printf("Você mora no Rio de Janeiro\n");
        break;
    case 32:
        printf("Você mora em Juiz de Fora\n");
        break;
    case 19:
        printf("Você mora no Campinas\n");
        break;
    case 27:
        printf("Você mora em Vitória\n");
        break;
    case 31:
        printf("Você mora em Belo Horizonte\n");
        break;
    default:
        printf("DDD não reconhecido\n");
        break;
    }
    }
    if(strcmp(argv[1], "cardapio") == 0)
    {
        int valores;
        printf("Digite o número do pedido desejado: ");
        scanf("%i", &valores);

        switch(valores)
        {
            case 100:
            printf("O Cachorro quente custa R$ 10,10\n");
            break;
            case 101:
            printf("O Bauru Simples custa R$ 8,30\n");
            break;
            case 102:
            printf("O Bauru com ovo custa R$ 8,50\n");
            break;
            case 103:
            printf("O Hamburguer custa R$ 12,50\n");
            break;
            case 104:
            printf("O Cheeseburguer custa R$ 13,25\n");
            break;
            default:
            printf("Não existe no cardápio\n");
            break;
        }
    }
    if(strcmp(argv[1], "calorias") == 0)
    {
        int prato, bebida, sobremesa;
        int calorias = 0;

        printf("Escolha um prato:\n");
    printf("1. Vegetariano\n");
    printf("2. Peixe\n");
    printf("3. Frango\n");
    printf("4. Carne\n");
    scanf("%d", &prato);

    printf("Escolha uma sobremesa:\n");
    printf("1. Abacaxi\n");
    printf("2. Sorvete Diet\n");
    printf("3. Mouse Diet\n");
    printf("4. Mouse Chocolate\n");
    scanf("%d", &sobremesa);

    printf("Escolha uma bebida:\n");
    printf("1. Chá\n");
    printf("2. Suco de Laranja\n");
    printf("3. Suco de Melão\n");
    printf("4. Refrigerante Diet\n");
    scanf("%d", &bebida);

    switch (prato) {
        case 1:
            calorias += 180;
            break;
        case 2:
            calorias += 230;
            break;
        case 3:
            calorias += 250;
            break;
        case 4:
            calorias += 350;
            break;
        default:
            printf("Opção de prato inválida.\n");
            return 1;
    }

    switch (sobremesa) {
        case 1:
            calorias += 75;
            break;
        case 2:
            calorias += 110;
            break;
        case 3:
            calorias += 170;
            break;
        case 4:
            calorias += 200;
            break;
        default:
            printf("Opção de sobremesa inválida.\n");
            return 1;
    }

    switch (bebida) {
        case 1:
            calorias += 20;
            break;
        case 2:
            calorias += 70;
            break;
        case 3:
            calorias += 100;
            break;
        case 4:
            calorias += 65;
            break;
        default:
            printf("Opção de bebida inválida.\n");
            return 1;
    }

    printf("A quantidade total de calorias da refeição é: %i calorias.\n", calorias);
    }
}