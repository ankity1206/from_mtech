#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int index, value;
    struct Node *left, *right;
} Node;

typedef struct StackNode {
    Node *node;
    int visited;
    struct StackNode *next;
} StackNode;

void push(StackNode **top, Node *node, int visited) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->node = node;
    temp->visited = visited;
    temp->next = *top;
    *top = temp;
}

StackNode *pop(StackNode **top) {
    StackNode *temp = *top;
    *top = (*top)->next;
    return temp;
}

int isEmpty(StackNode *top) {
    return top == NULL;
}

void printStack(StackNode *top) {
    StackNode *curr = top;
    while (curr) {
        printf("(%d,%d) ", curr->node->index, curr->node->value);
        curr = curr->next;
    }
    printf("\n");
}

void inorder(Node *root) {
    StackNode *S = NULL;
    push(&S, root, 0);

    while (!isEmpty(S)) {
        printStack(S);

        StackNode *temp = pop(&S);
        Node *v = temp->node;
        int visited = temp->visited;
        free(temp);

        if (v == NULL) continue;

        if (visited) {
            printf("%d %d\n", v->index, v->value);
        } else {
            push(&S, v->right, 0);
            push(&S, v, 1);
            push(&S, v->left, 0);
        }
    }
}
