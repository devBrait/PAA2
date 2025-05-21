/*
    Exercício 12 - Semana 12 -> (PROBLEMA DA MOCHILA 0/1) Dado um conjunto S de itens s1, s2, · · · , sn, onde cada item si possui um valor vi e peso wi, 
    para todo 1 ≤ i ≤ n, e uma capacidade W da mochila. Determine o valor máximo de itens que se pode colocar dentro da mochila sem exceder a capacidade W. 
    Não é permitido fracionar os itens. Escreva uma versão recursiva (backtracking), versão de programação dinâmica (top-down) e uma versão bottom-up.
*/
#include <stdio.h>
#include <stdlib.h>

int defineBackpack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w) {
                dp[i][w] = (dp[i - 1][w] > (dp[i - 1][w - weights[i - 1]] + values[i - 1]))? dp[i - 1][w]: (dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d (Peso %d, Valor %d)\n", i, weights[i - 1], values[i - 1]);
            w -= weights[i - 1];
        }
    }

    return dp[n][capacity]; 
}

int main() {
    int n = 5;
    int capacity = 50;
    int weights[] = {40, 30, 20, 10, 20};
    int values[] = {840, 600, 400, 100, 30};

    int maxValue = defineBackpack(weights, values, n, capacity);

    printf("\nValor máximo na mochila = %d\n", maxValue);

    return 0;
}
