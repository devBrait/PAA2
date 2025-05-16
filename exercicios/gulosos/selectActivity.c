#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compare(const void *a, const void *b) {
    Activity *x = (Activity *)a;
    Activity *y = (Activity *)b;
    return x->end - y->end;
}

void selectActivitiesGreedy(Activity A[], int n) {
    qsort(A, n, sizeof(Activity), compare);

    printf("Atividades selecionadas: ");

    int lastEnd = A[0].end;
    printf("(%d,%d) ", A[0].start, A[0].end);

    for (int i = 1; i < n; i++) {
        if (A[i].start >= lastEnd) {
            printf("(%d,%d) ", A[i].start, A[i].end);
            lastEnd = A[i].end;
        }
    }
    printf("\n");
}

int main() {
    Activity A[] = { {7,9}, {5,6}, {4,9}, {1,2}, {3,7}, {6,8}, {2,5}, {1,3}, {1,4} };
    int n = sizeof(A) / sizeof(A[0]);

    selectActivitiesGreedy(A, n);

    return 0;
}