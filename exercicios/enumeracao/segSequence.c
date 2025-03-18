/*
    Exercício 4 Enumeração ->
    Escreva uma função booleana na linguagem C que receba duas sequências e
    decida se a sequência s[i..k] é um segmento da sequência a[1..n]
*/
#include <stdio.h>

void decideSegSequence(int a[], int s[], int sizeA, int sizeS){

    int total = 0;
    int index = 0;

    if(sizeS > sizeA) return;

    for(int i = 0; i < sizeA; i++)
    {
        if(total > sizeS) break;

        if(a[i] == s[total])
        {
            total++;
            index = i;
            for(int j = 1; j < sizeS - 1; j++)
            {
                index++;
                if(s[j] == a[index] && total < sizeS)
                    total++;
            }
        }
    }

    if(total == sizeS)
        printf("Sequence S is a segment of sequence A.\n");
    else 
        printf("Not a segment.\n");
}

int main(){

    int a[] = {3, 8, 12, 5, 7, 9, 14};
    int s[] = {5, 7, 9};

    int sizeA = sizeof(a) / sizeof(a[0]);
    int sizeS = sizeof(s) / sizeof(s[0]);

    decideSegSequence(a, s, sizeA, sizeS);

    return 0;
}