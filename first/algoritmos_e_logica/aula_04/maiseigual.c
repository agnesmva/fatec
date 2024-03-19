#include <stdio.h>
int main()
{
    int num = 1, soma = 0;
    while (num <=100)
    {
        soma +=num;
        num++;
    }
    printf("%d\t",soma);
    return 0;
}
// soma + valor = soma