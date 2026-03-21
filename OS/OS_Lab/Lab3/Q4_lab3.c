#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t odd_sem, even_sem;
int bound=10;
void* odd(void* arg){
	for(int i=1;i<bound;i=i+2){
	sem_wait(&odd_sem);
	printf("%d\t",i);
	sem_post(&even_sem);
	}
	return NULL;

}

void* even(void* arg){
	for(int j=2;j<bound+1;j=j+2){
	sem_wait(&even_sem);
	printf("%d\t",j);
	sem_post(&odd_sem);
	}
	return NULL;

}

int main(){
	pthread_t t1,t2;
	sem_init(&odd_sem,0,1);
	sem_init(&even_sem,0,0);
	pthread_create(&t2,NULL,odd,NULL);
	pthread_create(&t1,NULL,even,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&odd_sem);
	sem_destroy(&even_sem);
	return 0;
}
