#include <stdio.h>
#include <stdlib.h>

void bar()
{
	printf("begin bar\n");
	exit(1);
	printf("end bar\n");
}

void foo()
{
	printf("begin foo\n");
	bar();
	printf("end foo\n");
}
void clean1()
{
	printf("cleaning 1\n");
}
void clean2()
{
	printf("cleaning 2\n");
}
int main()
{
	atexit(clean1);
	atexit(clean2);
	
	printf("one\n");
	foo();
	printf("two\n");
}
