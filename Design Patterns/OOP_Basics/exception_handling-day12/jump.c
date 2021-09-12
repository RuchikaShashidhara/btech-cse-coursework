#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
jmp_buf b;
void bar()
{
	printf("bar start\n");
	longjmp(b, 2); // acts like throw
	printf("bar end\n");
}
void foo()
{	
	printf("foo start\n");
	bar();
	printf("foo end\n");
}
int main()
{
	int opt;
	if((opt = setjmp(b)) == 0)
	{
		printf("buffer set\n");
		foo();
	}
	#if 1
	switch(opt) // acts catch blocks 
	{
		case 1 : printf("one\n"); break;
		case 2 : printf("two\n"); break;
	}
	#endif
}
