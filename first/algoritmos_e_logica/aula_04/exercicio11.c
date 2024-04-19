#include <stdio.h>
int main()
{
    int num, soma, d;
    printf("Digite um número?");
    scanf("%d", & num);
    for (d=1; d <= num/2; d++) // pode ser utilizado sqrt(num)
            if (num % d == 0)
            {
                soma += d;
            }
     if (soma == num)
            {
                printf("O número é perfeito\n");
            }
    else
            {
                printf("O número não é perfeito\n");
            }

}