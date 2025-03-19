/*
    Exercício 7 Enumeração ->
    Dada a sequência a[1..n] de números inteiros, escreva um programa na
    linguagem C que verifica se existem dois segmentos consecutivos iguais na
    sequência, isto é, se existem i e m tais que:
    a[i] a[i+1] ... a[i+m-1] = a[i+m] a[i+m+1] ... a[i+2m-1]
    Imprima, caso existam, os valores de i e m.
    Exemplo: Na sequência 7 9 5 4 5 4 8 6 
    Existem i=3 e m=2
*/
#include <stdio.h>

void defineEqualSegments(int s[], int sizeS) {

    for (int m = 1; m <= sizeS / 2; m++) {
        for (int i = 0; i + m < sizeS; i++) {
            int isEqual = 1;
            int pos1 = i;
            int pos2 = i + m;

            for (int k = 0; k < m; k++) {
                if (s[pos1] != s[pos2]) {
                    isEqual = 0;
                    break;
                }
                pos1++;
                pos2++;
            }

            if (isEqual) {
                printf("i = %d e m = %d\n", i+1, m);
                return;
            }
        }
    }

    printf("No value defined.\n");
}

int main(){

    int s[] = {7, 9, 5, 4, 5, 4, 8, 6};
    int sizeS = sizeof(s) / sizeof(s[0]);

    defineEqualSegments(s, sizeS);

    return 0;
}