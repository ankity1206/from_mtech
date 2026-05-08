#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parent[10000], rank_arr[10000];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_set(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) {
        if (rank_arr[pa] < rank_arr[pb])
            parent[pa] = pb;
        else if (rank_arr[pb] < rank_arr[pa])
            parent[pb] = pa;
        else {
            parent[pb] = pa;
            rank_arr[pa]++;
        }
    }
}

int main() {
    int r, c;
    scanf("%d, %d", &r, &c);

    char grid[r][c+1];

    for (int i = 0; i < r; i++)
        scanf("%s", grid[i]);

    int total = r * c;

    for (int i = 0; i < total; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }

    int dx[] = {-1,-1,-1,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'L') {
                int id1 = i*c + j;

                for (int d = 0; d < 8; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (ni >= 0 && nj >= 0 && ni < r && nj < c &&
                        grid[ni][nj] == 'L') {
                        int id2 = ni*c + nj;
                        union_set(id1, id2);
                    }
                }
            }
        }
    }

    int visited[10000] = {0};
    int count = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'L') {
                int root = find(i*c + j);
                if (!visited[root]) {
                    visited[root] = 1;
                    count++;
                }
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
