/*

    Exercício 15 - Semana 12 -> (CORTE DAS HASTES DE AÇO) Dada uma haste de tamanho n e uma tabela de preços pi
    para i = 1, 2, · · · , n, escreva um algoritmo que determine a receita máxima rn obtida pelo
    corte de uma haste de aço e pela subsequente venda de suas partes. Escreva uma versão recursiva (backtracking), 
    versão de programação dinâmica (top-down) e uma versão bottom-up.
*/

#include <stdio.h>

int cutRod(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int maxVal = -1;
        for (int j = 1; j <= i; j++) {
            if (price[j - 1] + dp[i - j] > maxVal)
                maxVal = price[j - 1] + dp[i - j];
        }
        dp[i] = maxVal;
    }

    return dp[n];
}

int main() {
    int price[] = {2, 5, 7, 3, 9};
    int size = sizeof(price) / sizeof(price[0]);

    printf("Receita máxima: %d\n", cutRod(price, size));

    return 0;
}