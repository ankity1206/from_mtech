#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void waitexample(){
    int stat;
    if(fork()==0)
        exit(1);
    else
        wait(&stat);
    if(WIFEXITED(stat)){
        printf("Exit status: %d\n",WEXITSTATUS(stat));
    }
    else if(WIFSIGNALED(stat))
        psignal(WTERMSIG(stat),"Exit signal");

}

int main(){
    waitexample();
    return 0;
}