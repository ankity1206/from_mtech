#include <stdio.h>
#include <stdlib.h>

int N;
int left[1000], right[1000];
int parent[1000];

void preorder(int root, int *count) {
    if (root == -1) return;

    printf("%d ", root);

    int children = 0;
    if (left[root] != -1) children++;
    if (right[root] != -1) children++;

    if (children < 2) (*count)++;

    preorder(left[root], count);
    preorder(right[root], count);
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        parent[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &left[i], &right[i]);

        if (left[i] != -1) parent[left[i]] = i;
        if (right[i] != -1) parent[right[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        if (parent[i] == -1) { // root
            int count = 0;
            preorder(i, &count);
            printf("%d\n", count);
        }
    }
}
