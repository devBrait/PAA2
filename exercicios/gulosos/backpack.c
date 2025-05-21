/*
    Exercício 5 - Semana 12 -> (PROBLEMA DA MOCHILA) Imagine um conjunto de objetos que eu gostaria de colocar
    na minha mochila. Cada objeto tem um certo peso e um certo valor. Posso escolher uma
    fração - entre 0% e 100% - de cada objeto para colocar na mochila.
    Exemplo: Considere a instância do problema da mochila fracionária que tem n = 5 objetos, capacidade c = 50, e os pesos e valores dados a seguir.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double valuePerWeight;
} Item;

void fillItems(Item items[], int weights[], int values[], int n) {
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].valuePerWeight = (double)values[i] / weights[i];
    }
}

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->valuePerWeight > itemA->valuePerWeight) return 1;
    if (itemB->valuePerWeight < itemA->valuePerWeight) return -1;
    return 0;
}

void sortItems(Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);
}

double fractionalBackpack(Item items[], int n, double capacity) {
    double totalValue = 0.0;
    double remainingCapacity = capacity;

    printf("Itens selecionados:\n");

    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0) {
            break;
        }

        if (items[i].weight <= remainingCapacity) {
            remainingCapacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item com peso %d e valor %d\n", items[i].weight, items[i].value);
        } else {
            double fraction = remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Item com peso %d e valor %d\n", items[i].weight, items[i].value);
            remainingCapacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int n = 5;
    double capacity = 50;

    int weights[] = {40, 30, 20, 10, 20};
    int values[] = {840, 600, 400, 100, 30};

    Item items[n];

    fillItems(items, weights, values, n);
    sortItems(items, n);
    double totalValue = fractionalBackpack(items, n, capacity);

    printf("\nTotal na mochila = %.2lf\n", totalValue);

    return 0;
}

