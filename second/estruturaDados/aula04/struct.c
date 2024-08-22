#include <stdio.h>
 struct dados
    {
        char nome[32];
        int idade;
    };
typedef struct dados PESSOA; //criando um tipo da estrutura de dados


int main()
{
    
    PESSOA a[3];
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("\nDigite o nome: ");
        fflush(stdin);
        gets(a[i].nome);
        printf("\nDigite a idade do usuário: ");
        fflush(stdin);
        scanf("%d", & a[i].idade);
    }
    printf("\n");
    for (size_t i = 0; i < 4; i++)
    {
        printf("%s tem  %d anos!\n", a[i].nome, a[i].idade);
    }
    
    
   
    return 0;
}
