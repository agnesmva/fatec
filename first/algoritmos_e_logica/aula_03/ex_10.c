/*
Elabore um algoritmo que leia 3 medidas (a, b e c). Verifique se elas
podem ser medidas de um triângulo. Caso sejam, determine se este
triângulo é equilátero, isósceles ou escaleno.
*/
#include <stdio.h>
int main()
{
    float l1, l2, l3;
    printf("\nQual  lado 1 do seu triângulo em cm?");
    scanf("%f", & l1);
    printf("\nQual lado 2 do seu triângulo em cm?");
    scanf("%f", & l2);
    printf("\nQual lado 3 do seu triângulo em cm?");
    scanf("%f", & l3);
    if (((l1+l2)>l3) && ((l2+l3) > l1) && ((l3+l1) > l2))
    {
        if ((l1 == l2) && (l2 == l3))
        {
            printf ("\nEsse triângulo é equilátero, ou seja, todos os lados são iguais");
        }
        else if ((l1 == l2) || (l2 == l3) || (l1 == l3))
        {
            printf("\nEsse triângulo é isóceles, ou seja, tem pelos menos dois lados iguais");
        }
        else 
        {
            printf("\nEsse triângulo é escaleno, ou seja, todos os lados são diferentes");
        } 
    }
    else 
    {
        printf("\nOs valores inseridos não foram um triângulo válido");
    }
    return 0;
}