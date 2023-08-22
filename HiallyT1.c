#include <stdio.h>

int main(void)
{
    char nome[50];
    int idade;
    char matricula[20];
    char endereco[100];
    char curso[50];
    char periodo[40];
    char disciplina[50];
    float mensalidade;

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Idade: ");
    scanf("%d", &idade);
    getchar();

    printf("Matricula: ");
    fgets(matricula, sizeof(matricula), stdin);

    printf("Endereco: ");
    fgets(endereco, sizeof(endereco), stdin);

    printf("Curso: ");
    fgets(curso, sizeof(curso), stdin);

    printf("Periodo: ");
    fgets(periodo, sizeof(periodo), stdin);

    printf("Disciplina: ");
    fgets(disciplina, sizeof(disciplina), stdin);

    printf("Mensalidade: ");
    scanf("%f", &mensalidade);

    printf(
        "\nNome: %s"
        "Idade: %d\n"
        "Matricula: %s"
        "Endereco: %s"
        "Curso: %s"
        "Periodo: %s"
        "Disciplina: %s"
        "Mensalidade: %.2f\n",
        nome, idade, matricula, endereco, curso, periodo, disciplina, mensalidade);

//Bruno Ribeiro Garcia uc23200609

}
