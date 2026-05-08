#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t hyd, ox;
int count;
int hid=21,oid=100;
void* hydro(void* arg){
	for(int i=0;i<hid && i<2*oid;i=i+2){
	sem_wait(&hyd);
	printf(" ");
    sem_post(&ox);
	}
	return NULL;

}

void* oxy(void* arg){
	for(int j=0;j<oid && j< hid/2;j++){
	sem_wait(&ox);
	count++;
	sem_post(&hyd);
	}
	return NULL;

}

int main(){
	pthread_t t1,t2;
	sem_init(&hyd,0,1);
	sem_init(&ox,0,0);
	pthread_create(&t2,NULL,hydro,NULL);
	pthread_create(&t1,NULL,oxy,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&hyd);
	sem_destroy(&ox);
	printf("Count: %d\n",count);
	return 0;
}
