/*
Considerando o exemplo antiror, faça um programa que leia um vetor de 10 números inteiros 
e calcule e mostre a soma dos valores do vetor.
*/
#include <stdio.h>
int main()
{
    int a[10], soma, i;
    for (i = 0; i < 10; i++)
    {
        printf("Digite o [%d] número: ", i+1);
        scanf("%d", & a[i]);
    }
    soma=0;
    puts("Vetor lido:"); //puts put s (bota uma string)
    for (i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
        soma += a[i];
    }
    printf("Soma dos valores: %d", soma);
    
    
    return 0;
}
