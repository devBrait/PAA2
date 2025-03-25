/*
    Exercício Backtracking ->
    Faça uma função para cálculo do mdc entre dois números.
    (a) Escreva uma função recusiva para computar o mdc(x, y).
    (b) Verifique suas funções para as seguintes entradas:
        mdc(270,192) = 6
        mdc(35,10) = 5
        mdc(10,15) = 5
        mdc(31,2) = 1
*/
#include <stdio.h>

void defineMdc(int x, int y, int div){

    if(div == 0) {
        printf("1");
        return;
    }

    if(x % div == 0 && y % div == 0) {
        printf("%d\n", div);
        return;
    }

    defineMdc(x, y, div - 1);
}


int main(){

    int x = 35;
    int y = 10;
    int div = x < y ? x : y;

    defineMdc(x, y, div);

    return 0;
}