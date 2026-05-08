#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int *OrgArr,*SortArr;
int N;

void *sorting1(void *arg){
    for(int i=0;i<N/2;i++){
        for(int j=i;j<N/2;j++){
            if(OrgArr[i]>OrgArr[j]){
                int tmp=OrgArr[i];
                OrgArr[i]=OrgArr[j];
                OrgArr[j]=tmp;
            }
        }
    }
    pthread_exit(0);
}

void *sorting2(void *arg){
    for(int i=N/2+1;i<N;i++){
        for(int j=i;j<N;j++){
            if(OrgArr[i]>OrgArr[j]){
                int tmp=OrgArr[i];
                OrgArr[i]=OrgArr[j];
                OrgArr[j]=tmp;
            }
        }
    }
    pthread_exit(0);
}

void *merging(void *arg){
    SortArr=malloc(N*sizeof(int));
    int p1=0,mid=N+1;
    int p2=mid,j=0;
   while(p1<mid && p2<N){
        if(OrgArr[p1]<OrgArr[p2]){
            SortArr[j]=OrgArr[p1];
            p1++;
        }
        else if(OrgArr[p1]>OrgArr[p2]){
            SortArr[j]=OrgArr[p2];
            p2++;
        }
        else{
            SortArr[j]=OrgArr[p1];
            p1++;
            p2++;
        }
    }
   while (p1 < mid) SortArr[j++] = OrgArr[p1++];
   while (p2 < N) SortArr[j++] = OrgArr[p2++];
   pthread_exit(0);
}

int main(int argc, char* argv[]){
    pthread_t t1,t2,t3;
    pthread_attr_t attr1,attr2,attr3;
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);
    int  nums[argc-1];
    for(int i=1;i<argc;i++){
        nums[i-1]=atof(argv[i]);
    }
    N=argc-1;
    OrgArr=nums;
    pthread_create(&t1, NULL, sorting1, NULL);
    pthread_create(&t2, NULL, sorting2, NULL);
    pthread_join(t1, NULL); // Wait for sort 1
    pthread_join(t2, NULL); // Wait for sort 2
    pthread_create(&t3, NULL, merging, NULL); // Start merge ONLY after sorts finish
    pthread_join(t3, NULL);
    for(int i=0;i<N;i++)
        printf("%d\t",SortArr[i]);
    printf("\n Main thread exited\n");

}
