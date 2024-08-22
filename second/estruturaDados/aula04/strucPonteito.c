#include <stdio.h>
#include <stdlib.h>

 struct dados
    {
        char nome[32];
        int idade;
    };
typedef struct dados PESSOA; //criando um tipo da estrutura de dados


int main()
{
    
    PESSOA *p;
    p = (PESSOA *)calloc(1, sizeof(PESSOA));

    printf("\nDigite o nome: ");
    fflush(stdin);
    gets(p->nome);
    printf("\nDigite a idade do usuário: ");
    scanf("%d", & p->idade);
    printf("\n");
    printf("Nome: %s e a idade: %d\n", p->nome, p->idade);
    
   
    return 0;
}
