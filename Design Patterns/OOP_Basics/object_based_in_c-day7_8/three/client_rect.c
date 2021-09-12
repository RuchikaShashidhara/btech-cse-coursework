#include <stdio.h>
#include "rect.h"

int main()
{
	rect_t r;
	printf("size : %ld\n", sizeof(r)); //  32
	init(&r, 20, 10);
	printf("area : %d\n", r.ptr_vtbl->area(&r));
	printf("peri : %d\n", r.ptr_vtbl->peri(&r));
	r.ptr_vtbl->disp(&r);
	//disp(&r); // error
}
