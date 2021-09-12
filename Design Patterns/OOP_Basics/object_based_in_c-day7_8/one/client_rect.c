#include <stdio.h>
#include "rect.h"

int main()
{
	rect_t r;
	printf("size : %ld\n", sizeof(r)); // 8 
	init(&r, 20, 10);
	printf("area : %d\n", area(&r));
	printf("peri : %d\n", peri(&r));
	disp(&r);
	
}
