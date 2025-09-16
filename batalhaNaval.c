#include <stdio.h>
#include <stdlib.h> // for abs()

#define TAM 10       // board size
#define TAM_NAVIO 3  // ship size
#define HSIZE 5      // ability matrix size
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// function to print board
void printBoard(int board[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// function to apply ability matrix on board
void applyAbility(int board[TAM][TAM], int ability[HSIZE][HSIZE], int originRow, int originCol) {
    int offset = HSIZE / 2; // center offset of ability matrix
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (ability[i][j] == 1) { // apply only marked positions
                int r = originRow + (i - offset);
                int c = originCol + (j - offset);
                if (r >= 0 && r < TAM && c >= 0 && c < TAM) {
                    if (board[r][c] == 0) { // don't overwrite ships
                        board[r][c] = 5; // mark affected area
                    }
                }
            }
        }
    }
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    int tabuleiro[TAM][TAM]; // board representation with a 10x10 matrix

    // initialize all cells with 0 (water)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0; // fill board with 0
        }
    }

    // place horizontal ship of size 3 starting at row 2, col 2
    for (int j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[2][2 + j] = 3; // mark ship cells with 3
    }

    // place vertical ship of size 3 starting at row 5, col 4
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[5 + i][4] = 3; // mark ship cells with 3
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // place diagonal ship (principal diagonal direction)
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[1 + k][1 + k] = 3;
    }

    // place diagonal ship (secondary diagonal direction)
    for (int k = 0; k < TAM_NAVIO; k++) {
        tabuleiro[7 - k][2 + k] = 3;
    }

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // build cone ability matrix
    int cone[HSIZE][HSIZE] = {0};
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (j >= HSIZE/2 - i && j <= HSIZE/2 + i) {
                cone[i][j] = 1; // cone expands downward
            }
        }
    }

    // build cross ability matrix
    int cross[HSIZE][HSIZE] = {0};
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (i == HSIZE/2 || j == HSIZE/2) {
                cross[i][j] = 1; // cross centered
            }
        }
    }

    // build octahedron (diamond) ability matrix
    int octa[HSIZE][HSIZE] = {0};
    for (int i = 0; i < HSIZE; i++) {
        for (int j = 0; j < HSIZE; j++) {
            if (abs(i - HSIZE/2) + abs(j - HSIZE/2) <= HSIZE/2) {
                octa[i][j] = 1; // diamond shape
            }
        }
    }

    // apply abilities at chosen origins
    applyAbility(tabuleiro, cone, 4, 4);
    applyAbility(tabuleiro, cross, 6, 6);
    applyAbility(tabuleiro, octa, 2, 7);

    // print final board
    printf("\nFinal Board with abilities:\n");
    printBoard(tabuleiro);

    return 0;
}
