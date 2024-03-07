/*
Elabore um programa que leia o sexo (uma letra/carctere) biológico de
uma pessoa (‘F’ – feminino ou ‘M’ – masculino) e escreva-o por extenso. //acrescentei intersexo
*/
#include <stdio.h>
int main()
{   char sexo;
    printf("\nQual seu sexo biológico? Digite F para fêmea, M para macho");
    scanf("%c", & sexo);
    
    if (sexo == 'F') //tentei inicialmente com aspas duplas não funcionou
    {
        printf("\nVocê é fêmea");
    }
    else if (sexo == 'M')
    {
        printf("\nVocê é macho");
    }
    else  
    {
        printf("\nDigite um caracter válido");
    }
    

}