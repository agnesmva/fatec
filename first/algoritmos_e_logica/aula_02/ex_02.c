#include <stdio.h> //Elabore um programa em C que leia as medidas de um terreno retangular(comprimento e largura) calcule e mostre qual é o perímetro e qual a área do terreno.
int main()
{
    float comp, larg, peri, area;
    printf("\nQual o comprimento do seu terreno? ");
    scanf("%f", & comp);
    printf("\nQual a largura do seu terreno?");
    scanf("%f", & larg);
    peri = 2 * (comp + larg); // perimetro precisa fazer multiplicado
    area = comp * larg;
    printf("\nAqui está o perímetro do seu terreno: %.2f que possui area de: %.2f\n", peri, area);

    return 0;

    // a ordem é %.2f

}