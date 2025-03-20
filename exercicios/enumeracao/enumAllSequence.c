/*
    Desafio Enumeração ->
    Suponha o seguinte problema:
    Enumerar todas as sequências possíveis de 3 dígitos, por exemplo se tivermos
    os dígitos 1, 2 e 3 teríamos como resultado:
    1 1 1, 1 1 2, 1 1 3, 1 2 1, 1 2 2, 1 2 3, 1 3 1, 1 3 2, 1 3 3,
    2 1 1, 2 1 2, 2 1 3, 2 2 1, 2 2 2, 2 2 3, 2 3 1, 2 3 2, 2 3 3,
    3 1 1, 3 1 2, 3 1 3, 3 2 1, 3 2 2, 3 2 3, 3 3 1, 3 3 2, 3 3 3
    Nesse caso teremos 27 sequências.
*/

#include <stdio.h>

void back(int sequence[], int s[], int pos, int sizeS) {

    if (pos == sizeS) {
        for (int i = 0; i < sizeS; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
        return;
    }
    
    for (int j = 0; j < sizeS; j++) {
        sequence[pos] = s[j];
        back(sequence, s, pos + 1, sizeS);
    }
}

int main() {
    int s[] = {1, 2, 3};
    int sequence[3];   
    int sizeS = sizeof(s) / sizeof(s[0]);
    
    back(sequence, s, 0, sizeS);
    
    return 0;
}