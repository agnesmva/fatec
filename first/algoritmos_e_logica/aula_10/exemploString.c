#include <stdio.h>
#include <string.h>
int main()
{
    char capital[30] = "Paris", cidade[20];
    printf("Qual a capital da Franca?\n");
    fflush(stdin);
    gets(cidade);
    if (strcmp(capital, cidade) ==  0)
    {
        printf("Condragulations! Você acertou!\n");
    }
    else
        printf("Sashay Away! Infelizmente você errou, a capital da França é %s\n", capital);
    
    return 0;
}
// strupr() .touppercase
// strncat
//strcpy(nome, "Jose Luis")
//strcat(nome, sobrenome)// guarda em nome
//strncmp() = compara até onde as strings são iguais
//strrev() = inverte a string 