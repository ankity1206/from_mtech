#include <stdio.h>
#include <stdlib.h>

#define MAX 1005
#define N 2000000000

typedef struct {
    int i, j;
    long long sum;
} Triple;

Triple heap[MAX];
int size = 0;

void swap(int a, int b) {
    Triple t = heap[a];
    heap[a] = heap[b];
    heap[b] = t;
}

void heapify_up(int idx) {
    while (idx > 0) {
        int p = (idx - 1) / 2;
        if (heap[p].sum <= heap[idx].sum) break;
        swap(p, idx);
        idx = p;
    }
}

void heapify_down(int idx) {
    while (1) {
        int l = 2*idx+1, r = 2*idx+2, smallest = idx;

        if (l < size && heap[l].sum < heap[smallest].sum) smallest = l;
        if (r < size && heap[r].sum < heap[smallest].sum) smallest = r;

        if (smallest == idx) break;

        swap(idx, smallest);
        idx = smallest;
    }
}

void insert(int i, int j) {
    long long sum = (long long)i*i*i + (long long)j*j*j;
    heap[size++] = (Triple){i,j,sum};
    heapify_up(size-1);
}

Triple extract_min() {
    Triple t = heap[0];
    heap[0] = heap[--size];
    heapify_down(0);
    return t;
}

int main() {
    for (int j = 0; j <= 1000; j++)
        insert(0, j);

    while (size > 0) {
        Triple t = extract_min();
        printf("%d %d %lld\n", t.i, t.j, t.sum);

        int i = t.i, j = t.j;
        if (i + 1 <= j) {
            long long newSum = (long long)(i+1)*(i+1)*(i+1) + (long long)j*j*j;
            if (newSum <= N)
                insert(i+1, j);
        }
    }
    return 0;
}
