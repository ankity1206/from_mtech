#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

float avg1,max1,min1;
float *nums1;
int N;
void *funmax(){
    max1=nums1[0];
    for(int i=0;i<N;i++){
        if(nums1[i]>max1){
            max1=nums1[i];
           // printf("%f",max1);
        }
    }
    pthread_exit(0);
}

void *funmin(){
    min1=nums1[0];
    for(int i=0;i<N;i++){
        if(nums1[i]<min1){
            min1=nums1[i];
           // printf("%f",min1);
        }
    }
        pthread_exit(0);
}

void *funavg(){
    float sum=0.0;
    for(int i=0;i<N;i++){
        sum+=nums1[i];
       // printf("\n Sum:%f",sum);
    }
    avg1=(float)sum/N;
    pthread_exit(0);
}

int main(int argc, char* argv[]){
    pthread_t t1,t2,t3;
    pthread_attr_t attr1,attr2,attr3;
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);
    float nums[argc-1];
    for(int i = 1; i < argc; i++) {
        nums[i-1] = atof(argv[i]);
    }

    N=argc-1;
   // printf("\nN:%d\n",N);
    nums1=nums;
    pthread_create(&t1,&attr1,funavg,&nums);
    pthread_create(&t2,&attr2,funmax,&nums);
    pthread_create(&t3,&attr3,funmin,&nums);
   // printf("\nMax: %f, Min:  %f, Avg:  %f\n",max1,min1,avg1);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
        printf("\nMax: %f, Min:  %f, Avg:  %f\n",max1,min1,avg1);
    printf("\n Main thread exited\n");
}
