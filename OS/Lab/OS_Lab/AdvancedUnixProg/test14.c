// #include "apue.h"
// #include<sys/wait.h>
// int globvar = 6; /* external variable in initialized data */
// char buf[] = "a write to stdout\n";
// int
// main(void)
// {
// int var; /* automatic variable on the stack */
// pid_t pid;
// var = 88;
// // if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
// // err_sys("write error");
// printf("before fork\n"); /* we don’t flush stdout */
// if ((pid = fork()) < 0) {
// // err_sys("fork error");
// } else if (pid == 0) { /* child */
// globvar++; /* modify variables */
// var++;
// } else {
// // sleep(2); /* parent */
// wait(NULL);
// }
// printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,var);
// exit(0);
// }


#include "apue.h"
int globvar = 6; /* external variable in initialized data */
int
main(void)
{
int var; /* automatic variable on the stack */
pid_t pid;
var = 88;
printf("before vfork\n"); /* we don’t flush stdio */
if ((pid = vfork()) < 0) {
// err_sys("vfork error");
} else if (pid == 0) { /* child */
globvar++; /* modify parent’s variables */
var++;
_exit(0); /* child terminates */
}
/* parent continues here */
printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar,var);
exit(0);
}