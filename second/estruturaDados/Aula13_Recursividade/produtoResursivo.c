#include <stdio.h>
 
int produto(int x, int y)
{
	if (y==0)
		return 0;
	else
	    return x+produto(x,y-1);
}
 
main()
{
	int x,y, r;
	printf("\nDigite o primeiro valor: ");
	scanf("%d", &x);
	printf("\nDigite o segundo valor: ");
	scanf("%d", &y);
	r = produto(x,y);
	printf("\nO produto de %d por %d = %d",x,y,r);
}