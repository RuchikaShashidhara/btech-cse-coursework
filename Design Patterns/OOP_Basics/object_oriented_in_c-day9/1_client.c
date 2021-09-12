#include <stdio.h>
#include <stdlib.h>
#include "1_base.h"
#include "1_derived.h"


int main()
{
	A_t *p;
	p = (A_t*)malloc(sizeof(A_t));
	init_A(p, 10, 20);
	p->ptr->foo();
	p->ptr->bar();
	
	A_t *q;
	q = (A_t*)malloc(sizeof(B_t));
	init_B((B_t*)q, 10, 20, 30, 40);
	q->ptr->foo();
	q->ptr->bar();
}
