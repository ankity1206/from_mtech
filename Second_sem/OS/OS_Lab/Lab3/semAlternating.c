#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t odd_sem, even_sem;

void* odd(void* arg) {
    for(int i = 1; i <= 9; i += 2) {
        sem_wait(&odd_sem);
        printf("T1: %d ", i);
        sem_post(&even_sem);
    }
    return NULL;
}

void* even(void* arg) {
    for(int i = 2; i <= 10; i += 2) {
        sem_wait(&even_sem);
        printf("T2: %d ", i);
        sem_post(&odd_sem);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&odd_sem, 0, 1);
    sem_init(&even_sem, 0, 0);

    pthread_create(&t1, NULL, odd, NULL);
    pthread_create(&t2, NULL, even, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&odd_sem);
    sem_destroy(&even_sem);

    return 0;
}
