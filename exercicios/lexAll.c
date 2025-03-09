#include <stdio.h>

void defineSequence(char *s, char *r, int sizeS, int sizeR){

    int smallSize = sizeS < sizeR ? sizeS : sizeR;

    for(int i = 0; i < smallSize; i++)
    {
        if(s[i] > r[i])
        {
            printf("Sequence of R is smaller.\n");
            return;
        }else if(r[i] > s[i])
        {
            printf("Sequence of R is greater.\n");
            return;
        }
    }

    if(sizeR > sizeS)
     printf("Sequence of R is greater.\n");
    else if(sizeS > sizeR)
     printf("Sequence of R is smaller.\n");
    else
        printf("Sequences are equal.\n");

}


int main(){
    char s[] = "apple";
    char r[] = "appetizer";

    defineSequence(s, r, sizeof(s) - 1, sizeof(r) - 1);

    return 0;
}