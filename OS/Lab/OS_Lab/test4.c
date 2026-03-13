#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
// #include<sys/wait.h>
int main(){
    pid_t p=fork();
    // pid_t p1=fork();
    if(p<0){
        printf("child creation failed");
    }
    else if(p>0){
        printf("1st child creation successful.");
    }
    else{
        // wait(NULL);
        printf("this is from parent.\n");
    }
    pid_t p2=fork();
    if(p2>0){
        if(p==0)
            printf("\nthis is 2nd child of original parent");
        if(p>0)
            printf("\nthis is child of first child of original parent.");    
    }
    printf("Hello!\n");

    // if(p1<0){
    //     printf("child creation failed");
    // }
    // else if(p1>0){
    //     printf("2nd child creation successful.");
    // }
    // else{
    //     if(p>0)
    //         printf("this is from 1st.\n");
    //     else
    //         printf("this is from parent.\n");
    //         wait(NULL);
    // }
    // printf("bye!\n");
    return 0;
}