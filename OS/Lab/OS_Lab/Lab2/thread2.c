#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* printA(void* arg)
{
    char *msg = "OperatingSystems\n";

    for(int i = 0; msg[i] != '\0'; i++)
    {
        printf("%c", msg[i]);
        fflush(stdout);
        usleep(10000);   // slow down printing
    }
    return NULL;
}

void* printB(void* arg)
{
    char *msg = "ConcurrencyControl\n";

    for(int i = 0; msg[i] != '\0'; i++)
    {
        printf("%c", msg[i]);
        fflush(stdout);
        usleep(10000);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, printA, NULL);
    pthread_create(&t2, NULL, printB, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
