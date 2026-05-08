#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data, left, right;
} Node;

typedef struct {
    Node *nodes;
    int root;
    int n;
} TREE;

void read_tree(TREE *t) {
    scanf("%d", &t->n);
    t->nodes = (Node *)malloc(t->n * sizeof(Node));

    for (int i = 0; i < t->n; i++)
        scanf("%d %d %d", &t->nodes[i].data,
                          &t->nodes[i].left,
                          &t->nodes[i].right);

    t->root = 0;
}

int min_node(TREE *t, int *index) {
    int curr = t->root;
    while (t->nodes[curr].left != -1)
        curr = t->nodes[curr].left;

    *index = curr;
    return t->nodes[curr].data;
}

int max_node(TREE *t, int *index) {
    int curr = t->root;
    while (t->nodes[curr].right != -1)
        curr = t->nodes[curr].right;

    *index = curr;
    return t->nodes[curr].data;
}

int main() {
    TREE t;
    read_tree(&t);

    int idx_min, idx_max;

    int minv = min_node(&t, &idx_min);
    int maxv = max_node(&t, &idx_max);

    printf("Minimum value: %d, node index = %d\n", minv, idx_min);
    printf("Maximum value: %d, node index = %d.\n", maxv, idx_max);

    free(t.nodes);
    return 0;
}
