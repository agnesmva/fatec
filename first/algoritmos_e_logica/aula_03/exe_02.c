/*
Elabore um programa que leia dois valores inteiros e determine se eles são iguais. Caso sejam diferentes, determine qual é o maior entre eles
*/
#include <stdio.h>
int main()
{
    int num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%d", & num1);
    printf("Digite o segundo número: ");
    scanf("%d", & num2);

    if (num1==num2)
    {
        printf("Os números são iguais");
    }
    
    else 
    {
            if (num1 > num2)
        {
            printf("O maior número é: %d", num1);
        }
            else 
        {
            printf("O maior número é: %d", num2);
        }
        
    }
    return   0;
}