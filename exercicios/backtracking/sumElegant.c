/*
    Exercício Backtracking ->
    São disponibilizados a você̂ n inteiros A1A2A3 · · · An. Encontre uma permutação destes n
    inteiros de forma que a soma da diferença absoluta entre os elementos adjacentes seja
    maximizada.
    Supondo n = 4 e que os inteiros fornecidos sejam 4 2 1 5. A permutação 2 5 1 4 permite a
    máxima soma. Para esta permutação, teríamos soma = abs(2-5) + abs(5-1) + abs(1-4) = 3+4+3 = 10. 
    De todas as 24 permutações possíveis, você̂ não vai obter qualquer soma cujo valor
    exceda 10. Nós iremos chamar este valor 10, de soma permutada elegante.
    Escreva uma função, usando Backtracking, que dado n inteiros encontre o valor da permutada
    elegante.
*/

#include <stdio.h>
#include <stdlib.h>

int back(int s[], int sizeS, int pos) {

    if (pos == sizeS - 1) {
        int sum = 0;
        for (int i = 1; i < sizeS; i++) {
            sum += abs(s[i - 1] - s[i]);
        }
        return sum;
    }

    int maxSum = 0;
    for (int j = pos; j < sizeS; j++) {
        int temp = s[pos];
        s[pos] = s[j];
        s[j] = temp;

        int currentSum = back(s, sizeS, pos + 1);

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }

        temp = s[pos];
        s[pos] = s[j];
        s[j] = temp;
    }
    return maxSum;
}



int main(){

    int s[] = {4, 2, 1, 5};
    int sizeS = sizeof(s) / sizeof(s[0]);

    int max = back(s, sizeS, 0);

    printf("%d\n", max);

    return 0;
}