/*
    Exercício Backtracking -> 
    Desenvolvendo um Algoritmo Eficiente para Processamento de Dados em Grande Escala
    Imagine que você faz parte da equipe de desenvolvimento de uma startup que está criando uma aplicação para analisar grandes quantidades de dados coletados em tempo 
    real de sensores. Uma das tarefas mais frequentes no processamento desses dados é encontrar o valor máximo em grandes coleções numéricas, que podem conter milhões de 
    elementos.

    Para otimizar esse processo, sua equipe decidiu implementar uma solução utilizando a técnica de Divisão e Conquista.

    Seu trabalho é desenvolver um algoritmo recursivo, na linguagem C, que utilize a técnica de Divisão e Conquista para encontrar o maior elemento de uma lista de números 
    inteiros. A ideia é dividir a lista em partes menores, processá-las recursivamente e, ao final, combinar as soluções para encontrar o valor máximo.
*/
#include <stdio.h>

int greaterNumber(int s[], int init, int end){

    if(init == end)
        return s[init];

    int mid = (init + end) / 2;
    int greaterLeft = greaterNumber(s, init, mid);

    int greaterRight = greaterNumber(s, mid + 1, end);

    if(greaterLeft > greaterRight)
        return greaterLeft;
    else 
        return greaterRight;
}

int main(){

    int s[] = {15, 42, 8, 23, 97, 5, 63, 12, 88, 34, 76, 91, 54, 30, 99, 3, 67, 82, 20, 45};
    int sizeS = sizeof(s) / sizeof(s[0]);


    int greater = greaterNumber(s, 0, sizeS - 1);

    printf("%d\n", greater);
}