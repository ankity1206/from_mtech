#include <stdio.h>
#include <stdlib.h>

int m, n;
int grid[200][200];
int visited[200][200];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int dfs(int i, int j) {
    visited[i][j] = 1;
    int count = 1;

    for (int d = 0; d < 8; d++) {
        int ni = i + dx[d], nj = j + dy[d];

        if (ni>=0 && nj>=0 && ni<m && nj<n &&
            grid[ni][nj] == 1 && !visited[ni][nj]) {
            count += dfs(ni, nj);
        }
    }
    return count;
}

int main() {
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                int count = dfs(i, j);
                printf("%d %d %d\n", i, j, count);
            }
        }
    }
}
