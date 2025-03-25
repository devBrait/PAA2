/*     
    Exercício Backtracking ->     
    Escreva uma função recursiva para computar o coeficiente binomial. 
*/
#include <stdio.h>

int backBinomial(int n, int m) {
    if (m == 0 || m == n) {
        return 1;
    }
    
    return backBinomial(n - 1, m - 1) + backBinomial(n - 1, m);
}

int main() {
    int n = 5;  
    int m = 2; 
    
    int result = backBinomial(n, m);
    
    printf("C(%d, %d) = %d\n", n, m, result);
    
    return 0;
}