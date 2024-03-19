/*
O IMC – Índice de Massa Corporal é calculado pela seguinte fórmula:
Peso
IMC =
2
Altura
Elabore um programa que calcule leia o peso e a altura de uma pessoa e
calcule o seu IMC. Em seguida mostre a sua classificação:
*/
#include <stdio.h>
int main()
{
    float peso, alt, imc;
    printf("\nQual seu peso em kilos?");
    scanf("%f", & peso);
    printf("\nQual a sua altura em metros?");
    scanf("%f", & alt);
    imc =  peso / (alt * alt);
    if (imc <= 18.5)
    {
        printf("Seu imc é de %.2f e você está abaixo do peso considerado ideal", imc);
    }
        else 
            if (imc <= 24.9)
            {
                printf("Seu imc é de %.2f e você está no peso considerado ideal", imc);
            }
            else 
                if  (imc <= 29.9)
                {
                    printf("Seu imc é de %.2f e você está com sobrepeso", imc);
                }
                else 
                    if (imc <= 34.9)
                    {
                        printf("Seu imc é de %.2f e você está com Grau I de obesidade", imc);
                    }
                    else 
                        if  (imc <= 39.9)
                        {
                            printf("Seu imc é de %.2f e você está com Grau II de obesidade", imc);
                        }
                        else 
                            {
                                printf("Seu imc é de %.2f e você está com Grau III de obesidade", imc);
                            }
                    
        
    return 0;
}
// #include <math.h> x = pow(alt,2);
// não precisa verificar duas vezes;