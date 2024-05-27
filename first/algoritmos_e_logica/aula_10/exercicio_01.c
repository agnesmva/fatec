#include <stdio.h>
#include <string.h>

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