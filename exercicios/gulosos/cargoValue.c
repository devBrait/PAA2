/*
    Problema de Transporte de carga
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double valuePerWeight;
} Item;

int compareItems(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;

    if (itemB->valuePerWeight > itemA->valuePerWeight) return 1;
    if (itemB->valuePerWeight < itemA->valuePerWeight) return -1;
    return 0;
}

double calculateTransport(Item items[], int itemCount, int capacity) {
    for (int i = 0; i < itemCount; i++) {
        items[i].valuePerWeight = (double)items[i].value / items[i].weight;
    }

    qsort(items, itemCount, sizeof(Item), compareItems);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // <-- IMPORTANT
    for (int i = 0; i < itemCount && remainingCapacity > 0; i++) {
        if (items[i].weight <= remainingCapacity) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            totalValue += items[i].valuePerWeight * remainingCapacity;
            remainingCapacity = 0;
        }
    }
    // --->

    return totalValue;
}

int main() {
    int capacity = 50;

    Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int itemCount = sizeof(items) / sizeof(items[0]);

    double result = calculateTransport(items, itemCount, capacity);

    printf("Valor total transportado: %.2lf\n", result);

    return 0;
}
