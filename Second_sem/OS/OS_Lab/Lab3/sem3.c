#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <unistd.h>

#define ITER 100000

// semaphore operations
void wait_sem(int semid) {
    struct sembuf op = {0, -1, 0};
    semop(semid, &op, 1);
}

void signal_sem(int semid) {
    struct sembuf op = {0, 1, 0};
    semop(semid, &op, 1);
}

int main() {
    key_t key = ftok("file", 65);

    // Shared memory
    int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    int *counter = (int*) shmat(shmid, NULL, 0);
    *counter = 0;

    // Semaphore
    int semid = semget(key, 1, 0666 | IPC_CREAT);

    // Initialize semaphore to 1
    semctl(semid, 0, SETVAL, 1);

    if (fork() == 0) {
        // Child process
        for(int i = 0; i < ITER; i++) {
            wait_sem(semid);
            (*counter)++;
            signal_sem(semid);
        }
        exit(0);
    } else {
        // Parent process
        for(int i = 0; i < ITER; i++) {
            wait_sem(semid);
            (*counter)++;
            signal_sem(semid);
        }

        wait(NULL);

        printf("Final counter = %d\n", *counter);

        // Cleanup
        shmctl(shmid, IPC_RMID, NULL);
        semctl(semid, 0, IPC_RMID);
    }

    return 0;
}
