/*

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int A[5][5], i, j, sim;
    for ( i= 0; i < 5; i++){
        for (j = 0; j < 5; j++)
            scanf("%d", & A[i][j]);
    }
     
     system("cls");  
     printf("\nMatriz A:\n", A[i][j]);
     sim = 1;
     for (i = 0; i < 5; i++)
    {
        for(j=0; j<5; j++)
        if (A[i][j] != A[j][i]){
            sim = 0;
            break;
        }
    }
    if (sim)
    {
        printf("A matriz é simetrica");
    }
    else
    {
        printf("A matriz não é simetrica");
    }
             
                    
            
        return 0;
}