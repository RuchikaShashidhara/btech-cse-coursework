#include <stdio.h>
#include "ex1.h"

int cube(int x)
{
#if 1
	int res = x * x * x;
	printf("\ninside #if\n");
	return res;
#endif
	return x * x * x;
}
