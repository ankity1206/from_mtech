#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
    int f;
    f=fork();
    
    if(f>0){
    wait(NULL);
    printf("Command successfully completed");
    }

    else {
        /*
        if(argc==0){
            execl("execCmd.c","execCmd.c","./execCmd",(char*)NULL);
        exit(0);
        }
        */
      char *args[]={argv[1],argv[2],NULL};
      printf("Cmnd is %s and argu is %s.\n",argv[1],argv[2]);
      execvp(argv[1],args);
        // execlp("ls","ls","-l",(char*)NULL);
        // execl("/bin/ls","ls","-l",(char*)NULL);
        exit(0);
    }
   // free(cmd);
   // free(input);
    return 0;
}
