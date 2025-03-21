/*
    Exercício 2 - Lista 5.1 - Backtracking ->
    (DESAFIO) Escreva um programa em linguagem C, que resolva o sudoku simples. Suponha que a tabela do sudoku já tenha algumas posições preenchidas.
    Sudoku 4x4
*/
#include <stdio.h>

int solveSudoku(int grid[4][4]) {
    int row, col, num, i, j, startRow, startCol, found = 0;

    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            if (grid[row][col] == 0) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (!found) return 1;

    for (num = 1; num <= 4; num++) {
        int isValid = 1;

        for (i = 0; i < 4; i++) {
            if (grid[row][i] == num || grid[i][col] == num) {
                isValid = 0;
                break;
            }
        }

        startRow = (row / 2) * 2;
        startCol = (col / 2) * 2;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                if (grid[startRow + i][startCol + j] == num) {
                    isValid = 0;
                    break;
                }
            }
            if (!isValid) break;
        }

        if (isValid) {
            grid[row][col] = num;

            if (solveSudoku(grid)) return 1;

            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[4][4] = {
        {0, 2, 4, 0},
        {1, 0, 0, 3},
        {4, 0, 0, 2},
        {0, 1, 3, 0}
    };

    if (solveSudoku(grid)) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
