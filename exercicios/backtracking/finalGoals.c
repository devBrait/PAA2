/*
    Exercício 2 - Lista 5.1 - Backtracking ->
    Considere uma partida de futebol entre duas equipes A × B, cujo placar final é m × n,
    em que m e n são número de gols marcados por A e B, respectivamente. Escreva um
    algoritmo recursivo que imprima todas as possíveis sucessões de gols marcados. Por
    exemplo, para um placar final de 3 × 1, as possíveis sucessões de gols são “AAAB”,
    “AABA”, “ABAA” e “BAAA”.
*/
#include <stdio.h>

void defineGoals(int m, int n, char *sequence, int pos){

    if (m == 0 && n == 0) {
        sequence[pos] = '\0';
        printf("%s\n", sequence);
        return;
    }

    if(m > 0){
        sequence[pos] = 'A';
        defineGoals(m - 1, n, sequence, pos + 1);
    }
    
    if(n > 0){
        sequence[pos] = 'B';
        defineGoals(m, n - 1, sequence, pos + 1);
    }
}

int main(){
    int m = 3;
    int n = 1;
    char sequence[m + n];

    defineGoals(m, n, sequence, 0);
}