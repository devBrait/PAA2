/*
    Problema da pirâmide
*/

#include <stdio.h>

#define SIZE 4

int max(int a, int b) {
    return a > b ? a : b;
}

void define(int P[SIZE][SIZE]){

    int S[SIZE][SIZE];

    for (int j = 0; j < SIZE; j++) {
        S[SIZE - 1][j] = P[SIZE - 1][j];
    }

    for (int i = SIZE - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            S[i][j] = max(S[i + 1][j], S[i + 1][j + 1]) + P[i][j];
        }
    }
    
    printf("Maior número de minerais: %d\n", S[0][0]);
    return;
}

int main() {
    int P[SIZE][SIZE] = {
        {3, 0, 0, 0},
        {7, 4, 0, 0},
        {2, 4, 6, 0},
        {8, 5, 9, 3}
    };

    define(P);

    return 0;
}
