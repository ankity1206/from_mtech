#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int time, p, f, dur, step;
} Event;

Event heap[MAX];
int size = 0;

void swap(int i, int j) {
    Event t = heap[i]; heap[i] = heap[j]; heap[j] = t;
}

void push(Event e) {
    heap[size] = e;
    int i = size++;
    while (i > 0) {
        int p = (i-1)/2;
        if (heap[p].time <= heap[i].time) break;
        swap(p,i);
        i = p;
    }
}

Event pop() {
    Event e = heap[0];
    heap[0] = heap[--size];

    int i = 0;
    while (1) {
        int l=2*i+1, r=2*i+2, s=i;
        if (l<size && heap[l].time < heap[s].time) s=l;
        if (r<size && heap[r].time < heap[s].time) s=r;
        if (s==i) break;
        swap(i,s);
        i=s;
    }
    return e;
}

typedef struct {
    int arrival;
    int k;
    int f[20], t[20];
} Patient;

Patient P[1000];

void print_time(int t) {
    printf("%04d:", t);
}

int main() {
    int m,n;
    scanf("%d %d",&m,&n);

    for(int i=0;i<m;i++){
        scanf("%d %d",&P[i].arrival,&P[i].k);
        for(int j=0;j<P[i].k;j++)
            scanf("%d %d",&P[i].f[j],&P[i].t[j]);

        push((Event){P[i].arrival,i,P[i].f[0],P[i].t[0],0});
    }

    while(size){
        Event e = pop();

        print_time(e.time);
        printf(" Facility %d attends to Patient %d for %d minutes\n",
                e.f,e.p,e.dur);

        int next_time = e.time + e.dur;
        int step = e.step + 1;

        if(step < P[e.p].k){
            push((Event){
                next_time,
                e.p,
                P[e.p].f[step],
                P[e.p].t[step],
                step
            });
        }
    }
}
