#include <stdio.h>
/*
Escreva um programa em C que leia um tempo em segundos e calcule o total de horas, minutos e
segundos equivalentes a este tempo dado de entrada.
Por exemplo: 7850 segundos é igual a: 2 horas 10 minutos e 50 segundos.
*/
int main()
{   
    int totalsegundos, horas, minutos, segundos;
    printf("Digite o total de segundos que deseja converter: ");
    scanf("%d", & totalsegundos);
    horas = totalsegundos / 3600;
    minutos = (totalsegundos % 3600) / 60;
    segundos = totalsegundos % 60;
    printf("\n%d segundos é igual a:\n%d horas %d minutos e %d segundos\n", totalsegundos, horas, minutos, segundos);
    return 0;
}
