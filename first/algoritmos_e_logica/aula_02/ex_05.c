#include <stdio.h>
/*
Um funcionário recebe um salário fixo mais 4% de comissão sobre as vendas. Faça um programa em C
que receba o salário fixo de um funcionário e o valor de suas vendas, calcule e mostre a comissão e o
salário final do funcionário.
*/
int main()
{
    float fixosalario, totalsalario;
    int qtvendas;
    printf("\nQual o salário do seu funcionário? ");
    scanf("%f", & fixosalario);
    printf("\nQuantas vendas esse funcionário fez esse mês? ");
    scanf("%d", & qtvendas);
    totalsalario = (fixosalario * 0.04) * qtvendas;
    printf("\nO salário final é de: %2.f ", totalsalario);
    return 0;
}