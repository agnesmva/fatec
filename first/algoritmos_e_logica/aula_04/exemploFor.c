/*
Exemplo: Programa para somar os números menores
ou iguais a 100.
}
*/
#include <stdio.h>
main()
    { int num, soma=0;

    for (num=1; num<=100; num++)
        soma += num;
        printf("\nA soma = %d", soma);
        return 0;
}