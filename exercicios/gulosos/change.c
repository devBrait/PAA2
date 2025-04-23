#include <stdio.h>

void define(int *values, int size, int *value_cents, const char *type) {
    for (int i = 0; i < size; i++) {
        int qtd = *value_cents / values[i];
        printf("%d %s(s) de R$ %.2f\n", qtd, type, values[i] / 100.0);
        *value_cents %= values[i];
    }
}

int main() {
    double value;
    int value_cents;

    int notes[] = {10000, 5000, 2000, 1000, 500, 200};
    int coins[] = {100, 50, 25, 10, 5, 1};

    scanf("%lf", &value);

    value_cents = (int)(value * 100 + 0.5);

    printf("NOTAS:\n");
    define(notes, 6, &value_cents, "nota");

    printf("MOEDAS:\n");
    define(coins, 6, &value_cents, "moeda");

    return 0;
}
