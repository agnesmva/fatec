#include <stdio.h>
/*Elabore um programa em C que leia um valor em reais (R$) e mostre sua conversão para dólares ($).
Para isto o algoritmo deverá solicitar ao usuário a cotação do dólar. Mostre o resultado.*/
int main()
{
    float real, cotacao, converter;
    printf("\nQual o valor da cotação do dólar hoje? ");
    scanf("%f", & cotacao);
    printf("\nQuantos reais você deseja converter para dólar? ");
    scanf("%f", & real);
    converter = real / cotacao;
    printf("\nO valor da sua conversão é de: %2.f", converter);
    return 0;
}