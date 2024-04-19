#include <stdio.h>
#include <math.h>
int main()
{
    int num, td, d;
    printf("Digite um número?");
    scanf("%d", & num);
    for (d=2; d <= num/2; d++) // pode ser utilizado sqrt(num)
            if (num % d == 0)
            {
                td++;
                break;
            }
     if (td == 2)
            {
                printf("O número é primo\n");
            }
    else
            {
                printf("O número não é primo\n");
            }

}