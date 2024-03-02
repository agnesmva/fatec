#include <stdio.h>
int main()
{
    int num, resto;
    printf("Digite um número: ");
    scanf("%d",& num);
    resto = num % 2;
    if (resto == 0)
    printf("Esse número é par %d", num);
    else
    printf("Esse número é impar %d", num);
}