#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
    int f;
    f=fork();
    if(f==0){
      char *args[]={"ls","-l",NULL};
      execvp("ls",args);
        // execlp("ls","ls","-l",(char*)NULL);
        // execl("/bin/ls","ls","-l",(char*)NULL);
    }
    wait(NULL);
    return 0;
}
