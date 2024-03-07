/*
Uma competição de natação é organizada de acordo com idade de cada nadador. Elabore
um programa que leia a idade de um nadador e determine qual a categoria que ele deve
competir. Considere:
idade<=8 anos → Categoria Infantil A
idade <13 anos → Categoria Infantil B
idade <18 anos → Categoria Juvenil A
idade <21 anos → Categoria Juvenil B
idade>=21 → Categoria Sênior
*/
#include <stdio.h>
int main()
{
    int idade;
    printf("Vamos verificar se qual sua categoria para natação? Insira sua idade: ");
    scanf("%d", & idade);
    if ((idade > 0) & (idade < 100 ))
    {
                if (idade <= 8)
            {
                printf("\n Categoria Infantil A\n");
            }
            else if (idade <= 13)
            {
            printf("\n Categoria Infantil B\n");
            }
            else if (idade <= 18)
            {
            printf("\n Categoria Juvenil A\n");
            }
            else if (idade < 21)
            {
            printf("\n Categoria Juvenil B\n");
            }
            else
            {
                printf("\n Categoria Sênior\n");
            }
    }
    else 
    {
        printf("\nVocê precisa digitar uma idade válida");
    }
        
    return 0;
}