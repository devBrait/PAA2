/*
    Exercício 1 - Semana 12 -> Leia um valor de ponto flutuante com duas casas decimais. Este valor representa
    um valor monetário. A seguir, calcule o menor número de notas e moedas
    possíveis no qual o valor pode ser decomposto. As notas consideradas são de
    100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10,
    0.05 e 0.01. O seu programa deve a relação de notas necessárias, por
    exemplo para o valor 576.73 teríamos:
    NOTAS:                         
    5 nota(s) de R$ 100.00
    1 nota(s) de R$ 50.00
    1 nota(s) de R$ 20.00
    0 nota(s) de R$ 10.00
    1 nota(s) de R$ 5.00
    0 nota(s) de R$ 2.00
    
    MOEDAS:
    1 moeda(s) de R$ 1.00
    1 moeda(s) de R$ 0.50
    0 moeda(s) de R$ 0.25
    2 moeda(s) de R$ 0.10
    0 moeda(s) de R$ 0.05
    3 moeda(s) de R$ 0.01
*/

#include <stdio.h>

#define MAX 1000000
#define INF 1000000

void defineChange(double value) {

    int values[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    int size = 12;
    int cents = (int)(value * 100 + 0.5);

    int dp[MAX];   
    int last[MAX];

    for (int i = 1; i <= cents; i++) {
        dp[i] = INF;
        for (int j = 0; j < size; j++) {
            if (values[j] <= i && dp[i - values[j]] + 1 < dp[i]) {
                dp[i] = dp[i - values[j]] + 1;
                last[i] = j;
            }
        }
    }

    int qtd[12] = {0};
    int current = cents;

    while (current > 0) {
        int lastUsed = last[current];
        qtd[lastUsed]++;
        current -= values[lastUsed];
    }

    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2f\n", qtd[i], values[i] / 100.0);
    }

    printf("MOEDAS:\n");
    for (int i = 6; i < 12; i++) {
        printf("%d moeda(s) de R$ %.2f\n", qtd[i], values[i] / 100.0);
    }
}

int main() {
    double value = 576.73;
    defineChange(value);

    return 0;
}

