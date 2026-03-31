#include <stdio.h>
#include <stdlib.h>

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

typedef struct {
    int *arr, top;
} Stack;

void push(Stack *s, int x) { s->arr[++s->top] = x; }
int pop(Stack *s) { return s->arr[s->top--]; }
int empty(Stack *s) { return s->top == -1; }

void pushLeft(TREE *t, Stack *s, int idx) {
    while (idx != -1) {
        push(s, idx);
        idx = t->nodes[idx].left;
    }
}

void pushRight(TREE *t, Stack *s, int idx) {
    while (idx != -1) {
        push(s, idx);
        idx = t->nodes[idx].right;
    }
}

int main() {
    TREE t1, t2;
    read_tree(&t1);
    read_tree(&t2);

    int x;
    while (scanf("%d", &x) == 1) {
        printf("Target: %d\n", x);

        Stack s1 = {malloc(t1.n*sizeof(int)), -1};
        Stack s2 = {malloc(t2.n*sizeof(int)), -1};

        pushLeft(&t1, &s1, t1.root);
        pushRight(&t2, &s2, t2.root);

        while (!empty(&s1) && !empty(&s2)) {
            int i = s1.arr[s1.top];
            int j = s2.arr[s2.top];

            int v1 = t1.nodes[i].data;
            int v2 = t2.nodes[j].data;

            if (v1 + v2 == x) {
                printf("Index in T1: %d, value = %d; Index in T2: %d, value = %d.\n",
                        i, v1, j, v2);

                pop(&s1); pop(&s2);
                pushLeft(&t1, &s1, t1.nodes[i].right);
                pushRight(&t2, &s2, t2.nodes[j].left);
            }
            else if (v1 + v2 < x) {
                pop(&s1);
                pushLeft(&t1, &s1, t1.nodes[i].right);
            }
            else {
                pop(&s2);
                pushRight(&t2, &s2, t2.nodes[j].left);
            }
        }

        free(s1.arr);
        free(s2.arr);
    }
    return 0;
}
