#include <stdio.h>
#include "rect.h"

int main()
{
	rect_t r;
	printf("size : %ld\n", sizeof(r)); //  32
	init(&r, 20, 10);
	printf("area : %d\n", r.area(&r));
	printf("peri : %d\n", r.peri(&r));
	r.disp(&r);
	//disp(&r); // error
}
