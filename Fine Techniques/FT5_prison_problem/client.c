#include <stdio.h>
#include "prison1.h"

int main()
{
	prison_t p; int n;
	scanf("%d", &n);
	init_prison(&p, n);
	open_close(&p);
	disp_open(&p);
}
