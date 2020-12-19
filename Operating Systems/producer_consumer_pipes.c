#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int data[2];

void producer() {

	for(int i = 1; i <= 10; ++i) {
		close(data[0]);
		int item = i;		
		write(data[1], &item, sizeof(int));
		printf(" Producer sent: %d\n", item);	
	}
}

void consumer() {

	for(int i = 1; i <= 10; ++i) {
		close(data[1]);
		int item;
		read(data[0], &item, sizeof(int));
		printf(" Consumer got:  %d\n", item);	
	}
}

int main() {
	pipe(data);
	
	pid_t pipeid;
	pipeid = fork();
	
	if(pipeid == 0) 
	        consumer();
	        
	else if(pipeid > 0) {
		producer();
		wait(NULL);
	}
	
	return 0;
}
