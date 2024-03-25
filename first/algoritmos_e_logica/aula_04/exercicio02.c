#include <stdio.h>
int main()
{
    int n, cont=1, r;
    printf("\nDigite o último número: ");
    scanf("%d",&n);
    while (cont <= 10)
    {
        r=n*cont;
        printf("\n%d x %d = %d a tabuada desejada", n, cont, r);
        cont++;
    }
    
    return 0;
}