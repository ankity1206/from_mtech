#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define M 3
#define N 3
#define P 3

int A[M][N] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

int B[N][P] = {
    {1,0,0},
    {0,1,0},
    {0,0,1}
};

int C[M][P];

void *multiply(void *arg)
{
    int row = *(int*)arg;

    for(int j = 0; j < P; j++)
    {
        C[row][j] = 0;

        for(int k = 0; k < N; k++)
        {
            C[row][j] += A[row][k] * B[k][j];
        }
    }

    pthread_exit(0);
}

double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main()
{
    pthread_t threads[M];
    int row[M];
	double start_time, end_time;
	

    start_time = get_time();

    for(int i = 0; i < M; i++)
    {
        row[i] = i;
        pthread_create(&threads[i], NULL, multiply, &row[i]);
    }

    end_time = get_time();
    printf("Time: %.4f seconds\n\n", end_time - start_time);

    for(int i = 0; i < M; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Result Matrix:\n");

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < P; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
