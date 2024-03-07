/*
Elabore um algoritmo que determine se um ano é ou não bissexto.
Obs. Um ano é bissexto se ele for divisível por 400 ou se ele for divisível
por 4 e não por 100.
*/
#include <stdio.h>
int main()
{
    int ano;
    printf("\nVamos verificar se esse ano é bissexto? Insira um ano: ");
    scanf("%d", & ano);
    if (((ano %400) == 0) || (((ano%4) == 0)) && !(ano%100)==0)
    {
        printf("O ano inserido é bissexto!!");
    }
    else 
    {
        printf("O ano inserido não é bissexto.");
    }
    
    return 0;
}
