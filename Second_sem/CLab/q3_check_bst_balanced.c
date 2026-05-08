#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int data, left, right;
} Node;

typedef struct {
    Node *nodes;
    int root, n;
} TREE;

void read_tree(TREE *t) {
    scanf("%d", &t->n);
    t->nodes = malloc(t->n * sizeof(Node));
    for (int i = 0; i < t->n; i++)
        scanf("%d %d %d", &t->nodes[i].data,
                          &t->nodes[i].left,
                          &t->nodes[i].right);
    t->root = 0;
}

int isBSTUtil(TREE *t, int idx, int min, int max) {
    if (idx == -1) return 1;

    int val = t->nodes[idx].data;
    if (val < min || val > max) return 0;

    return isBSTUtil(t, t->nodes[idx].left, min, val-1) &&
           isBSTUtil(t, t->nodes[idx].right, val+1, max);
}

int is_BST(TREE *t) {
    return isBSTUtil(t, t->root, INT_MIN, INT_MAX);
}

int height(TREE *t, int idx) {
    if (idx == -1) return 0;

    int lh = height(t, t->nodes[idx].left);
    if (lh == -1) return -1;

    int rh = height(t, t->nodes[idx].right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return 1 + (lh > rh ? lh : rh);
}

int is_balanced(TREE *t) {
    return height(t, t->root) != -1;
}

int main() {
    TREE t;
    read_tree(&t);

    printf("BST: %s, Balanced: %s.\n",
           is_BST(&t) ? "YES" : "NO",
           is_balanced(&t) ? "YES" : "NO");

    free(t.nodes);
    return 0;
}
