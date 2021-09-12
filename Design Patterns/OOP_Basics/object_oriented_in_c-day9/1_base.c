#include <stdio.h>
#include "1_base.h"

static void foo_A()
{
	printf("foo A called\n");
}

static void bar_A()
{
	printf("bar A called\n");
}

static vtbl_A_t vtbl_A =
{
	foo_A,
	bar_A
};

void init_A(A_t *p, int a1, int a2)
{
	p->ptr = &vtbl_A;
	p->a1 = a1;
	p->a2 = a2;
}



