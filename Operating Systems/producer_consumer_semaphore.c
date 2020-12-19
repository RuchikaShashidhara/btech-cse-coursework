#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <semaphore.h>

#define BUFF_SIZE 5
int buff[BUFF_SIZE];
int produced_item = 0;
int consumed_item = 0;

sem_t empty, full, signal;

void *producer(void *num) {

	for(int i = 1; i <= 2*BUFF_SIZE; ++i) {
	
		sem_wait(&empty);
		sem_wait(&signal);
		
		buff[produced_item] = i*10;
		produced_item = (produced_item + 1) % BUFF_SIZE;
		printf(" Produced item is %d\n", i);
		
		sem_post(&signal);
		sem_post(&full);	
	}
	exit(0);
}

void *consumer(void *num) {

	for(int i = 1; i <= 2*BUFF_SIZE; ++i) {
	
		sem_wait(&full);
		sem_wait(&signal);
		
		int item = buff[consumed_item];
		consumed_item = (consumed_item + 1) % BUFF_SIZE;
		printf(" Consumed item is %d\n", i);
		
		sem_post(&signal);
		sem_post(&empty);	
	}
	exit(0);
}

int main() {

	sem_init(&empty, 0, BUFF_SIZE);
	sem_init(&full, 0, 0);
	sem_init(&signal, 0, 1);
	
	pthread_t ptid, ctid;
	
	pthread_create(&ptid, NULL, (void *)producer, NULL);
	pthread_create(&ctid, NULL, (void *)consumer, NULL);	
	
	pthread_join(ptid, NULL);
	pthread_join(ctid, NULL);
	
	return 0;
}
