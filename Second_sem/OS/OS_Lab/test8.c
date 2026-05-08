#include "common.h"

int main(int ac, char **av){
    float sum=0.0;
    for(int i=1;i<ac;i++){
        sum+=atof(av[i]);
    }
    printf("sum is %f",sum);
    printf("\nmean is %f",sum/(ac-1));
    // printf("\n%f",atof("a")); // any non numrical input is equal to 0 in  atof and atoi
    return 0;
}

// int main(int ac, char **av){
//     char *s;
//     int max=0;
//     for(int i=1;i<ac;i++){
//         if(strlen(av[i])>max){
//             max=strlen(av[i]);
//             s=av[i];
//         }
//     }
//     printf("longest string is %s",s);
//     return 0;
// }