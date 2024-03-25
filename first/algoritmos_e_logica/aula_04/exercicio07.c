/* Elabore um algoritmo, usando a estrutura PARA, que calcule
a soma de 10 números lidos pelo teclado. */
#include <stdio.h>
int main()
{
    int num, soma;
    for (num=1; num <= 10; num++)
    {
        soma +=num;
        printf("\nA soma = %d", soma);
    }
    
    return 0;
}
