/*
    Exercício 8 Enumeração ->
    Dada uma sequência de números inteiros com n elementos, escreva uma função
    na linguagem C determinar um segmento de soma máxima.
    Exemplo: Na sequência 5 2 -2 -7 3 14 10 -3 9 -6 4 1, a soma do
    segmento é 33.

    Solução O(n):
    void defineSegSumMax(int s[], int sizeS){
    int temp = s[0];
    int greater = s[0];

    for(int i = 1; i < sizeS; i++){
        if(s[i] < temp + s[i]){
            temp += s[i];
        }else{
            temp = s[i];
        }

        if(temp > greater){
            greater = temp;
        }
    }

    printf("%d\n", greater);
}


*/
#include <stdio.h>

void defineSegSumMax(int s[], int sizeS){
    int temp, greater;
    greater = s[0];

    for(int i = 0; i < sizeS; i++){
        temp = 0;
        for(int j = i; j < sizeS; j++){
            temp += s[j];
            if(temp > greater){
                greater = temp;
            }
        }
    }

    printf("%d\n", greater);
}


int main(){

    int s[] = {5, 2, -2, -7, 3, 14, 10, -3, 9, -6, 4, 1};
    int sizeS = sizeof(s) / sizeof(s[0]);

    defineSegSumMax(s, sizeS);
}