/*
    1) Leia um valor de ponto flutuante com duas casas decimais. Este valor representa
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

void define(float value) {
    int notes[] = {10000, 5000, 2000, 1000, 500, 200};
    int coins[] = {100, 50, 25, 10, 5, 1};
    int cents = (int)(value * 100 + 0.5);

    int size = sizeof(notes) / sizeof(notes[0]);

    printf("NOTAS:\n");
    for (int i = 0; i < size; i++) {
        int qtd = cents / notes[i];
        cents %= notes[i];
        printf("%d nota(s) de R$ %.2f\n", qtd, notes[i] / 100.0);
    }

    printf("MOEDAS:\n");
    for (int i = 0; i < size; i++) {
        int qtd = cents / coins[i];
        cents %= coins[i];
        printf("%d moeda(s) de R$ %.2f\n", qtd, coins[i] / 100.0);
    }
}

int main() {
    float value = 576.73;
    define(value);

    return 0;
}
