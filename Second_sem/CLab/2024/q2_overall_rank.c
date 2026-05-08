#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double score;
    int idx;
} Pair;

int cmp(const void *a, const void *b) {
    double d = ((Pair*)a)->score - ((Pair*)b)->score;
    return (d > 0) - (d < 0);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    double R[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &R[i][j]);

    int rank[m][n];

    for (int i = 0; i < m; i++) {
        Pair arr[n];
        for (int j = 0; j < n; j++) {
            arr[j].score = R[i][j];
            arr[j].idx = j;
        }

        qsort(arr, n, sizeof(Pair), cmp);

        for (int j = 0; j < n; j++)
            rank[i][arr[j].idx] = n - j;
    }

    double sum[n];
    for (int j = 0; j < n; j++) {
        sum[j] = 0;
        for (int i = 0; i < m; i++)
            sum[j] += rank[i][j];
    }

    Pair films[n];
    for (int j = 0; j < n; j++) {
        films[j].score = sum[j];
        films[j].idx = j;
    }

    qsort(films, n, sizeof(Pair), cmp);

    double final_rank[n];

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && films[j].score == films[i].score) j++;

        double avg = (i + 1 + j) / 2.0;

        for (int k = i; k < j; k++)
            final_rank[films[k].idx] = avg;

        i = j;
    }

    for (int j = 0; j < n; j++)
        printf("%.1f ", final_rank[j]);

    return 0;
}
