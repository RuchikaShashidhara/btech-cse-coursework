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
$ ./a.sh
time 0.014929 
is sorted : 1
# of moves : 3097173
# of comp : 2196081
*/
/*
$ ./b.sh
time 0.014494 
is sorted : 1
$ ./b.sh
time 0.014530 
is sorted : 1
$ ./b.sh
time 0.014521 
is sorted : 1
$ ./b.sh
time 0.014697 
is sorted : 1
$ ./b.sh
time 0.014488 
is sorted : 1
*/

