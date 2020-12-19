#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

#define BUFF_SIZE 10
#define LOOP_COUNT 100

int buffer[BUFF_SIZE];
int front_pointer = 0, rear_pointer = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t empty = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t full = PTHREAD_MUTEX_INITIALIZER;

void* producer() {

    int item = 0;
    
    // Producing items for LOOP_COUNT times
    for(int i = 0; i < LOOP_COUNT; i++) {
        
        // Locking Mutexes
        pthread_mutex_lock(&empty);
        pthread_mutex_lock(&mutex);
        
        // Producing an item
        item += 1; 
        printf(" Item Produced %d\n", item);
        usleep(1);
        
        // Updating buffer
        buffer[front_pointer] = item;
        
        // Updating front_pointer
        front_pointer = (front_pointer + 1) % BUFF_SIZE;
        
        // Unlocking mutexes
        pthread_mutex_unlock(&mutex);
        pthread_mutex_unlock(&full);       
    }
}

void* consumer() {
    
    // Consuming items for LOOP_COUNT times
    for(int i = 0; i < LOOP_COUNT; i++) {

        // Locking Mutexes
        pthread_mutex_lock(&full);
        pthread_mutex_lock(&mutex);

        // Retrieving consumed item
        int consumed = buffer[rear_pointer];
        
        // Consuming an item
        printf(" Item Consumed %d\n", consumed);
        usleep(1);
        
        // Updating rear_pointer
        rear_pointer = (rear_pointer + 1) % BUFF_SIZE;
        
        // Unlocking mutexes
        pthread_mutex_unlock(&mutex);
        pthread_mutex_unlock(&empty);
    }
}


int main() {

    // Initializing producer & consumer threads and buffer
    memset(buffer, 0, BUFF_SIZE*sizeof(int));
    pthread_t ptid, ctid;
    
    // Creating producer & consumer threads
    pthread_create(&ptid, NULL, producer, NULL);
    usleep(1);
    pthread_create(&ctid, NULL, consumer, NULL);
    
    // Joining producer & consumer threads
    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);
    
    // Exiting
    pthread_exit(NULL);
    return 0;
}
