/*
Elabore um programa que leia uma matriz 4X6 e calcule e mostre a sua matriz transposta equivalente
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int A[4][6], i, j, B[6][4];
    //zerando a matriz inteira
    srand(time(NULL));
    for ( i= 0; i < 4; i++)
        for (j = 0; j < 6; j++)
            A[i][j] = rand()%50+1; // +1 usa para gerar numeros maiores que 1 

    for ( i= 0; i < 6; i++)
        for (j = 0; j < 4; j++)
        {
            B[i][j] = A[j][i];
        }
        
            
    
    printf("\nMatriz A: \n");
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
            printf("%3d", A[i][j]);
        printf("\n");
        
        
    }
     printf("\nMatriz transposta B: \n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
            printf("%3d", B[i][j]);
        printf("\n");
        
        
    }
    
    

    return 0;
}