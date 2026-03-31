#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    double R[m][n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &R[i][j]);

    // reuse logic from Q1 + Q2 (simplified)
    double rank[m][n], overall[n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int r = 1;
            for (int k = 0; k < n; k++)
                if (R[i][k] > R[i][j]) r++;
            rank[i][j] = r;
        }
    }

    for (int j = 0; j < n; j++) {
        overall[j] = 0;
        for (int i = 0; i < m; i++)
            overall[j] += rank[i][j];
    }

    double final[n];

    for (int j = 0; j < n; j++) {
        int r = 1;
        for (int k = 0; k < n; k++)
            if (overall[k] < overall[j]) r++;
        final[j] = r;
    }

    for (int i = 0; i < m; i++) {
        double mare = 0;
        for (int j = 0; j < n; j++)
            mare += fabs(rank[i][j] - final[j]);

        mare /= n;
        printf("%.6f ", mare);
    }

    return 0;
}
