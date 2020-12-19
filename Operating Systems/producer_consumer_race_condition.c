#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define BUFF_SIZE 10
#define LOOP_COUNT 100

int buffer[BUFF_SIZE];
int front_pointer = 0, rear_pointer = 0;

void* producer() {

    int item = 0;
    
    // Producing items for LOOP_COUNT times
    for (int i = 0; i < LOOP_COUNT; i++) {
    
        //Producing an item
        item += 1; 
        printf(" Item Produced %d\n", item);
        usleep(1);

        //Waiting until the buffer is full
        while (((front_pointer + 1) % BUFF_SIZE) == rear_pointer); 
        
        // Updating buffer & front_pointer
        buffer[front_pointer] = item;
        front_pointer = (front_pointer + 1) % BUFF_SIZE;
    }    
}

void* consumer() {

    // Consuming items for LOOP_COUNT times
    for (int i = 0; i < LOOP_COUNT; i++) {
    
        // Waiting until buffer is empty   
        while(front_pointer == rear_pointer); 
        
        // Retrieving consumed item
        int consumed_item = buffer[rear_pointer];
        
        // Consuming an item
        printf(" Item Consumed %d\n", consumed_item);
        usleep(1);
        
        // Updating buffer & rear_pointer
        rear_pointer = (rear_pointer + 1) % BUFF_SIZE;
    }    
}


int main() {

    // Initializing producer & consumer threads
    pthread_t ptid, ctid;
    
    // Creating producer & consumer threads
    pthread_create(&ptid, NULL, producer, NULL);
    pthread_create(&ctid, NULL, consumer, NULL);
    
    // Joining producer & consumer threads
    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);
    
    // Exiting
    pthread_exit(NULL);    
    return 0;
}
