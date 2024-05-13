#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int A[20], i, aux;
    printf("Digite vinte números iremos verificar se eles são par ou impar:\n ");
    srand(time(NULL));
    for (i=0; i<20; i++)
       {
          A[i]= rand()%50+1;
          printf("%3d\t", A[i]);
       }
    for (i = 0; i < 10; i++)
    {
        aux = A[i];
        A[i] = A[i+10];
        A[i+10] = aux;
    }
    printf("Vetor modificado\n");
    for ( i = 0; i < 20; i++)
    {
       printf("%3d", A[i]);
    }
    
    return 0;
}