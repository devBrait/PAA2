/*
    Exercício BackTracking ->
    Organização de Equipes em Torneio Utilizando Permutação

    Você é um programador encarregado de organizar as equipes em um torneio de programação. Para modelar o sistema de sorteio aleatório, você decidiu que a ordem em que os 
    competidores se apresentam deve variar a cada rodada do torneio. Sua tarefa é desenvolver um programa que gere todas as permutações possíveis em que os competidores podem
     ser organizados, com base nos seus números de inscrição. Você decidiu utilizar a técnica de backtracking para resolver esse problema.

    Especificação do Problema: Dado um conjunto de 
    𝑛
    competidores representados por seus números de inscrição (inteiros distintos), implemente um algoritmo que gere todas as permutações possíveis desses números 
    utilizando backtracking.

    Entrada: 1, 2, 3

    Saída:
    1, 2, 3
    1, 3, 2
    2, 1, 3
    2, 3, 1
    3, 1, 2
    3, 2, 1
*/

#include <stdio.h>

void defineNumbers(int n[], int sizeN, int pos){

    if (pos == sizeN - 1) {
        for (int i = 0; i < sizeN; i++) {
            printf("%d ", n[i]);
        }
        printf("\n");
        return;
    }

    for (int j = pos; j < sizeN; j++) {

        int temp = n[pos];
        n[pos] = n[j];
        n[j] = temp;

        defineNumbers(n, sizeN, pos + 1);
        
        temp = n[pos];
        n[pos] = n[j];
        n[j] = temp;
    }
}


int main(){
    int n[] = {1, 2, 3};
    int sizeN = sizeof(n) / sizeof(n[0]);

    defineNumbers(n, sizeN, 0);

    return 0;
}