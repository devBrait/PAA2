/*
    Exercício 3 - Semana 12 ->
    (ARQUIVOS DIGITAIS) Temos n arquivos digitais em um computador, com cada arquivo i
    tendo tamanho ti megabytes. Desejamos copiar o maior número de arquivos do computador para um pendrive de capacidade c megabytes. 
    Formalmente, resolver este problema consiste em determinar o maior subconjunto X do intervalo discreto 1 . . n que satisfaça
    a restrição P i∈X ti ≤ c. 
    Escreva um algoritmo guloso que resolva este problema de maneira eficiente, determine a complexidade de tempo de execução.
*/

#include <stdio.h>

int filesMax(int files[], int size, int cap) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (files[i] > files[j]) {
                int temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    int used = 0;
    int quantFiles = 0;

    for (int i = 0; i < size; i++) {
        if (used + files[i] <= cap) {
            used += files[i];
            quantFiles++;
        }
    }

    return quantFiles;
}


int main() {
    int files[] = {50, 100, 30, 120, 10, 60};
    int size = sizeof(files) / sizeof(files[0]);
    int cap = 200;
    
    int result = filesMax(files, size, cap);
    printf("Valor total dos arquivos na mochila: %d\n", result);
    
    return 0;
}