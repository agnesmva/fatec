/*Elabore um programa em C que leia/gere um vetor contendo 20 elementos inteiros. Cada elemento é toral de pontos que alunos obtiveram em uma prova do tipo teste, velendo no máximo 100 pontos. Mostre quais foram as duas menores notas.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int prova[20], i, a = 100, b = 100;
    srand(time(NULL));
    printf("Aqui estão as notas dos seus alunos: \n");
    for (i = 0; i < 20; i++) {
        prova[i] = rand() % 100;
        printf("%d ", prova[i]);
    }

    for (i = 0; i < 20; i++) {
        if (prova[i] < a) {
            b = a;
            a = prova[i];
        } else if (prova[i] < b) {
            b = prova[i];
        }
    }
    printf("\nAs duas menores notas dessa turma são: %d e %d\n", a, b);

    return 0;
}
