/*Elbore um programa em C para criar a seguinte matriz 5x5
                            11111
                            12345
                            33333
                            12345
                            55555
*/
#include <stdio.h>

int main() {
    int A[5][5], i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 4) {
                A[i][j] = 5;
            }
            else if (i == 2) {
                A[i][j] = 3;
            }
            else if (i == 0){
                A[i][j] = 1;
            }
        
            else {
                A[i][j] = 1 + j;
            }
        }
    }

    printf("Essa é a matriz A:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
