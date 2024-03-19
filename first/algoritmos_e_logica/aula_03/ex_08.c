/*
Uma loja, lançou uma grande promoção a seus clientes... Dependendo do valor da
compra, um certo desconto será concedido, como mostrado abaixo:
 20% se o valor da compra for maior ou igual a R$ 500,00
 15% se for maior ou igual a R$200,00 e menor que R$ 500,00
 10% caso seja menor que R$200,00.
Escreva um programa que após ler o valor da compra, calcule e mostre: o valor da compra do
cliente, o valor do desconto obtido e o valor a ser pago pelo cliente.
*/
#include <stdio.h>
int main() 
{
    float  valorcompra, valorfinal;
    printf("\nNossa loja está com descontos! Qual o valor da sua compra?");
    scanf("%f", & valorcompra);
    if (valorcompra >= 500.00)
    {
        printf("\nO valor da sua compra é: %.2f", valorcompra);
        printf("\nO valor do seu desconto é: 20%%");
        valorfinal = (valorcompra - (valorcompra * 0.2));
        printf("\nQue legal! A sua compra final ficou em: %.2f\n", valorfinal);
    }
    else if (valorcompra >= 200.00)
    {
        printf("\nO valor da sua compra é: %.2f", valorcompra);
        printf("\nO valor do seu desconto é: 15%%");
        valorfinal = (valorcompra - (valorcompra * 0.15));
        printf("\nQue legal! A sua compra final ficou em: %.2f\n", valorfinal);
    }
    else if (valorcompra < 200.00)
    {
        printf("\nO valor da sua compra é: %.2f", valorcompra);
        printf("\nO valor do seu desconto é: 10%%");
        valorfinal = (valorcompra -(valorcompra * 0.10) );
        printf("\nQue legal! A sua compra final ficou em: %.2f\n", valorfinal);
    }
    else 
    {
        printf("\nInsira um valor válido"); //o caso insira chart o programa é convertido para float retorna 0;
    }
    
    return 0;
}
