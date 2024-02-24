#include <stdio.h>
/*
Faça um programa em C que receba o preço de um produto, calcule e mostre o novo preço,
sabendo-se que este sofreu um desconto de 10%.
*/
int main()
{
    float valorproduto, valordesconto;
    printf("\nNossa loja está com promoção! Qual o preço do produto? ");
    scanf("%f", & valorproduto);
    valordesconto = valorproduto - ((valorproduto * 10) / 100); //em c não usamos a precedencia de (), {} e [] de prioridade da matemática
    printf("\nO valor final do produto é: %2.f\n", valordesconto);
    return 0;
}