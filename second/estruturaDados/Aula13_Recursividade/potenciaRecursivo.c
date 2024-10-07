#include <stdio.h>
 
int potencia(int x, int y)
{
	if (y==0)
		return 1;
	else{
        return x * potencia(x,y-1);
        
    }
	    
}
 
int main()
{
	int x,y, r;
	printf("\nDigite a base: ");
	scanf("%d", &x);
	printf("\nDigite o expoente: ");
	scanf("%d", &y);
	r = potencia(x,y);
	printf("\naA potência de %d elevado a %d = %d\n",x,y,r);
    return 0;
}