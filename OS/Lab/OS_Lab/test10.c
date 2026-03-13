#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
// int main(){
//     int x=0;
//     for(int i=0;i<5;i++){
//         fork();
//     }
//     printf("Hello\n");
//     return 0;
// }


void f(int n){
    int i;
    for(i=0;i<n;i++){
        if(fork()){
            printf("A\t");
            fflush(stdout);
        }
    }
    for(i=0;i<n;i++){
        wait(NULL);
    }
    printf("B\n");
    fflush(stdout);
    // exit(0);

}

int main(){
    // int pid;
    // pid=fork();
    // if(pid>0){
    //     printf("Parent: child pid: %d\n",pid);
    //     pid=wait(NULL);
    //     printf("Hello from parent: child process is terminated\n");
    //     printf("Parent: child %d exited\n",pid);
    // }    
    // else{
    //     printf("In child process\thello from child\n");
    //     // exit(0);
    // }

    // int i=0, pid;
    // pid = fork();
    // if (pid > 0){
    //     sleep(1);
    //     printf("parent : %d\n", i);
    //     wait(NULL);
    //     // printf("Update from parent : %d\n", i);
    //     }
    // else{
    //     i = i + 1;	
    //     printf("child : %d\n", i);
    //     sleep(1);
    //     i = i + 1;	
    //     printf("child : %d\n", i);
    // }

    f(3);

    return 0;
}