#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;

void* first(void* arg) {
    printf("First\n");
    sem_post(&s);
    return NULL;
}

void* second(void* arg) {
    sem_wait(&s);
    printf("Second\n");
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&s, 0, 0);

    pthread_create(&t2, NULL, second, NULL);
    pthread_create(&t1, NULL, first, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&s);
    return 0;
}
