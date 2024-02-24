#include <stdio.h> //std - stardart , i - input, o - output, h - header
int main()
{
    float num1, num2, media; //float 
    printf("\nDigite a primeira nota:");
        scanf ("%f", & num1);
    printf("\nDigite a segunda nota:");
        scanf ("%f", & num2);
        media = (num1 + num2) / 2;
    printf("\nO a média das suas notas foi de %2.f", media);
    return 0;

}