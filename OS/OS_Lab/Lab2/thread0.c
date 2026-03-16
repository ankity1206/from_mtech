#include <stdio.h>
#include <pthread.h>

int x = 10;

void* increment(void* arg)
{
	int sum;
	int *val = (int *)(arg);
	sum = x + *val;

	printf ("%d\n", sum);
    return NULL;
}

int main()
{
    pthread_t t1, t2;
	int a = 10, b = 20;

    pthread_create(&t1, NULL, increment, &a);
    pthread_create(&t2, NULL, increment, &b);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", x);

    return 0;
}
