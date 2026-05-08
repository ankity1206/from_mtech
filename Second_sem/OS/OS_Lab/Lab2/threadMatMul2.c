#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define N 600

int A[N][N], B[N][N], C[N][N];

typedef struct {
    int start;
    int end;
} range;

void *parallel_multiply(void *arg)
{
    range *r = (range*)arg;

    for(int i = r->start; i < r->end; i++)
        for(int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    pthread_exit(NULL);
}

double time_diff(struct timeval start, struct timeval end)
{
    return (end.tv_sec - start.tv_sec) +
           (end.tv_usec - start.tv_usec)/1000000.0;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    int THREADS = atoi(argv[1]);

    pthread_t threads[THREADS];
    range args[THREADS];

    struct timeval start, end;

    /* initialize matrices */
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }

    /* Sequential multiplication */
    gettimeofday(&start,NULL);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            C[i][j] = 0;
            for(int k=0;k<N;k++)
                C[i][j] += A[i][k]*B[k][j];
        }

    gettimeofday(&end,NULL);

    double seq_time = time_diff(start,end);

    //printf("Sequential Time: %f seconds\n",seq_time);

    /* Parallel multiplication */

    gettimeofday(&start,NULL);

    int rows_per_thread = N/THREADS;

    for(int t=0;t<THREADS;t++)
    {
        args[t].start = t*rows_per_thread;
        args[t].end = (t==THREADS-1)?N:(t+1)*rows_per_thread;

        pthread_create(&threads[t],NULL,
                       parallel_multiply,&args[t]);
    }

    for(int t=0;t<THREADS;t++)
        pthread_join(threads[t],NULL);

    gettimeofday(&end,NULL);

    double par_time = time_diff(start,end);

    printf("Parallel Time: %f seconds\n",par_time);

    double speedup = seq_time/par_time;
    double efficiency = speedup/THREADS;

    printf("Threads: %d\n",THREADS);
    // printf("Speedup: %f\n",speedup);
    //printf("Efficiency: %f\n",efficiency);

    return 0;
}
