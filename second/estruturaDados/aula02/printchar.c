#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, i, soma= 0; //alocando memória em P
    p = (int *)calloc(5, sizeof(int)); //funcao calloc(1, sizeof()) //sizeof é o tamanho em bytes que vai ser alocado na memória
    for (i = 0; i < 5; i++)
    {
        scanf("%d", (p+i)); //não coloca & porque não é o conteúdo é o endereço físico
    }
    for (i = 0; i < 5; i++)
    {
        soma += *(p+i); 
    }
        printf("%d", soma);

    for ( i = 0; i < 5; i++)
    {
      
        printf("\no valor de p: %d\n", *(p+i));
    }


    
    return 0;
}
