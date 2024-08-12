#include <stdio.h>

// Função para criar e verificar o quadrado mágico
void quadradoMagico(int N) {
    int quadrado[N][N];
    int i, j;
    int soma_esperada = N * (N * N + 1) / 2; // Valor esperado para todas as linhas, colunas e diagonais

    // Inicializa o quadrado com zeros
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            quadrado[i][j] = 0;
        }
    }

    // Posicionamento dos números no quadrado mágico
    int num = 1;
    int row = 0;
    int col = N / 2;
    int next_row, next_col;
    while (num <= N * N) {
        quadrado[row][col] = num;
        num++;
        next_row = (row - 1 + N) % N;
        next_col = (col + 1) % N;
        if (quadrado[next_row][next_col] != 0) {
            row = (row + 1) % N;
        } else {
            row = next_row;
            col = next_col;
        }
    }

    // Verificação se é um quadrado mágico
    int soma_diag1 = 0, soma_diag2 = 0;
    for (i = 0; i < N; i++) {
        int soma_linha = 0, soma_coluna = 0;
        for (j = 0; j < N; j++) {
            soma_linha += quadrado[i][j];
            soma_coluna += quadrado[j][i];
        }
        soma_diag1 += quadrado[i][i];
        soma_diag2 += quadrado[i][N - 1 - i];

        // Verifica se a soma da linha é igual à soma esperada
        if (soma_linha != soma_esperada) {
            printf("Não é um quadrado mágico!\n");
            return;
        }

        // Verifica se a soma da coluna é igual à soma esperada
        if (soma_coluna != soma_esperada) {
            printf("Não é um quadrado mágico!\n");
            return;
        }
    }

    // Verifica se as diagonais têm a soma esperada
    if (soma_diag1 != soma_esperada || soma_diag2 != soma_esperada) {
        printf("Não é um quadrado mágico!\n");
        return;
    }

    // Se passou por todas as verificações, é um quadrado mágico
    printf("É um quadrado mágico!\n");
    printf("Soma esperada para cada linha, coluna e diagonal: %d\n", soma_esperada);

    // Imprime o quadrado mágico
    printf("Quadrado mágico:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", quadrado[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;

    // Solicita ao usuário o valor do lado do quadrado (ordem N)
    printf("Digite o valor do lado do quadrado: ");
    scanf("%d", &N);

    // Verifica se N é maior que 2
    if (N <= 2) {
        printf("O valor de N precisa ser maior que 2.\n");
        return 1;
    }

    // Chama a função para criar e verificar o quadrado mágico
    quadradoMagico(N);

    return 0;
}
