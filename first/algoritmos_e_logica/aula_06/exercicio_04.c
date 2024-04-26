/*
Elabore um algoritmo que leia dois vetores de 10 valores cada e calcule o produto escalar entre eles:
PE = A[0]*B[0] + A[1]*B[2] + A[3]*B[3] ... + A[9]*B[9]
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[10], b[10], PE[10], i;
    srand(time(NULL));
     for (i = 0; i < 10; i++)
    {
        
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }
    PE = 0;
    for (i = 0; i < 10; i++)
    {
        PE[i] += a[i] * b[i];
        printf("%d * %d = %d \n", a[i], b[i], PE[i]);
       
    }
    printf("%d", PE[i]);
    return 0;
}


