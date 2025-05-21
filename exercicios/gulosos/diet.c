/*
    Exercício 6 - Semana 12 -> (DIETA) Deseja-se calcular uma dieta com no máximo K calorias. Tem-se n potes, cada
    uma com um alimento diferente. Cada pote i tem c[i] calorias e p[i] proteínas. Desejase maximizar a quantidade de proteínas sem ultrapassar o limite de calorias. Escreva
    um algoritmo que leia o valor de K e o valor de calorias e proteínas para n alimentos
    diferentes e apresente o quanto desses alimentos estão presentes na dieta.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int calories;
    int protein;
    double proteinPerCalorie;
} Food;

void fillDefaultFoods(Food foods[], int *n) {
    *n = 7;
    
    int calories[] = {200, 70, 150, 130, 120, 250, 100};
    int proteins[] = {50, 6, 8, 2, 9, 30, 7};
    
    for (int i = 0; i < *n; i++) {
        foods[i].calories = calories[i];
        foods[i].protein = proteins[i];
        foods[i].proteinPerCalorie = (double)proteins[i] / calories[i];
    }
}

int compare(const void *a, const void *b) {
    Food *foodA = (Food *)a;
    Food *foodB = (Food *)b;
    if (foodB->proteinPerCalorie > foodA->proteinPerCalorie) return 1;
    if (foodB->proteinPerCalorie < foodA->proteinPerCalorie) return -1;
    return 0;
}

void sortFoods(Food foods[], int n) {
    qsort(foods, n, sizeof(Food), compare);
}

double computeDiet(Food foods[], int n, double maxCalories) {
    double totalProtein = 0.0;
    double remainingCalories = maxCalories;

    for (int i = 0; i < n; i++) {
        if (remainingCalories == 0) {
            break;
        }

        if (foods[i].calories <= remainingCalories) {
            remainingCalories -= foods[i].calories;
            totalProtein += foods[i].protein;
            printf("%d calorias, %d proteína\n", foods[i].calories, foods[i].protein);
        } else {
            double fraction = remainingCalories / foods[i].calories;
            totalProtein += foods[i].protein * fraction;
            printf("%d calorias, %d proteína\n", foods[i].calories, foods[i].protein);
            remainingCalories = 0;
        }
    }

    return totalProtein;
}

int main() {
    int n;
    double maxCalories;

    maxCalories = 500;
    Food foods[10];
    fillDefaultFoods(foods, &n);

    sortFoods(foods, n);
    double totalProtein = computeDiet(foods, n, maxCalories);

    printf("\nTotal proteína na dieta = %.2lf\n", totalProtein);

    return 0;
}
