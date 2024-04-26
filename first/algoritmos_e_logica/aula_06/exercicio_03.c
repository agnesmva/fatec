/*Elabore um algoritmo que seja capaz de armazenar os primeiro vinte valores impares*/
#include <stdio.h> //input and output
int main()
{
    int A[20], i, imp=1;
    for (i = 0; i < 20; i++)
    {
        A[i] = imp;
        imp+=2;
    }
    for (i = 0; i < 20; i++)
    {
        printf("%d\t", A[i]);
    }
    
    
    
    return 0;
}

// programação dinâmica
/*
a[0]=1
for (i = 0; i < 20; i++)
    {
        A[i] = A[-1]+2;
        
    }
*/


//resultado a partir de um calculo matemático
/*
for (i = 0; i < 20; i++)
    {
        a[i] = 2 * i + 1;
    }

*/