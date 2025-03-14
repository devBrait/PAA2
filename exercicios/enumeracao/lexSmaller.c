#include <stdio.h>

void sequenceSmaller(char *s, char *r, int sizeS, int sizeR){

    int smallSize = sizeS < sizeR ? sizeS : sizeR;

    for(int i = 0; i < smallSize; i++)
    {
        if(r[i] < s[i])
        {
            printf("Sequence of R is smaller.\n");
            return;
        }else if (r[i] > s[i]) 
            return;
    }

    if(sizeR < sizeS)
     printf("Sequence of R is smaller.\n");
}


int main(){
    char s[] = "apple";
    char r[] = "app";

    sequenceSmaller(s, r, sizeof(s) - 1, sizeof(r) - 1);

    return 0;
}