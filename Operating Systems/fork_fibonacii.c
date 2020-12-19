#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, char *argv[]) {

	long int f1 = -1, f2 = 1, fn;	/* fn ==> nth fibonaccii number */
	pid_t pid;	

	if ( argc == 2 ) {		
		/* Program is executed only if one number as an argument is passed */
		int num = atoi( argv[1] );
		
		pid = fork();

		if ( pid == 0 ) {	
			/* Child Process starts execution to print first n elements of the fibonaccii series*/			
			while( num-- > 0 ) {
				fn = f1 + f2;
				printf( "%ld ", fn );				
				f1 = f2;
				f2 = fn;
			}
			printf( "\n" );			
			/* Child process finishes execution */	
		}  

		else if ( pid > 0 ) {
			/* Parent process waits for Child Process to complete */
			wait( NULL );
			/* Parent process finishes execution */		
		}
		
		else {
			/* Creation of Child Process was unsuccessful */
			perror( "\nError in fork()\n" );
		}
	}
	
	return 0;
}	
