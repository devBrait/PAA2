/*
    Exercício 5 - Lista 5.3 - Backtracking ->
    SUBSET SUM - O PROBLEMA DO CHEQUES:
    Suponha que p1, p2, · · · , pn são os valores dos cheques que você emitiu durante o mês.
    No fim do mês, o banco debita uma quantia C na sua conta. Você quer saber se algum
    conjunto de cheques corresponde ao valor debitado. Considere que não temos cheques
    com valores repetidos. 
    Generalização do problema: Dado um conjunto de números naturais P = {p1, p2, · · · , pn} e C, decidir se existe um subconjunto X de {1, 2, · · · , n} tal que
    o somatório dos elementos P relacionados em X é igual a C.

    Exemplo1: P = {30, 40, 10, 15, 11, 60, 54} e C = 55, teríamos os subconjuntos
    • X = {2, 4} p2 = 40 p4 = 15
    • X = {1, 4, 5}, p1 = 30, p4 = 15, p5 = 10

    Exemplo sem Backtracking:

    void check(int p[], int c, int sizeP) {
        int x[sizeP];
        int pos;
        int temp;
        
        for(int i = 0; i < sizeP; i++) {
            temp = p[i];
            pos = 0;
            x[pos] = i + 1; 
            
            for(int j = 1; j < sizeP; j++) {
                if(temp + p[j] <= c) {
                    temp += p[j];
                    pos++;
                    x[pos] = j + 1; 
                    

                    if(temp == c) {
                        printf("{ ");
                        for(int k = 0; k <= pos; k++) {
                            printf("%d ", x[k]);
                        }
                        printf("}\n");
                        return;
                    }
                }
            }
        }
    }
*/
#include <stdio.h>

void check(int p[], int c, int sizeP, int pos, int result, int x[], int xPos) {
    
    if (result == c) {
        printf("{ ");
        for (int i = 0; i < xPos; i++) {
            printf("%d ", x[i]);
        }
        printf("}\n");
        return;
    }

    if (pos == sizeP || result > c) return; 

    x[xPos] = pos + 1;
    check(p, c, sizeP, pos + 1, result + p[pos], x, xPos + 1);

    check(p, c, sizeP, pos + 1, result, x, xPos);
}

int main() {
    int p[] = {30, 40, 10, 15, 11, 60, 54};
    int sizeP = sizeof(p) / sizeof(p[0]);
    int c = 55;
    int x[sizeP];

    check(p, c, sizeP, 0, 0, x, 0);
    return 0;
}
