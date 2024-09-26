#include <stdio.h>

int main()
{
    int heranca;
    printf("Qual o valor da herança? ");
    scanf("%d", &heranca);

    // Parte da mãe é 1/8 da herança
    int parte_mae = heranca / 8;

    // Cada menino recebe 2 vezes a parte da mãe
    int parte_menino = 2 * parte_mae;

    // A menina recebe 3 vezes a parte da mãe
    int parte_menina = 3 * parte_mae;

    printf("A mãe receberá: %d\n", parte_mae);
    printf("Cada menino receberá: %d\n", parte_menino);
    printf("A menina receberá: %d\n", parte_menina);

    return 0;
}
