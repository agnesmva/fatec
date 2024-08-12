#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int valorsorteado[6], valordigitado[6], i, j, acertos = 0;

    printf("Vamos conferir se você acertou a Mega-Sena? \nDigite uma sequência de 6 números separados por espaço: ");
    for (i = 0; i < 6; i++) {
        scanf("%d", &valordigitado[i]);
    }

    srand(time(NULL));
    for (i = 0; i < 6; i++) {
        valorsorteado[i] = rand() % 60 + 1;
    }

    bubbleSort(valordigitado, 6);
    bubbleSort(valorsorteado, 6);

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (valordigitado[i] == valorsorteado[j]) {
                acertos++;
                break; 
            }
        }
    }

    if (acertos < 4) {
        printf("Infelizmente não foi dessa vez! Você perdeu o jogo.\n");
    } else if (acertos == 4) {
        printf("Parabéns você acertou uma quadra.\n");
    } else if (acertos == 5) {
        printf("Parabéns você acertou uma quina.\n");
    } else if (acertos == 6) {
        printf("Parabéns você acertou todos os números. Você fez uma Mega-sena!!\n");
    }

    return 0;
}
