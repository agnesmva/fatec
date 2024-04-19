#include <stdio.h>
main ()
{
 int num, algarismos = 0; // precisa inicializar
	
	printf(" \n Insira um numero inteiro: ");
	scanf("%d", &num);
	
	if (num == 0)
	{
		algarismos = 1;
	}
	else
	{
		while (num > 0)
		{
			num /= 10;
			algarismos++;
		}
	}
    //só consegui usar para contar até 10 algarismos, mais do que isso dá erro e vai pra "0"
	
	printf("\n O numero possui %d algarismos.", algarismos);
}