/*
Elabore um programa que leia o sexo (uma letra/carctere) biológico de
uma pessoa (‘F’ – feminino ou ‘M’ – masculino) e escreva-o por extenso. //acrescentei intersexo
*/
#include <stdio.h> // <> ele busca dentro da pasta include libs
int main()
{   char sexo;
    printf("\nQual seu sexo biológico? Digite F para fêmea, M para macho");
    fflush(stdin); //limpa o buffer do teclado, importante usar é uma boa prática para chart e strings
    scanf("%c", & sexo);
    
    if (sexo == 'F' || sexo == 'f') //tentei inicialmente com aspas duplas não funcionou
    {
        printf("\nVocê é fêmea");
    }
    else if (sexo == 'M' || sexo == 'm') //enquanto não aprendemos touppercase
    {
        printf("\nVocê é macho");
    }
    else  
    {
        printf("\nDigite um caracter válido");
    }
    

}