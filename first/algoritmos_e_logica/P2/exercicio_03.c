/*Elabore um programa em C que dada uma frase de no máximo 100 caracteres, crie uma sigla, formada pela primeira letra de cada palavra desta frase. Obs Não existem espaços em branco no início da frase, ou seja, a primeira letra da frase é a primeira letra da sigla.
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0, j = 0;
    char frase[100], sigla[100];
    printf("Esse é o nosso gerador de siglas automáticas. Digite uma frase que mostraremos a sigla: ");
    fgets(frase, 100, stdin);

    
    sigla[j++] = frase[0];

    
    for(i = 0; i < strlen(frase); i++) {
        if(frase[i] == ' ') {
            sigla[j++] = frase[i+1];
        }
    }

    sigla[j] = '\0';

    printf("A sigla é: %s\n", sigla);

    return 0;
}


