#include <stdio.h> 
/*Uma sorveteria quer implementar um algoritmo que dado o peso em quilogramas do sorvete
escolhido pelo cliente, calcule e mostre o total a pagar. Para isto leia duas informações: o valor do
quilo do sorvete e também a quantidade em quilogramas comprada pelo cliente.*/
int main()
{
    float kgSoverte, pesoSorvete, valorSorvete;
    printf("\nQual o peso do seu sorvete em quilos?");
    scanf("%f", & kgSoverte);
    printf("\nQual o preço desse tipo de sorvete por quilo?");
    scanf("%f", & pesoSorvete);
    valorSorvete = kgSoverte * pesoSorvete;
    printf("\nO valor da compra é de %2.f", valorSorvete);
    return 0;
}