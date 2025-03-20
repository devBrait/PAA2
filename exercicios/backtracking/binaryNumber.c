/*
    Exercício 1 - Lista 01 - Backtracking ->
    Escreva uma função recursiva que apresente números binários de tamanho n.
    • Exemplo: n = 3
    Saída :
        000
        001
        010
        011
        100
        101
        110
        111
*/
#include <stdio.h>

void getBinaries(int binary[], int n, int pos) {

    if (pos == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", binary[i]);
        }
        printf("\n");
        return;
    }

    binary[pos] = 0;
    getBinaries(binary, n, pos + 1);

    binary[pos] = 1;
    getBinaries(binary, n, pos + 1);
}

int main() {
    int n = 3;

    int binary[n];
    getBinaries(binary, n, 0);

    return 0;
}
