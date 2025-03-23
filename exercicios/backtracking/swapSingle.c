/*
    Exercício Backtracking ->
    Geração de Combinações com Trocas Adjacentes
    Dado um array de números distintos, gere todas as possíveis combinações resultantes trocando apenas um elemento de posição por vez. 
    Utilize um algoritmo de backtracking para explorar todas as configurações válidas, garantindo que cada estado seja restaurado antes 
    de tentar novas trocas.

    Exemplo de entrada: 
    {1, 2, 3}

    Exemplo de saída:
    1 2 3
    2 1 3
    2 3 1
*/

#include <stdio.h>

void back(int n[], int sizeN, int pos) {
    for (int i = 0; i < sizeN; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");

    if (pos < sizeN - 1) {
        int temp = n[pos];
        n[pos] = n[pos + 1];
        n[pos + 1] = temp;

        back(n, sizeN, pos + 1);

        temp = n[pos];
        n[pos] = n[pos + 1];
        n[pos + 1] = temp;
    }
}

int main() {
    int n[] = {1, 2, 3};
    int size = sizeof(n) / sizeof(n[0]);

    back(n, size, 0);

    return 0;
}
