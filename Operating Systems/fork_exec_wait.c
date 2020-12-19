#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[] ) {
	
	char *binaryPath_ls = "/bin/ls";
	char *binaryPath_find = "/usr/bin/find";
	char *currDirPath = ( char * ) malloc (250 * sizeof(char) );
	
	pid_t pid;
	
	getcwd(currDirPath, 250); /* currDirPath stores the current diretcory's path */
	
	pid = fork();
	
	if ( pid == 0 ) {
		/* Child process begins its execution */
		
		if ( argc >= 2 ) {
		
			/* ls is passed as argument */
			if ( strcmp( argv[1], "ls" ) == 0 )
				execl( binaryPath_ls, currDirPath, NULL );	
			/* ls -l is passed as argument */
			else if ( strcmp( argv[1], "ls -l" ) == 0 )
				execl( binaryPath_ls, currDirPath, "-l", NULL );
			
			/* find is passed as argument to print the all the files of type .c in current directory*/
			else if ( strcmp ( argv[1], "find" ) == 0 ) 
				execl( binaryPath_find, "find", currDirPath, "-name", "*.c", NULL );
			
			/* an executable program is passed as argument along with other arguments */
			else {			
				char **execProgArgs = ( char** ) malloc ( argc * 250 * sizeof(char) );
				int i;
				for( i = 1; i < argc; i++ )
					execProgArgs[i - 1] = argv[i];			
				execProgArgs[argc - 1] = NULL;
				execvp( execProgArgs[0], execProgArgs );
			}	
		}
		/* Child process finishes execution */		
	}
	
	else if ( pid > 0 ) {
		/* Parent process begins execution */
		
		printf("Parent Process waiting for Child Process to finish execution...\n\n");
		wait ( NULL );
		printf("\nParent Process is now exiting ...\n");
		
		/* Parent process finishes execution */	
	}	
	
	else {
		/* Creation of Child Process was unsuccessful */
		perror("\nError in fork()\n");
	}
	
	return 0;
}
