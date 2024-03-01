#include <stdio.h>
int main()
{
    int num, prox;
    printf("Digite um número: ");
    scanf("%d", & num);
    prox = (num + 1) % 12;
    printf("Esse é o sucessor desse número em segundos: %d", prox);
    return 0;
}