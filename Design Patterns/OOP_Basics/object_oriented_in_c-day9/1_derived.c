#include <stdio.h>
#include "1_derived.h"
// struct B :
//	foo : modified : overridden
//	bar : not changed; should use the function of  struct A

static void foo_B()
{
	printf("foo B called\n");
}



static vtbl_B_t vtbl_B;


void init_B(B_t *p, int a1, int a2, int b1, int b2)
{
	p->ptr = &vtbl_B;
	init_A(&p->base, a1, a2);
	
	p->ptr->foo = foo_B;
	p->ptr->bar = p->base.ptr->bar;
	
	p->b1 = b1;
	p->b2 = b2;
}




