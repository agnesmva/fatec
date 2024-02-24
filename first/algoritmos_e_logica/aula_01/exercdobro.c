#include <stdio.h>
int main()
{
    int num, dobro;
     printf("\nDigite um numero:");
     scanf("%d", & num); //scanf função que recebe dados, precisa declarar o tipo de dado que essa função vai receber e variavel scanf("%", & variavel)
        dobro = num*2; 
        printf("\nO dobro de %d = %d\n", num, dobro); 
    return 0;
}