/*
    Escreva um algoritmo utilizando a estratégia Backtracking que ordena um vetor de N
    elementos inteiros. (Um tanto ridículo, mas pode ser um bom exercício). O seu algoritmo
    funciona para números repetidos ?
*/

#include <stdio.h>

int check(int n[], int sizeN) {
    for (int i = 1; i < sizeN; i++) {
        if (n[i-1] > n[i]) {
            return 0; 
        }
    }
    return 1;
}

int find = 0;

void sort(int n[], int sizeN, int pos) {

    if(find) return;

    if (check(n, sizeN)) {
        for (int i = 0; i < sizeN; i++) {
            printf("%d ", n[i]);
        }
        printf("\n");
        find = 1;
        return;
    }

    if(pos >= sizeN) return;

    for (int i = pos; i < sizeN; i++) {
        int temp = n[pos];
        n[pos] = n[i];
        n[i] = temp;

        sort(n, sizeN, pos + 1);

        temp = n[pos];
        n[pos] = n[i];
        n[i] = temp;
    }
}

int main() {
    int n[] = {4, 3, 2, 1, 1};
    int sizeN = sizeof(n) / sizeof(n[0]);
    
    sort(n, sizeN, 0);

    return 0;
}
