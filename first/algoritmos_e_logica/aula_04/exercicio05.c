#include <stdio.h>
int main()
{
    int nota;

    do
    {
        printf("\nDigite uma nota entre 0 e 10: ");
        scanf("%d", & nota);
        if ((nota<0) || (nota>10))
        {
            printf("Digite novamente. Nota inválida\n");
        }
    } while ((nota<0) || (nota>10));
        printf("A nota digitada é válida\n");
    return 0;
}
