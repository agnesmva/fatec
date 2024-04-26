/*
Elabore um algoritmo que leia 2 vetores de 10 números inteiros cada e em seguida calcule e 
imprima um terceiro vetor formado pela soma dos valores respectivos dos vetores lidos.
*/
#include <stdio.h> //input and output
#include <time.h> //time
#include <stdlib.h> //rand biblioteca 
int main()
{
    int a[10], b[10], soma[10], i;
    srand(time(NULL));
     for (i = 0; i < 10; i++)
    {
        
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    puts("Resultados: "); //puts put s (bota uma string)
    for (i = 0; i < 10; i++)
    {
        soma[i] = a[i] + b[i];
        printf("%d + %d = %d \n", a[i], b[i], soma[i]);
       
    }
    
    return 0;
}


