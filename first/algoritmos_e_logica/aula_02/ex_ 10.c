/*
DESAFIO: Faça um programa em C que leia um número entre 0 e 60 e determine o seu sucessor.
Porem, o sucessor do 60 deve ser o 0 (como em um cronômetro). Ex. Sucessor de 20 == 21, Sucessor
de 45 == 46 e Sucessor de 60 == 0.
*/
#include <stdio.h>
int main()
{
    int num, prox;
    printf("Digite um número: ");
    scanf("%d", & num);
    prox = (num + 1) % 61;
    printf("Esse é o sucessor desse número em segundos: %d", prox);
    return 0;
}