#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {


        printf("Modo de uso: ./avaliativo (questao correspondente)\n");
        return 1;
    }
    if(strcmp(argv[1], "questaoum") == 0){

    double x, resultado;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    if (x <= 4.0)
    {
        printf("O valor de x deve ser maior que 4 para evitar raiz negativa.\n");
    }
    else {
        resultado = (5 * x + 3) / sqrt(x * x - 16);

        printf("O valor de f(x) é: %lf\n", resultado);
    }
    }



    if(strcmp(argv[1], "questaodois") == 0){
        double alturaChico = 1.50;
    double alturaZe = 1.10;
    int anos = 0;

    while (alturaZe <= alturaChico) {
        alturaChico += 0.02;
        alturaZe += 0.03;
        anos++;
    }

    printf("Serão necessários %d anos para que Zé seja maior que Chico.\n", anos);
    }

    if(strcmp(argv[1], "questaotres") == 0){

    double A, B, C;

    printf("Digite o valor de A: ");
    scanf("%lf", &A);

    printf("Digite o valor de B: ");
    scanf("%lf", &B);

    printf("Digite o valor de C: ");
    scanf("%lf", &C);

    if (A + B > C && A + C > B && B + C > A) {
        if (A == B && B == C) {
            printf("É um triângulo equilátero.\n");
        }
        else if (A == B || A == C || B == C) {
            printf("É um triângulo isósceles.\n");
        }
        else {
            printf("É um triângulo escaleno.\n");
        }
    } else {
        printf("Os valores fornecidos não formam um triângulo.\n");
    }
    }

    if(strcmp(argv[1], "questaoquatro") == 0){
        double A, B, C;
    double anguloA, anguloB, anguloC;

    printf("Digite o valor de A: ");
    scanf("%lf", &A);

    printf("Digite o valor de B: ");
    scanf("%lf", &B);

    printf("Digite o valor de C: ");
    scanf("%lf", &C);

    if (A + B > C && A + C > B && B + C > A) {
        anguloA = acos((B * B + C * C - A * A) / (2 * B * C)) * 180 / 3.1415;
        anguloB = acos((A * A + C * C - B * B) / (2 * A * C)) * 180 / 3.1415;
        anguloC = 180 - anguloA - anguloB;

        if (anguloA == 90 || anguloB == 90 || anguloC == 90) {
            printf("Triângulo Retângulo\n");
        } else if (anguloA > 90 || anguloB > 90 || anguloC > 90) {
            printf("Triângulo Obtusângulo\n");
        } else {
            printf("Triângulo Acutângulo\n");
        }
    } else {
        printf("Os valores fornecidos não formam um triângulo.\n");
    }
    }


    if(strcmp(argv[1], "questaocinco") == 0){
        double x1, y1, x2, y2;

    printf("Digite as coordenadas do ponto 1 (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Digite as coordenadas do ponto 2 (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    double distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("A distância entre os pontos é: %.4lf\n", distancia);
    }

    if(strcmp(argv[1], "questaoseis") == 0){
         double x, y;

    printf("Digite as coordenadas do ponto (x y): ");
    scanf("%lf %lf", &x, &y);

    if (x == 0 && y == 0) {
        printf("Origem\n");
    } else if (x == 0) {
        printf("Eixo Y\n");
    } else if (y == 0) {
        printf("Eixo X\n");
    } else if (x > 0 && y > 0) {
        printf("Q1\n");
    } else if (x < 0 && y > 0) {
        printf("Q2\n");
    } else if (x < 0 && y < 0) {
        printf("Q3\n");
    } else {
        printf("Q4\n");
    }
    }
    if(strcmp(argv[1], "questaosete") == 0){
        int num_alunos = 30;
    double notas[num_alunos];
    double media_ponderada;
    double media_geral = 0.0;
    int aluno;

    for (aluno = 1; aluno <= num_alunos; aluno++) {
        double n1, n2, n3;

        printf("Digite as três notas do aluno %d (n1 n2 n3): ", aluno);
        scanf("%lf %lf %lf", &n1, &n2, &n3);

        media_ponderada = (n1 * 2 + n2 * 4 + n3 * 3) / 10;
        media_geral += media_ponderada;

        printf("A média ponderada do aluno %d é: %.2lf\n", aluno, media_ponderada);
        if (media_ponderada >= 7.0) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }
    media_geral /= num_alunos;
    printf("A média geral da turma é: %.2lf\n", media_geral);
    }



    if(strcmp(argv[1], "questaooito") == 0){

            double salario, soma_salarios = 0;
    int numero_filhos, total_habitantes = 0;
    double maior_salario = 0;
    int habitantes_com_salario_ate_100 = 0;

    do {
        printf("Digite o salário (ou um valor negativo para encerrar): ");
        scanf("%lf", &salario);

        if (salario < 0) {
            break;
        }

        printf("Digite o número de filhos: ");
        scanf("%d", &numero_filhos);

        soma_salarios += salario;

        if (salario > maior_salario) {
            maior_salario = salario;
        }

        if (salario <= 100.0) {
            habitantes_com_salario_ate_100++;
        }

        total_habitantes++;

    } while (1);
    if (total_habitantes > 0) {
        double media_salario = soma_salarios / total_habitantes;
        double media_filhos = (double)total_habitantes / total_habitantes;

        printf("a) Média do salário da população: %.2lf\n", media_salario);
        printf("b) Média do número de filhos: %.2lf\n", media_filhos);
        printf("c) Maior salário: %.2lf\n", maior_salario);
        double percentual_salario_ate_100 = (double)habitantes_com_salario_ate_100 / total_habitantes * 100.0;
        printf("d) Percentual de pessoas com salário até R$100,00: %.2lf%%\n", percentual_salario_ate_100);
    } else {
        printf("Nenhum dado foi inserido.\n");
    }
    }

     if(strcmp(argv[1], "questaonove") == 0){

        int codigo_voto;
    int votos_candidato[4] = {0}; // Inicializa com zero votos para cada candidato
    int votos_nulos = 0;
    int votos_em_branco = 0;

    printf("Digite o código do candidato (ou 0 para encerrar): ");

    while (1) {
        scanf("%d", &codigo_voto);

        if (codigo_voto == 0) {
            break;
        }

        switch (codigo_voto) {
            case 1:
            case 2:
            case 3:
            case 4:
                votos_candidato[codigo_voto - 1]++;
                break;
            case 5:
                votos_nulos++;
                break;
            case 6:
                votos_em_branco++;
                break;
            default:
                printf("Código de voto inválido. Ignorando.\n");
                break;
        }

        printf("Digite o próximo código do candidato (ou 0 para encerrar): ");
    }

    printf("Total de votos para cada candidato:\n");
    for (int i = 0; i < 4; i++) {
        printf("Candidato %d: %d votos\n", i + 1, votos_candidato[i]);
    }
    printf("Total de votos nulos: %d\n", votos_nulos);
    printf("Total de votos em branco: %d\n", votos_em_branco);
    }

    if(strcmp(argv[1], "questaodez") == 0){
    int codigo_cidade;
    char estado[3];
    int num_veiculos;
    int num_acidentes;
    char cidade_maior_acidente[50];
    char cidade_menor_acidente[50];
    int maior_acidente = -1;
    int menor_acidente = -1;
    int total_veiculos = 0;
    int total_acidentes_RS = 0;
    int num_cidades_RS = 0;

    for (int i = 1; i <= 200; i++) {
        printf("Digite o código da cidade: ");
        scanf("%d", &codigo_cidade);

        if (codigo_cidade == 0) {
            break;
        }

        printf("Digite o estado da cidade (RS, SC, PR, SP, RJ, ...): ");
        scanf("%s", estado);

        printf("Digite o número de veículos de passeio em 1992: ");
        scanf("%d", &num_veiculos);

        printf("Digite o número de acidentes de trânsito com vítimas em 1992: ");
        scanf("%d", &num_acidentes);

        total_veiculos += num_veiculos;

        if (strcmp(estado, "RS") == 0) {
            total_acidentes_RS += num_acidentes;
            num_cidades_RS++;
        }
        if (maior_acidente == -1 || num_acidentes > maior_acidente) {
            maior_acidente = num_acidentes;
            strcpy(cidade_maior_acidente, estado);
        }

        if (menor_acidente == -1 || num_acidentes < menor_acidente) {
            menor_acidente = num_acidentes;
            strcpy(cidade_menor_acidente, estado);
        }
    }

    if (maior_acidente != -1 && menor_acidente != -1) {
        printf("a) Maior índice de acidentes pertence a %s com %d acidentes.\n", cidade_maior_acidente, maior_acidente);
        printf("   Menor índice de acidentes pertence a %s com %d acidentes.\n", cidade_menor_acidente, menor_acidente);
    } else {
        printf("Não foram fornecidos dados válidos.\n");
    }

    if (total_veiculos > 0) {
        double media_veiculos = (double)total_veiculos / 200;
        printf("b) Média de veículos nas cidades brasileiras: %.2lf\n", media_veiculos);
    } else {
        printf("Não foram fornecidos dados válidos.\n");
    }

    if (num_cidades_RS > 0) {
        double media_acidentes_RS = (double)total_acidentes_RS / num_cidades_RS;
        printf("c) Média de acidentes com vítimas no Rio Grande do Sul: %.2lf\n", media_acidentes_RS);
    } else {
        printf("Não foram fornecidos dados válidos para o Rio Grande do Sul.\n");
    }
    }
}