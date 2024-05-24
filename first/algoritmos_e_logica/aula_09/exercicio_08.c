/*

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int A[5][5], i, j;
    srand(time(NULL));
    for ( i= 0; i < 5; i++){
        for (j = 0; j < 5; j++)
            A[i][j] = rand()%50+1;
    }
        
            for (i = 0; i < 5; i++)
            {
                for(j=0; j<5; j++)
                if (A[i][j] == A[j][i]){
                    printf("é uma matriz simetrica");
                }
                    else
                    printf("não é uma matriz simetrica");
                    break;
            }
            
            
        return 0;
}