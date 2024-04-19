#include <stdio.h>

int main() {
    int A, B, primeiro, segundo, qtA, qtB;

    printf("Digite o valor A: ");
    scanf("%d", &A);

    printf("Digite o valor B: ");
    scanf("%d", &B);
      primeiro = A;
      segundo = B;
    if (primeiro < segundo) 
        printf("A não pode estar contido dentro de B, pois %d é menor que %d\n", A, B);
    else if (primeiro == segundo)
        printf("%d termina com %d\n", A, B);
    else {
        int seg = segundo;

        while (seg*10 < primeiro)
            seg *= 10;

        if (primeiro - seg == segundo)
            printf("%d termina com %d\n", A, B);
        else
            printf("%d não termina com %d\n", A, B);
    }
    return 0;
}