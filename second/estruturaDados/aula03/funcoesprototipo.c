/*
Parametros = transporte de funções 
 */

#include <stdio.h>
int soma(int x, int y);
int main()
{
    int a = 10, b = 5, c;
    c = soma(a, b);

    printf("\nA soma de %d com %d = %d", a, b, c);
    return 0;
}

int soma(int x, int y){
     return x + y;
}