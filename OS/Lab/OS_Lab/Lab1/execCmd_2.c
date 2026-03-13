#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#define LINE_SIZE 1024
int main ( ){
    char pwd[1024];
    getcwd(pwd,sizeof(pwd)); // for getting the path of current directory we are in
    char line[LINE_SIZE];
    while (1) {
        /* Read a line of input from the user */
        printf("ankit$%s: ",pwd);
        fgets(line,LINE_SIZE,stdin);
        line[strlen(line)-1] = '\0';
        char *args[64];
        int i = 0;
        args[i] = strtok(line," ");
        while(args[i] != NULL){
            i++;
            args[i] = strtok(NULL," ");
        }
        if(args[0] == NULL)
            continue;
       if(!strcmp(args[0],"exit"))
           break;
        int background = 0;
        if(i > 0 && strcmp(args[i-1], "&") == 0){
            background = 1;
            args[i-1] = NULL;
        }
        if(!strcmp(args[0],"cd")){
            if(args[1]==NULL)
                printf("cd: argument missing\n");
            else{
                if(chdir(args[1])!=0)
                    perror("cd");
                else{
                    getcwd(pwd,sizeof(pwd));                    
                }
            }
            continue;
        }
        if (fork()) { /* Parent process */
            if(!background){
                 wait(NULL);
            }
        }
        else { /* Child process */
            //char *cmnd=strtok(line, " ");
             //char *rest = cmnd + strlen(cmnd) +1;
            // printf("cmnd %s and argu is _%s.\n",cmnd,rest);
            // if(rest==NULL)
              //  *rest="";
            // char *args[]={cmnd,rest,NULL};
             //execvp(cmnd,args);
            if (execvp(args[0], args) == -1) {
                fprintf(stderr, "Command %s not found\n", args[0]);
                exit(127);
            }
        }
    }
    exit(0);
}
