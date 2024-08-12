#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    char sigla[100];
    int i, j = 0;

    printf("Digite a frase: ");
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