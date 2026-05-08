#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    Node *node;
    struct Stack *next;
} Stack;

void push(Stack **top, Node *n) {
    Stack *temp = malloc(sizeof(Stack));
    temp->node = n;
    temp->next = *top;
    *top = temp;
}

Node* pop(Stack **top) {
    Stack *temp = *top;
    Node *n = temp->node;
    *top = temp->next;
    free(temp);
    return n;
}

int empty(Stack *top) {
    return top == NULL;
}

void pushLeft(Stack **s, Node *root) {
    while (root) {
        push(s, root);
        root = root->left;
    }
}

int main() {
    Node *T1 = NULL, *T2 = NULL; // assume read_tree fills these

    Stack *s1 = NULL, *s2 = NULL;
    pushLeft(&s1, T1);
    pushLeft(&s2, T2);

    while (!empty(s1) || !empty(s2)) {
        Stack **s;

        if (empty(s1)) s = &s2;
        else if (empty(s2)) s = &s1;
        else {
            if (s1->node->val <= s2->node->val)
                s = &s1;
            else
                s = &s2;
        }

        Node *curr = pop(s);
        printf("%d\n", curr->val);
        pushLeft(s, curr->right);
    }

    return 0;
}
