#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int time,p,f,dur,step;
} Event;

Event heap[MAX];
int size=0;

void push(Event e){
    heap[size]=e;
    int i=size++;
    while(i>0){
        int p=(i-1)/2;
        if(heap[p].time<=heap[i].time) break;
        Event t=heap[p]; heap[p]=heap[i]; heap[i]=t;
        i=p;
    }
}

Event pop(){
    Event e=heap[0];
    heap[0]=heap[--size];
    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<size && heap[l].time<heap[s].time) s=l;
        if(r<size && heap[r].time<heap[s].time) s=r;
        if(s==i) break;
        Event t=heap[i]; heap[i]=heap[s]; heap[s]=t;
        i=s;
    }
    return e;
}

typedef struct {
    int arrival,k,f[20],t[20];
} Patient;

Patient P[1000];
int facility_free[100];
int wait_time[1000];

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    for(int i=0;i<n;i++) facility_free[i]=0;

    for(int i=0;i<m;i++){
        wait_time[i]=0;

        scanf("%d %d",&P[i].arrival,&P[i].k);
        for(int j=0;j<P[i].k;j++)
            scanf("%d %d",&P[i].f[j],&P[i].t[j]);

        push((Event){P[i].arrival,i,P[i].f[0],P[i].t[0],0});
    }

    while(size){
        Event e=pop();

        if(e.time < facility_free[e.f]){
            wait_time[e.p] += facility_free[e.f] - e.time;

            push((Event){facility_free[e.f],e.p,e.f,e.dur,e.step});
            continue;
        }

        facility_free[e.f] = e.time + e.dur;

        int next_time = facility_free[e.f];
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

    for(int i=0;i<m;i++)
        printf("%d %d\n",i,wait_time[i]);
}
