#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#define LINE_SIZE 1024

int main(){
     char pwd[1024];
     getcwd(pwd,sizeof(pwd)); // for getting the path of current directory we are in
     char line[LINE_SIZE];
     while (1) {
        while(waitpid(-1,NULL,WNOHANG) > 0);
         /* Read a line of input from the user */
        printf("ankit$%s: ",pwd);
        fgets(line,LINE_SIZE,stdin);
        line[strlen(line)-1] = '\0';
        /*------Parallel execution-----*/
        if(strstr(line,"&&&")){

            char *cmd = line;

            pid_t pids[64];
            int count = 0;

            while(cmd){

                char *next = strstr(cmd,"&&&");

                if(next){
                    *next = '\0';
                    next += 3;
                }

                char *args[64];
                int i = 0;

                args[i] = strtok(cmd," ");

                while(args[i]){
                    i++;
                    args[i] = strtok(NULL," ");
                }

                if(args[0] == NULL){
                    cmd = next;
                    continue;
                }

                pid_t pid = fork();

                if(pid == 0){
                    execvp(args[0],args);
                    printf("Command %s not found\n",args[0]);
                    exit(1);
                }
                else{
                    pids[count++] = pid;
                }

                cmd = next;
            }

            for(int i=0;i<count;i++)
                waitpid(pids[i],NULL,0);

            continue;
        }

        /*-------------------------------*/
        else{
            int background = 0;

            char *amp = strchr(line,'&');

            if(amp && *(amp+1) != '&'){
                background = 1;
                *amp = '\0';
            }

            char *cmd = line;
            while(cmd){
                char *next = strstr(cmd,"&&");
                if(next){
                    *next = '\0';
                    next += 2;
                }
            char *args[64];
            int i = 0;

            args[i] = strtok(cmd," ");

            while(args[i] != NULL){
                i++;
                args[i] = strtok(NULL," ");
            }
            if(args[0] == NULL){
                cmd = next;
                continue;
            }
            if(!strcmp(args[0],"exit"))
               exit(0);

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
                cmd = next;
                continue;
            }
            pid_t pid = fork();
            if (pid>0) { /* Parent process */
                if(!background){
                    int status;
                    waitpid(pid,&status,0);
                    if(!WIFEXITED(status) || WEXITSTATUS(status) != 0)
                        break; 
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
            cmd = next; 
            }
        }
    }
    exit(0);
}