/*
Elabore um alagoritmo que crie um tabuleiro de xadrez (8X8)
colocando 0 nas casas brancas e 1 nas casas pretas
*/

#include <stdio.h>

int main()
{
    int A[8][8], i, j;
    for ( i= 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if(j%2==0 || i%2==0){
                A[i][j]=0;
            }
            else {
                A[i][j]=1;
            }
    
    printf("\nMatriz A: \n");
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            printf("%3d", A[i][j]);
        printf("\n");
        
        
    }
        return 0;
}