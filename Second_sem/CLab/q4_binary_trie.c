#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int left, right;
    char flag; // -1 or character
} Node;

Node trie[1000];
int n;

char* decode(char *s) {
    char *res = malloc(500);
    int pos = 0, i = 0;

    while (s[i]) {
        int curr = 0;

        while (1) {
            if (trie[curr].flag != -1) {
                res[pos++] = trie[curr].flag;
                break;
            }

            if (!s[i]) {
                printf("Not a valid encoding.\n");
                free(res);
                return NULL;
            }

            if (s[i] == '0')
                curr = trie[curr].left;
            else
                curr = trie[curr].right;

            if (curr == -1) {
                printf("Not a valid encoding.\n");
                free(res);
                return NULL;
            }
            i++;
        }
    }

    res[pos] = '\0';
    return res;
}

int find_code(int node, char ch, char *path, int depth, char *ans) {
    if (node == -1) return 0;

    if (trie[node].flag == ch) {
        path[depth] = '\0';
        strcpy(ans, path);
        return 1;
    }

    path[depth] = '0';
    if (find_code(trie[node].left, ch, path, depth+1, ans)) return 1;

    path[depth] = '1';
    if (find_code(trie[node].right, ch, path, depth+1, ans)) return 1;

    return 0;
}

char* encode(char *s) {
    char *res = malloc(1000);
    res[0] = '\0';

    for (int i = 0; s[i]; i++) {
        char path[200], ans[200];

        if (!find_code(0, s[i], path, 0, ans)) {
            printf("Unexpected input\n");
            free(res);
            return NULL;
        }
        strcat(res, ans);
    }
    return res;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char temp[5];
        scanf("%d %d %s", &trie[i].left, &trie[i].right, temp);

        if (strcmp(temp, "-1") == 0)
            trie[i].flag = -1;
        else
            trie[i].flag = temp[0];
    }

    char input[300];

    while (scanf("%s", input) == 1) {
        if (input[0] == '0' || input[0] == '1') {
            char *res = decode(input);
            if (res) {
                printf("%s\n", res);
                free(res);
            }
        } else {
            char *res = encode(input);
            if (res) {
                printf("%s\n", res);
                free(res);
            }
        }
    }

    return 0;
}
