#include <stdio.h>
#include "2_foo.h"

int main()
{
	printf("one\n");
	foo();
	printf("two\n");
}
/*
$ gcc -c -Dfoo=bar 2_client.c
// hijacked the function foo and replaced by bar
$ nm 2_client.o
                 U bar
                 U _GLOBAL_OFFSET_TABLE_
0000000000000000 T main
                 U puts
$ gcc 2_client.o 2_bar.o
$ ./a.out
one
bar called
two
*/

// 1. make memory allocation and deallocation safe
// 2. profiling
// 3. time a function


