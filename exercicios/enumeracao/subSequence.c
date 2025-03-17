#include <stdio.h>

void decideSubSequence(int *s, int *a, int sizeS, int sizeA){
    int total = 0;

    for(int i = 0; i < sizeA; i++)
    {
        if(sizeS > total && s[total] == a[i]) 
            total++;
    }

    if(total == sizeS)
        printf("Valid subsequence.\n");
    else 
        printf("Invalid subsequence\n");
}

int main(){
    int s[] = {2,3,5,8};
    int a[] = {1,2,3,4,5,6,7,8};
    
    int sizeS = sizeof(s) / sizeof(s[0]);
    int sizeA = sizeof(a) / sizeof(a[0]);

    decideSubSequence(s, a, sizeS, sizeA);

    return 0;
}