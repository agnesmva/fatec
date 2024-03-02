#include <stdio.h>
/*
1.) Elabore um programa que leia duas notas, calcule a média e verifique
se aluno foi aprovado ou reprovado. Para estar aprovado a média deverá
ser maior ou igual a 6
*/
int main()
{
    float n1, n2, media;
    printf("Qual a nota do seu primeiro bimestre? ");
    scanf("%f", & n1);
    printf("Qual a nota do seu segundo bimestre? ");
    scanf("%f", & n2);
    media = (n1 + n2) / 2;
    if (media >=6){
        
        printf("Você foi aprovado sua nota é de %.2f", media);
 
    }
    else {

        printf("Você foi reprovado por nota, sua nota é de %.2f", media);
    }
    return   0;

}