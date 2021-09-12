#include <stdio.h>
#include "rect.h"

void init(rect_t* ptr_rect, int length, int breadth)
{
	ptr_rect->length = length;
	ptr_rect->breadth = breadth;
}

int area(const rect_t* ptr_rect)
{
	return ptr_rect->length * ptr_rect->breadth;
}

void disp(const rect_t* ptr_rect)
{
	printf("length : %d breadth : %d\n", ptr_rect->length , ptr_rect->breadth);
}

int peri(const rect_t* ptr_rect)
{
	return 2 * (ptr_rect->length + ptr_rect->breadth);
}



