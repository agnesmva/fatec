#include <stdio.h>
 
int soma(int x)
{
	if (x==1)
		return 1;
	else
	    return x+soma(x-1);
}
 
int main()
{
	int x, r;
	printf("\nDigite o primeiro valor: ");
	scanf("%d", &x);
	r = soma(x);
	printf("\nA Soma de %d até chegar em 1 é %d\n",x,r);
    return 0;
}