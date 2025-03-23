/*
    Exercício Backtracking ->
    O Desafio das Torres Você é um programador que foi convidado a desenvolver um sistema de inteligência artificial para um jogo de tabuleiro de 
    estratégia que simula a batalha entre reis. Neste jogo, cada jogador deve posicionar até 8 torres em um tabuleiro de 8x8, onde as torres não podem se atacar. 
    As torres se atacam se estiverem na mesma linha ou na mesma coluna.

    Tarefa: Implemente uma função, utilizando backtracking em C, que encontra todas as formas possíveis de posicionar 8 torres no tabuleiro de forma que nenhuma torre 
    possa atacar outra. Esta função chamada void resolverTorres(int tabuleiro[8][8], int coluna) usa backtracking para posicionar as torres. A função resolverTorres deve 
    imprimir todas as soluções encontradas.
*/
#include <stdio.h>
#define SIZE 8

void back(int board[SIZE][SIZE], int column) {
    
    if (column == SIZE) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int row = 0; row < SIZE; row++) {
        int safe = 1;

        for (int i = 0; i < column; i++) {
            if (board[row][i] == 1) {
                safe = 0;
                break;
            }
        }

        if (safe) {
            board[row][column] = 1;
            back(board, column + 1);
            board[row][column] = 0;
        }
    }
}

int main() {
    int board[SIZE][SIZE] = {0};

    back(board, 0);
    return 0;
}