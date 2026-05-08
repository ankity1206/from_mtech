#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t mutex;
void* first(void* arg){
	//sem_wait(&mutex);
	printf("First\n");
	sem_post(&mutex);
	return NULL;
}

void* second(void* arg){
	sem_wait(&mutex);
	printf("Second\n");
	sem_post(&mutex);
	return NULL;
}

int main(){
	pthread_t t1,t2;
	sem_init(&mutex,0,1);
	pthread_create(&t2,NULL,second,NULL);
	pthread_create(&t1,NULL,first,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&mutex);
	return 0;
}
