#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t s;

void* worker(void* arg) {
    int id = *(int*)arg;

    sem_wait(&s);
    printf("Thread %d entering\n", id);

    sleep(1);

    printf("Thread %d leaving\n", id);
    sem_post(&s);

    return NULL;
}

int main() {
    pthread_t t[10];
    int ids[10];

    sem_init(&s, 0, 3);

    for(int i = 0; i < 10; i++) {
        ids[i] = i;
        pthread_create(&t[i], NULL, worker, &ids[i]);
    }

    for(int i = 0; i < 10; i++)
        pthread_join(t[i], NULL);

    sem_destroy(&s);
    return 0;
}
