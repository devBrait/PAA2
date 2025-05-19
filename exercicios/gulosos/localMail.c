/*
    Exercício 2 - Semana 9 -> No correio local há somente selos de 3 e de 5 centavos. A taxa mínima para
    correspondência é de 8 centavos. Faça um programa que determina o menor
    número de selos de 3 e de 5 centavos que completam o valor de uma taxa dada.
*/

#include <stdio.h>

void findStamps(int tax) {
    int qtdStamps5 = tax / 5;
    int remaining;
    
    for (int i = 0; i < 3 && qtdStamps5 >= 0; i++) {
        remaining = tax - (qtdStamps5 * 5);
        
        if (remaining % 3 == 0) {
            int qtdStamps3 = remaining / 3;
            printf("%d selo(s) de 5 centavos e %d selo(s) de 3 centavos\n", qtdStamps5, qtdStamps3);
            return;
        }
        qtdStamps5--;
    }

    printf("Impossível encontrar uma solução para essa taxa.");
}

int main(){
    int tax = 11;
    findStamps(tax);

    return 0;
}