#include<stdio.h>
#include<stdlib.h>

int main(){
    int c;
    int sum=0;
    while ('\n' !=(c=getchar())){
        // EOF for many lines and \n for one line
        // printf("c is %c\n",c);
        if(c!='\n')
            sum=sum+c-'0';
            // printf("\ncurrent sum is %d\n",sum);
        
        }
    printf("sum of digits is %d",sum);
    int temp;
    while(sum>9){
        int x=0;
        while(sum>0){
            x+=sum%10;
            sum=sum/10;
        }
        sum=x;
    }


    return 0;
}

// int main(){
//     char s,t;
//     scanf("  %c  %c",&s,&t);
//     printf("input is %c and %c",s,t);
//     return 0;

// }