/*
Escreva um programa que leia a altura e o sexo (‘F’ ou ‘M’) de uma pessoa, outro
caractere deverá ser desconsiderado. Calcule e imprima o seu peso ideal utilizando as
seguintes fórmulas:
Para homens: (72.7*h)-58
Para mulheres: (62.1*h)-44.7
*/
#include <stdio.h>
int main()
{
    char sexo;
    float peso, h;
    printf("\nQual seu sexo biológico? Digite F para fêmea, M para macho: ");
    fflush(stdin);
    scanf("%c", & sexo);
    printf("\nQual a sua altura? ");
    scanf("%f", & h);
    
    if (sexo == 'F') //tentei inicialmente com aspas duplas não funcionou
    {
        peso = (72.7*h)-58;
        printf("\nSeu peso ideal é de: %.2f", peso);
    }
    else if  (sexo == 'M')
    {
        peso = (62.1*h)-44.7;
        printf("\nSeu peso ideal é de: %.2f", peso);
    }
    else
    {
        printf("Insira um valor válido");
    }
    return 0;
}