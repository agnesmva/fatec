/*
Elabore um programa em C que calcule a soma dos valores ímpares compreendidos entre dois valores A e B lidos pelo teclado. Os valores de A e B também deverão ser somados se forem valores ímpares. Veja alguns exemplos:

A = 10 B = 15 --> calcular a soma: 11 + 13 + 15 --> 39
*/
#include <stdio.h>
int main()
{
    int A, B, resultado;
    printf("Digite o primeiro número: ");
    scanf("%d", & A);
    printf("Digite o segundo número: ");
    scanf("%d", & B);
            if (A/2 == 0)
            {
               A +1;
            }
            else if (B/2 == 0)
            {
                B-1;
            }
        for (int i = A + 1; i <= B; i += 2) {
        resultado += i;
    }
    printf("o valor de da soma dos ímpares de A até B são: %d", resultado);
    return 0;
}