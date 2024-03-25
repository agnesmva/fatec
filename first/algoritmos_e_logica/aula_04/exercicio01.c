#include <stdio.h>
int main()
{
    int n, imp=1, soma=0;
    printf("\nDigite o último número: ");
    scanf("%d",&n);
    while (imp <= n)
    {
        soma+=imp;
        imp+=2;
        
      
    }
    printf("\n%d", soma);
    
    return 0;
}
