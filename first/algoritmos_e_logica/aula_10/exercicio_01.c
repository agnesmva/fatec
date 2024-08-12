#include <stdio.h>
#include <string.h>
int main()
{
    char palavra[30];
    printf("Hey boy, look. Imma doing this for you...\n You have y two choices\n Digite a palavra e vamos verificar se ela é um palindromo:\n");
    fflush(stdin);
    scanf("%s", palavra);
    if (strcmp(strrev(palavra), palavra) == 0)
    {
        printf("Uhuuuul\n A palavra %s é um palindromo", palavra);
    }
    else
    {
        printf("Unfortunaly You Need to try again. A palavra não é um palindromo");
    }
    
    return 0;
}
