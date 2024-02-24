#include <stdio.h> 
/*
Faça um programa em C que leia dois valores inteiros e positivos e armazene nas variáveis A e B
respectivamente. Em seguida troque o conteúdo das variáveis, ou seja, A deverá receber o valor de B e B
o valor de A.
*/
int main()
{
    int A, B, C;
    printf("Digite o número A: ");
    scanf("%d", & A);
    printf("Digite o número B: ");
    scanf("%d", & B);
    C = A;
    A = B;
    B = C;
    printf("Número A: %d\nNúmero B: %d \n", A, B);
    return 0;

}