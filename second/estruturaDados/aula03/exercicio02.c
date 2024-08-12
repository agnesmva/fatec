/*
Elabore uma função que receba como parâmetro duas notas (n1 e n2). A
função deverá retornar com a maior nota e também com a média entre elas (um
dos cálculos deverá ser retornado via parâmetro). Faça a função principal e a
devida chamada a função criada.
*/
#include <stdio.h>
float notas(float n1, float n2, float *med){
     float maior;
     (*med) = (n1+n2) /2;

     if (n1 > n2)
     {
        maior = n1;
     }
     else
        maior = n2;

     return maior;
}
int main()
{
    float a = 10, b = 5, c, media;
    c = notas(a, b, &media);
    printf("A maior entre as notas é %.2f e a média é %.2f\n", c, media);
    return 0;
}