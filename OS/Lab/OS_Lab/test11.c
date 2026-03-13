// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<sys/wait.h>
// #include<string.h>
// #include<stdbool.h>
// #include<stdlib.h>
// // int main(){
// //     fork();
// //     // fork();
// //     // fork();
// //     while(true);
// //     return 0;
// // }

// int main(int argc, char *argv[]) {
// 	if (argc > 1 && strcmp(argv[1], "execed") == 0) {
//         printf("Stop condition met. No fork/exec.\n");
//         return 0;
//     }
// 	pid_t p = fork();
// 	if (p == 0) {
// 		printf("Child PID %d\n", getpid());
// 		printf("Parent PID %d\n", getppid());
//         execlp("./a.out","a.out",NULL);
//         // printf("Hello\n");
//         // sleep(1);
//         // printf("Hello1\n");
//  	}
// 	else {
//         // wait(NULL);
//         // sleep(1);
//         // printf("Bye\n");
// 		printf("Parent PID %d\n", getpid());
//         // sleep(1);
// 		// printf("Parent's parent PID %d\n", getppid());
//         printf("Bye");
// 	}

// 	// printf("Exiting with %d\n", getpid());
//     // while(true);
// 	return 0;
// }

// // int main(){
// //     pid_t pid;
// //     pid= fork();
// //     if(pid<0)
// //         printf("Erro in creating fork");
// //     else if(pid==0){
// //         execlp("/bin/ls","ls",NULL);
// //         sleep(1);
// //         printf("Line J");
// //     }
// //     else{
// //         // wait(NULL);
// //         printf("Parent activate, Child complete");
// //     }
// //     return 0;
// // }

// // int main(){
// //     if(fork() && fork()){
// //         printf("Hello\n");
// //     }
// //     sleep(1);
// //     printf("PID = %d , PPID= %d\n",getpid(),getppid());
// //     return 0;
// // }

// // int main(){
// //     pid_t child;
// //     int status, exit_status;
// //     if((child=fork())==0){
// //         sleep(5);
// //         exit(8);
// //     }
// //     wait(&status);
// //     if(WIFEXITED(status)){
// //         exit_status=WEXITSTATUS(status);
// //         printf("Child %d done: %d\n",child,exit_status);
// //     }
// //     return 0;
// // }

// // int main(){
// //     pid_t id1=fork();
// //     pid_t id2=fork();
// //     if(id1>0 && id2>0){
// //         // parent process
// //         wait(NULL);
// //         wait(NULL);
// //         printf("Parent terminated.\n");
// //     }
// //     else if(id1==0 && id2>0){
// //         // 1st child
// //         sleep(2);
// //         wait(NULL);
// //         printf("1st child terminated\n");
// //     }
// //     else if(id1>0 && id2==0){
// //         // 2nd child
// //         sleep(1);
// //         wait(NULL);
// //         printf("2nd child terminated\n");
// //     }
// //     else{
// //         // child of 1st child (Grand Child)
// //         // sleep(1);
// //         printf("Grand Child terminated\n");
// //     }
// //     return 0;

// // }

//replacement and its detection
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // STOP CONDITION (survives exec)
    if (argc > 1 && strcmp(argv[1], "EXECED") == 0) {
        printf("Exec'ed instance detected. PID = %d\n", getpid());
        return 0;
    }

    pid_t p = fork();

    if (p == 0) {
        execlp("./a.out", "a.out", "EXECED", NULL);
        perror("execlp failed");
        exit(1);
    }
    else if (p > 0) {
        wait(NULL);
        printf("Parent exiting. PID = %d\n", getpid());
    }

    return 0;
}
