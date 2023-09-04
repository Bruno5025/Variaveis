#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float valor1,valor2,valor3,media;
int a,b;
int aplicouAumento = 0;
float i, j, l;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
// Questao 6 - ./exercicios678910 par
// Questao 7 - ./exercicios678910 media
// Questao 8 - ./exercicios678910 aposentadoria
// Questao 9 - ./exercicios678910 aumento
// Questao 10 - ./exercicios678910 raizes

        printf("Modo de uso: ./exercicios678910 (questao correspondente)\n");
        return 1;
    }
    //Questão 6
    if(strcmp(argv[1], "par") == 0)
    {
        printf("Digite um Número inteiro: ");
        scanf("%i", &a);
        if(a%2==0)
        {
            printf("O número digitado foi %i e ele é par!\n", a);
        }
    }
    //Questão 7
    if(strcmp(argv[1], "media") == 0)
    {
        printf("Nota da prova 1: ");
        scanf("%f", &valor1);
        printf("Nota da prova 2: ");
        scanf("%f", &valor2);
        printf("Nota da prova 3: ");
        scanf("%f", &valor3);

        media = ((valor1 * 1) + (valor2 * 1) + (valor3 * 2))/ 4;

        if(media >= 7.0)
        printf("Você foi aprovado com nota %.1f\n", media);
        else
        printf("Você foi reprovado com nota %.1f\n", media);
    }
    //Questão 8
    if(strcmp(argv[1], "aposentadoria") == 0)
    {
        printf("Idade: ");
        scanf("%i", &a);
        printf("Anos de Trabalho: ");
        scanf("%i", &b);

        if(a >= 65 || b >= 30)
        printf("Aposentadoria Liberada!\n");
        else if(a >= 60 && b >= 25)
        printf("Aposentadoria Liberada!\n");
        else
        printf("Aposentadoria Negada.\n");
    }
    //Questão 9
    if (strcmp(argv[1], "aumento") == 0) {
        printf("Salário atual: ");
        scanf("%f", &valor1);
        printf("Anos de serviço na empresa: ");
        scanf("%i", &a);

        if (valor1 <= 500) {
            valor1 *= 1.25;
            aplicouAumento = 1;
        } else if (valor1 <= 1000) {
            valor1 *= 1.20;
            aplicouAumento = 1;
        } else if (valor1 <= 1500) {
            valor1 *= 1.15;
            aplicouAumento = 1;
        } else if (valor1 <= 2000) {
            valor1 *= 1.10;
            aplicouAumento = 1;
        }

        if (a > 0) {
            if (a <= 3) {
                valor1 += 100;
                aplicouAumento = 1;
            } else if (a <= 6) {
                valor1 += 200;
                aplicouAumento = 1;
            } else if (a <= 10) {
                valor1 += 300;
                aplicouAumento = 1;
            } else if (a > 10) {
                valor1 += 500;
                aplicouAumento = 1;
            }
        }

        if (!aplicouAumento) {
            printf("Você não tem direito ao aumento de salário\n");
        } else {
            printf("Seu novo salário é de %.2f reais\n", valor1);
        }
    }
    //Questão 10
    if(strcmp(argv[1], "raizes") == 0){
        printf("Digite os coeficientes i, j e l da equação quadrática (ix^2 + jx + l = 0):\n");
    printf("i: ");
    scanf("%f", &i);
    printf("j: ");
    scanf("%f", &j);
    printf("l: ");
    scanf("%f", &l);

    float delta = j * j - 4 * i * l;

    if (delta < 0) {
        printf("Não existe raiz.\n");
    } else if (delta == 0) {
        float raiz = -j / (2 * i);
        printf("Raiz única: %.2f\n", raiz);
    } else {
        float raiz1 = (-j + sqrt(delta)) / (2 * i);
        float raiz2 = (-j - sqrt(delta)) / (2 * i);
        printf("Duas raízes reais: %.2f e %.2f\n", raiz1, raiz2);
    }
    }
}