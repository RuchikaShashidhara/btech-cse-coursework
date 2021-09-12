#include <stdio.h>
#include "qsort.h"
#if DEBUG
	extern int move_count; 
	extern int comp_count;
#endif

#define SIZE 100 

int main()
{
	int n;
	n = SIZE + 1;
	int a[n + 1];
	fill(a, n);
	myqsort(a, 1, n);
	printf("is sorted : %d\n", is_sorted(a, n));
#if DEBUG
	printf("# of moves : %d\n# of comp : %d\n",
		move_count, comp_count); 
#endif
}

/*
// DEBUG is 1
$ gcc -DDEBUG=1 -c client.c
$ gcc -DDEBUG=1 -c qsort.c
$ gcc client.o qsort.o
$ ./a.out
is sorted : 1
# of moves : 849
# of comp : 831
*/
/*
// DEBUG is 0
$ gcc -DDEBUG=0 -c client.c
$ gcc -DDEBUG=0 -c qsort.c
$ gcc client.o qsort.o
$ ./a.out
is sorted : 1
*/
