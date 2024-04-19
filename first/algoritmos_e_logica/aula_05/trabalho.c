/*
 “Termina.com”

Elaborar um programa que, considerando como dados de entrada dois valores inteiros A e B, verifique se o número B está contido entre os últimos algarismos de A. Se B é maior que A à “Não termina”, caso contrário... precisa-se de verificação.
*/
#include <stdio.h>

int main() {
    int A, B, primeiro, segundo, qtA, qtB;

    printf("Digite o valor A: ");
    scanf("%d", &A);

    printf("Digite o valor B: ");
    scanf("%d", &B);
      primeiro = A;
      segundo = B;
    if (primeiro < segundo) {
        printf("A não pode estar contido dentro de B, pois %d é menor que %d\n", A, B);
      } 
    else if ((A == B))
    {
        printf("%d termina com %d\n", A, B);
    }
    
      else {
            while (segundo > 0)
            {
            
                if (primeiro%10 == segundo%10)
                {
                primeiro /= 10;
                segundo /= 10;
                }
                else
                {
                  break;
                }
            }
        if (segundo == 0)
              {
              printf("%d termina com %d\n", A, B);
              }
              else 
              {
              printf("%d não termina com %d\n", A, B);
              }
            
        
    }

    return 0;
}