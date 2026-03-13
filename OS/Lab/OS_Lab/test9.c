#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
// #include<sys/wait.h>
#include <sys/wait.h>
int main(){
    // int p=fork();
    // if(p<0){
    //     printf("error in creating child process.\n");
    // }
    // else if(p==0){
    //     printf("from child.\n");
    // }
    // else{
    //     wait(NULL);
    //     printf("from parent.\n");
    // }
    // // printf("Hello\n");

    pid_t p=fork();
    if(p==0){
        // sleep(3);
        printf("Hello from child\n");
    }
    else{
        printf("Hello from parent\n");
        // wait(NULL);
        printf("Child terminated\n");
    }
    printf("Bye\n");
    return 0;
}