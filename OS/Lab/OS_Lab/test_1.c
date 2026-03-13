// trials for forking

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
     int pid;
    // int x=3;
    // printf("Original x is %d\n",x);
     pid=fork();
     if(pid>0){
         wait(NULL);
         printf("I am Parent %d",getpid());
        // wait(NULL);
        // printf("After child completion, value of x is:%d\n",x);
     }
     else{
         printf("I am child_1, %d",getpid());
         //x=x+5;
     }

    // if(pid==0){
    //     x+=5;
    //     printf("Child:%d address %p\n",x,&x);
    // }
    // else{
    //     x-=5;
    //     wait(NULL);
    //     printf("Parent:%d address %p\n",x,&x);
    //     // wait(NULL);
    // }

    // while(x>0){
    //     x-=1;
    //     pid=fork();
    //     printf("hello: %d ->  %d\n",getpid(),pid);
    //     wait(NULL);
    // }
    /*
    printf("Parent pid %d\n",getpid());
    if(fork() && !fork()){
        if(fork() || fork()){
            fork();
            wait(NULL);
        }
    }
    printf("X with pid %d\n",getpid());
    */
    //wait(NULL);
    // exit(0);
    return 0;
}
