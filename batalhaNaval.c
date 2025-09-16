#include <stdio.h>

#define TAM 10       // board size
#define TAM_NAVIO 3  // ship size
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[TAM][TAM]; // board representation with a 10x10 matrix
    int valid = 1; // control variable to check if placement is valid

    // initialize all cells with 0 (water)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // fill board with 0
        }
    }

    // place horizontal ship of size 3 starting at row 2, col 2
    valid = 1;
    for (int j = 0; j < TAM_NAVIO; j++) {
        if (tabuleiro[2][2 + j] != 0) valid = 0; // check overlap
    }
    if (valid) {
        for (int j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[2][2 + j] = 3; // mark ship cells with 3
            printf("Horizontal ship part at: (%d, %d)\n", 2, 2 + j);
        }
    } else {
        printf("Error: horizontal ship cannot be placed (overlap detected).\n");
    }

    // place vertical ship of size 3 starting at row 5, col 4
    valid = 1;
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[5 + i][4] != 0) valid = 0; // check overlap
    }
    if (valid) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[5 + i][4] = 3;
            printf("Vertical ship part at: (%d, %d)\n", 5 + i, 4);
        }
    } else {
        printf("Error: vertical ship cannot be placed (overlap detected).\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // place diagonal ship (principal diagonal direction)
    valid = 1;
    for (int k = 0; k < TAM_NAVIO; k++) {
        if (tabuleiro[1 + k][1 + k] != 0) valid = 0;
    }
    if (valid) {
        for (int k = 0; k < TAM_NAVIO; k++) {
            tabuleiro[1 + k][1 + k] = 3;
            printf("Diagonal (main) ship part at: (%d, %d)\n", 1 + k, 1 + k);
        }
    } else {
        printf("Error: main diagonal ship cannot be placed (overlap detected).\n");
    }

    // place diagonal ship (secondary diagonal direction)
    valid = 1;
    for (int k = 0; k < TAM_NAVIO; k++) {
        if (tabuleiro[7 - k][2 + k] != 0) valid = 0;
    }
    if (valid) {
        for (int k = 0; k < TAM_NAVIO; k++) {
            tabuleiro[7 - k][2 + k] = 3;
            printf("Diagonal (secondary) ship part at: (%d, %d)\n", 7 - k, 2 + k);
        }
    } else {
        printf("Error: secondary diagonal ship cannot be placed (overlap detected).\n");
    }

    // print final board state
    printf("\nFinal Board:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]); // print each cell
        }
        printf("\n");
    }

    return 0;
}

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
