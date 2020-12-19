#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main() {

        int arr_size = 5;
        int *arr = ( int* ) malloc ( arr_size * sizeof(int) );
	int *partialSums = ( int* ) malloc ( arr_size * sizeof(int) );
	int *partialProducts = ( int* ) malloc ( arr_size * sizeof(int) );
	
	pid_t pid;
	
	int i;
	for( i = 0; i < arr_size; i++ )
		arr[i] = i + 1;	
		
	pid = fork();

	if ( pid == 0 ) {	
		/* Child Process starts execution to compute Partial Sums*/		
		for ( i = 0; i < arr_size; i++ ) {
			if ( i == 0 )
				partialSums[i] = 0 + arr[i];
			else
				partialSums[i] = partialSums[i - 1] + arr[i];
		}
		printf( "Total Sum = %d\n", partialSums[arr_size - 1]) ;	
		/* Child process finishes execution */	
	}  

	else if ( pid > 0 ) {
		/* Parent process starts execution to compute Partial Products */	
		for ( i = 0; i < arr_size; i++ ) {
			if ( i == 0 )
				partialProducts[i] = 1 * arr[i];
			else
				partialProducts[i] = partialProducts[i - 1] * arr[i];
		}
		
		/* Parent process waits for Child Process to complete */
		wait( NULL );	
			
		printf( "Total Product = %d\n", partialProducts[arr_size - 1] );
		/* Parent process finishes execution */		
	}
	
	else {
		/* Creation of Child Process was unsuccessful */
		perror("\nError in fork()\n");
	}
	
	return 0;
}	
