/*
Elabore um programa que leia 3 valores inteiros (a,b e c) e os
coloque em ordem crescente, de modo que em a fique o menor
valor, em b o valor intermediário e em c o maior valor. Tente
pensar em uma solução com no máximo 3 estruturas de
seleção.
*/
#include <stdio.h>
int main()
{
    int a,b,c;
    printf("\nVamos colocar valores em ordem crescente? Insira o primeiro número ");
    scanf("%d", & a);
    printf("\nInsira o segundo número ");
    scanf("%d", & b);
    printf("\nInsira o segundo número ");
    scanf("%d", & c);
    if ((b>a)&&(b>c))
    {
        a=b, b=a, c=c;
        printf("\nprimeiro:%d \n segundo:%d \nterceiro:%d", a,b,c);
    }    
    else if ( (a>c) && (a>b))
    {
        a=c, b=b, c=a;
        printf("\nprimeiro:%d \n segundo:%d \nterceiro:%d", a,b,c);
    }
    else //n precisa haver troca
    {
        
        printf("\nprimeiro:%d \n segundo:%d \nterceiro:%d", a,b,c);
    }
    
    return 0;

}