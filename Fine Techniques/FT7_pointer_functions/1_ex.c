#include <stdio.h>

#define ptr int*
typedef int* ptr_t;

int foo(int x)
{
	printf("foo called\n");
	return x * x;
}

int main()
{
//	int* p, q; // p is a pointer to int, q is an int
//	do not declare more than one variable in a single statement

	// ptr p, q; // no change!!
	// pre-processor is dumb; does textual substitution
	
	ptr_t p, q; // p, q : pointers
	
	int res = foo(10); printf("res : %d\n", res);
	
	int (*bar)(int) = foo;
	res = (*bar)(20); printf("res : %d\n", res);
	res = bar(20); printf("res : %d\n", res);
}

// int *p1;
// int **p2;
// int *p3[5];
// int (*p4)[5];
// int p5(int);
// int (*p6)(int);
// int* (*p7)(int*, int*);
// int (*p8[5])(int, int);


