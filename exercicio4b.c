#include <stdio.h>

int array[] = {10, 1, 8, 7};
int tamanho = sizeof(array)/sizeof(array[0]);

int main(void)
{
int maior = array[0];
int menor = array[0];
   for (int i = 0 ; i < tamanho ; i++)
   {
        if(array[i] > maior)
           menor = array[i];
   }
   for (int i = 0 ; i < tamanho ; i++)
   {
        if(array[i] < menor)
           menor = array[i];
   }
   printf("O maior numero é: %d\n", maior);
   printf("O menor numero é: %d\n", menor);

}