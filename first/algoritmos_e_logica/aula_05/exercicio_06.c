#include <stdio.h>
int main()
{
    int cont = 0, id;
    float soma = 0, med;
    do
    {
        printf("\nDigite a Idade ou 0 para encerrar o programa: ");
        scanf("%d",& id)/
        if (id > 0)
        {
            cont++;
            soma+= id;
        }
        
    } while (id > 0);
    if (cont > 0)
    {
        med = cont/soma;
        printf("\nA média da idade das pessoas desse grupo é %d", med);
    }
    else 
    {
        printf("\nNão há pessoas nesse grupo");
    }
    
    
    return 0;
}
