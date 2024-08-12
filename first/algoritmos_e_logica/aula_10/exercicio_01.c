#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
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
=======

int main(){
 char palavra[20], palavraCopia[20];
 
 printf("\nVERIFICADOR DE PALINDROMOS\nDigite uma palavra!\n");
 fflush(stdin);
 gets(palavra);
 strcpy(palavraCopia, palavra);
 
 if (strcmp(strupr(palavra), strupr(strrev(palavraCopia)))==0){
  printf("\nA palavra %s e um palindromo.", palavra);
 }
 else{
  printf("\nA palavra %s nao e um palindromo.", palavra);
 }
 
 return 0;
}
>>>>>>> 4a4378f8a724c2b7715d9ff9fbd0f396ab269540
