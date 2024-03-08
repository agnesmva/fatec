/*
Elabore um programa que leia 3 valores inteiros distintos entre si.
Mostre o maior entre eles
*/
#include <stdio.h>
int main ()
{
    int num1, num2, num3;
    printf("\nDigite o primeiro número: ");
    scanf("%d", & num1);
    printf("\nDigite o segundo número:  ");
    scanf("%d", & num2);
    printf("\nDigite o terceiro número:  ");
    scanf("%d", & num3);
    if ((num1 > num2) && (num1 > num3))
    {
        printf("\nO primeiro é o maior: %d\n", num1);
    }
        
    else if ((num2 > num1) && (num2 > num3))
    {
        printf("\nO segundo é o maior: %d\n", num2);
    }
    else if ((num3 > num1) && (num3 > num2))
    {
        printf("\nO terceiro número é o maior: %d\n", num3);
    }
    else 
    {
        printf("\nalgo deu errado, tente novamente")
    }
    
    return   0;
}
// correção

/*
if((num1>num2) && (num1>num3))
{
    print("\nO maior valor é: %d", num1);
}
else 
    if (num2>num3)
    {
        print("\nO maior valor é: %d", num2);
    }
    else 
    {
        print("\nO maior valor é: %d", num3);
    }
*/
// segunda possibilidade
/*
int m;
if((num1>num2) && (num1>num3))
{
    m = num1;
}
else 
    if (num2>num3)
    {
         m = num2;
    }
    else 
    {
        m = num3;
    }
print("\nO maior número é: %d", m)
*/