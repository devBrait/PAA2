#include <stdio.h>

void countSequences(int sequence[], int sizeS){

    int quant = 1;
    for (int i = 1; i < sizeS; i++) {
        if (sequence[i - 1] != sequence[i]){
            quant++;
        }
    }

    printf("Total of subSequences %d\n", quant);
}

int main(){
    int sequence[] = {5, 2, 2, 3, 4, 4, 4, 4, 4, 1, 1};
    int sizeS = sizeof(sequence) / sizeof(sequence[0]);

    countSequences(sequence, sizeS);

    return 0;
}