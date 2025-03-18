/*
    Exercício 6 ->
    Dada uma sequência de números inteiros com n elementos, faça uma função na
    linguagem C para determinar o comprimento de um segmento crescente de tamanho máximo.
    Exemplos:
    Na sequência 5 10 3 2 4 7 9 8 5 o comprimento do segmento crescente
    máximo é 4 (2, 4, 7, 9).
    Na sequência 10 8 7 5 2 o comprimento do segmento crescente máximo é 1.
*/
#include <stdio.h>

void decideSegCrescent(int s[], int sizeS){

    int greater = 0;
    int temp = 0;

    for(int i = 1; i < sizeS; i++){
        if(s[i - 1] < s[i]){
            temp++;
        }else{
            temp = 1;
        }

        if(temp > greater){
            greater = temp;
        }
    }

    printf("Max value: %d\n", greater);
}

int main(){
    int s[] = {5, 10, 3, 2, 4, 7, 9, 8, 5};

    int sizeS = sizeof(s) / sizeof(s[0]);

    decideSegCrescent(s, sizeS);

    return 0;
}