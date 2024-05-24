#include <stdio.h>
int main()
{
    int A[5][5], i, j;
    //zerando a matriz inteira
    for ( i= 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            A[i][j] = 0;

    for ( i= 0; i < 5; i++)
        for (j = 0; j < 5; j++)
        if (i+j<4)
        {
            A[i][j] = 1;
        }
        
            
    
    printf("\nTriângulo Superior Direito: \n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%3d", A[i][j]);
        printf("\n");
        
        
    }
    
    

    return 0;
}