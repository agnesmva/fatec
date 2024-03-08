/*No Brasil, temos regras para quem pode ou não votar. Vejam:
    Idade < 16 → “Votar é proibido!”
    Idade >=16 e idade < 18 ou idade >= 65 → “Votar é facultativo!”
    Idade >=18 e idade < 65 → “Votar é obrigatório!”
    
    Elabore um programa que leia da idade de uma pessoa e determina sua situação com
relação ao seu voto.
    */
#include <stdio.h>
int main()
{
    int idade;
    printf("\nQual a sua idade?");
    scanf("%d", & idade);
    if( idade < 16)
    {
        printf("\nVotar é proibido pois você só tem apenas %d anos", idade);
    }
    else if ((idade >=16) && (idade < 18) || (idade >= 65))
    {
        printf("\nVotar é facultativo, pois você tem %d anos\n", idade);
    }
    else if ((idade >= 18) &&(idade < 65))
    {
        printf("\nVotar é obrigatório, pois você tem %d anos", idade);
    }
    else {
        printf("Insira um valor válido");
    }
    
    
    return 0;
}
/*
if (idade < 16)
{
    print ("\nVotar é proibido")
}
else 
    if (idade > 18 && idade < 65)
    {
        print("\nVotar é obrigatório")
    }
    else
    {
        print("\nVotar é facultativo")
    }
*/