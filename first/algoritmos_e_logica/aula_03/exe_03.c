/*
Elabore um programa que leia o sexo (uma letra/carctere) biológico de
uma pessoa (‘F’ – feminino ou ‘M’ – masculino) e escreva-o por extenso.
*/
#include <stdio.h>
int main()
{   char sexo;
    printf("\nQual seu sexo biológico? Digite F para fêmea, M para macho e I para intersexo");
    scanf("%c", & sexo);
    
    if (sexo == 'F') //tentei inicialmente com aspas duplas não funcionou
    {
        printf("\nVocê é fêmea");
    }
    if (sexo == 'M')
    {
        printf("\nVocê é macho");
    }
    if (sexo == 'I') 
    {
        printf("\nVocê é intersexo");
    }
    

}