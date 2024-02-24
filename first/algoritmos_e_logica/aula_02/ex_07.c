#include <stdio.h>
/*
Elabore um programa em C leia um numero inteiro (max. 3 algarismos) e mostre os algarismos em
separado. Ex. NUM == 725 o algoritmo produzirá: Centena = 7, Dezena = 2 e Unidade = 5.
*/
int main()
{
    int num, cen, dez, uni;
    printf("Digite um número: ");
    scanf("%d", & num);
    cen = (num / 100);
    dez = (num % 100) / 10;
    uni = (num % 100) % 10;
    printf("\nA decomposição do número fica: %d centenas, %d dezenas e %d unidades\n", cen, dez, uni);
    return 0;
}