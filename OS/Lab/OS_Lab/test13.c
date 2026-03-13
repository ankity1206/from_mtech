#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
    int n;
    sleep(3);
    fork();
    printf("enter a number: ");
    scanf("%d",&n);
    sleep(4);
    printf("The number entered is %d",n);
    return 0;
}