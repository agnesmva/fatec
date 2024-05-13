/*
Elabore um algoritmo que leia um vetor capaz de armazenar 20 valores inteiros e, em seguida, gere outros dois vetores um formado pelos  valores pares e outro pelos valores ímpares
*/

// int *C, *B; isso daqui é para fazer alocação diretamente na memória

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int A[20], B[20], C[20], i, j=0, k=0;
    printf("Digite vinte números iremos verificar se eles são par ou impar:\n ");
    srand(time(NULL));
    for (i=0; i<20; i++)
       {
          A[i]= rand()%50+1;
          printf("%3d", A[i]);
       }
    for (i=0; i < 20; i++)
    {
        
        if (A[i]%2 == 0)
        {
           
            B[j] = A[i];
            j++;
        }
        
        else
        {
            C[k] = A[i];
            k++;
        }

    }
    printf("\nNumeros Pares:\n");
        for (i = 0; i < j; i++)
        printf("%3d", B[i]);
    printf("\nNumeros Impares:\n");
        for (i = 0; i < k; i++)
        printf("%3d", C[i]);
    return 0;
}
