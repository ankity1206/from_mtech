#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double val;
    int idx;
} Pair;

int cmp(const void *a, const void *b) {
    double d = ((Pair*)b)->val - ((Pair*)a)->val;
    return (d > 0) - (d < 0);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    double R[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &R[i][j]);

    for (int i = 0; i < m; i++) {
        Pair arr[n];

        for (int j = 0; j < n; j++) {
            arr[j].val = R[i][j];
            arr[j].idx = j;
        }

        qsort(arr, n, sizeof(Pair), cmp);

        int rank[n];

        for (int j = 0; j < n; j++)
            rank[arr[j].idx] = j + 1;

        for (int j = 0; j < n; j++)
            printf("%d ", rank[j]);

        printf("\n");
    }

    return 0;
}
