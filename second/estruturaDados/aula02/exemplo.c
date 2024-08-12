#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, a; //alocando memória em P
    p = (int *)calloc(5, sizeof(int)); //funcao calloc(1, sizeof()) //sizeof é o tamanho em bytes que vai ser alocado na memória
    *p = 5;
    *(p+1) = 10;
    a = *(p+1);
    printf("\no valor de p: %d\n", *p);
     printf("\no valor de a: %d\n", a);
    return 0;
}
