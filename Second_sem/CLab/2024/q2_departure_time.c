#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arrival,k,f[20],t[20];
} Patient;

Patient P[1000];

int main(){
    int m,n;
    scanf("%d %d",&m,&n);

    for(int i=0;i<m;i++){
        scanf("%d %d",&P[i].arrival,&P[i].k);
        int total=0;
        for(int j=0;j<P[i].k;j++){
            scanf("%d %d",&P[i].f[j],&P[i].t[j]);
            total += P[i].t[j];
        }

        int time = P[i].arrival + total;

        printf("%d %04d\n",i,time);
    }
}
