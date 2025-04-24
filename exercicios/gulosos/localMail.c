#include <stdio.h>

void findStamps(int tax) {
    int qtdStamps5, qtdStamps3;
    int find = 0;

    for (qtdStamps5 = tax / 5; qtdStamps5 >= 0; qtdStamps5--) {
        int remaining = tax - (qtdStamps5 * 5);

        if (remaining % 3 == 0) {
            qtdStamps3 = remaining / 3;
            find = 1;
            printf("%d selo(s) de 5 centavos e %d selo(s) de 3 centavos\n", qtdStamps5, qtdStamps3);
            return;
        }
    }

    if (!find)
        printf("Impossível encontrar uma solução para essa taxa.");
}

int main(){
    int tax = 11;
    findStamps(11);

    return 0;
}