/*
    Exercício 9 Enumeração ->
    Dados dois números naturais m e n e duas sequências ordenadas sem números
    repetidos com m e n números inteiros, obter uma única sequência ordenada
    contendo todos os elementos das sequências originais.
*/
#include <stdio.h>

void sortSequence(int seqM[], int seqN[], int m, int n) {
    int merged[m + n];
    int i = 0, j = 0, k = 0;
    int sizeMerge = sizeof(merged) / sizeof(merged[0]);
    
    for (k = 0; k < sizeMerge && i < m && j < n; k++) {
        if (seqM[i] <= seqN[j]) {
            merged[k] = seqM[i++];
        } else {
            merged[k] = seqN[j++];
        }
    }
    
    // ; inicia o valor já definido de i ou j abaixo
    for (; i < m; i++, k++) {
        merged[k] = seqM[i];
    }

    for (; j < n; j++, k++) {
        merged[k] = seqN[j];
    }
    
    for (int p = 0; p < sizeMerge; p++) {
        if(p < sizeMerge - 1){ 
            printf("%d, ", merged[p]);
        }else{
            printf("%d", merged[p]);
        } 
    }
    printf("\n");
}

int main(){
    int seqM[] = {1, 3, 5};
    int seqN[] = {2, 4, 6, 8};

    int m = sizeof(seqM) / sizeof(seqM[0]);
    int n = sizeof(seqN) / sizeof(seqN[0]);

    sortSequence(seqM, seqN, m, n);
}