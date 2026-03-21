#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int counter=0;
sem_t mutex;
void* increment(void* arg){
	for(int i=0;i<100000;i++){
		sem_wait(&mutex);
		counter++;
		sem_post(&mutex);
	}
	return NULL;
}

int main(){
	pthread_t t1,t2;
	sem_init(&mutex,0,1);
	pthread_create(&t1,NULL,increment,NULL);
	pthread_create(&t2,NULL,increment,NULL);
	pthread_join(t1,NULL);
	//pthread_create(&t2,NULL,increment,NULL);	
	pthread_join(t2,NULL);
	printf("Result: %d",counter);
}
