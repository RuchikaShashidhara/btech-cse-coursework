#include <stdio.h>
#include "qsort.h"
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}

#if DEBUG
	extern int move_count; 
	extern int comp_count;
#endif

#define SIZE 100000

int main()
{
	int n;
	n = SIZE + 1;
	int a[n + 1];
	fill(a, n);
	
	struct timespec start;
	struct timespec end;
	clock_gettime(CLOCK_REALTIME, &start);	

	myqsort(a, 1, n);

	clock_gettime(CLOCK_REALTIME, &end);	
	printf("time %lf \n",
			   time_elapsed(start, end));  
	
	printf("is sorted : %d\n", is_sorted(a, n));
#if DEBUG
	printf("# of moves : %d\n# of comp : %d\n",
		move_count, comp_count); 
#endif
}
/*
$ gcc -DDEBUG=0 -c client.c
$ gcc -DDEBUG=0 -c qsort.c
$ gcc client.o qsort.o
$ ./a.out
time 0.020015 
is sorted : 1
$ ./a.out
time 0.018569 
is sorted : 1
$ ./a.out
time 0.018829 
is sorted : 1
$ ./a.out
time 0.018404 
is sorted : 1
$ ./a.out
time 0.018706 
is sorted : 1
$ ./a.out
time 0.023675 
is sorted : 1

*/
/*
$ gcc -DDEBUG=1 -c qsort.c
$ gcc -DDEBUG=1 -c client.c
$ gcc client.o qsort.o
$ ./a.out
time 0.020588 
is sorted : 1
# of moves : 1332144
# of comp : 2725819
$ ./a.out
time 0.019137 
is sorted : 1
*/

