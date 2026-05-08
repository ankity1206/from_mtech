#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int Colsign=1,Rowsign=1,sub_grid_sign=1;
int Mat[9][9] = {
    {3, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};

typedef struct{
    int row;
    int col;
}params;

void *col_check(void *arg){
    for(int j=0;j<9;j++){
        int freq[9]={0};
        for(int i=0;i<9;i++){
            freq[Mat[i][j]-1]++;
        }
        for(int i=0;i<9;i++){
            if(freq[i]==0){
               Colsign=0;
                pthread_exit(0);
            }
        }
    }
    pthread_exit(0);
}

void *row_check(void *arg){
    for(int i=0;i<9;i++){
        int freq[9]={0};
        for(int j=0;j<9;j++){
            freq[Mat[i][j]-1]++;
        }
        for(int j=0;j<9;j++){
            if(freq[j]==0){
               Rowsign=0;
                pthread_exit(0);
            }
        }
    }
    pthread_exit(0);
}

void *sub_grid_check(void *arg){
    int freq[9]={0};
    int row=((params*)arg)->row;
    int col=((params*)arg)->col;
    for(int i=row;i<row+3;i++){
        for(int j=col;j<col+3;j++){
            freq[Mat[i][j]-1]++;
        }
    }
    for(int j=0;j<9;j++){
        if(freq[j]==0){
            sub_grid_sign=0;
            free(arg);
            pthread_exit(0);
        }
    }
    free(arg);
    pthread_exit(0);
}

int main(int argc, char* arg[]){
    pthread_t t1,t2;
    pthread_create(&t1, NULL, row_check, NULL);
    pthread_create(&t2, NULL, col_check, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("row check: %d\t col check:%d\n",Rowsign,Colsign);
    //params *data = (params*) malloc(sizeof(params));
    pthread_t threads[9];
    int k=0;
    for(int i=0;i<9;i=i+3){
        for(int j=0;j<9;j=j+3){
            params *data=(params*)malloc(sizeof(params));
            data->row=i;
            data->col=j;
            pthread_create(&threads[k++],NULL,sub_grid_check,data);
        }
       // free(data);
    }
    for(int i=0;i<9;i++){
        pthread_join(threads[i], NULL);
    }
    printf("subgrid check:\t%d\n",sub_grid_sign);
}
