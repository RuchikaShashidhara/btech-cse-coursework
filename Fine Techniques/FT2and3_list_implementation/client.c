#include <stdio.h>
// avoid the problem of multiple inclusion at compile time
#include "list.h"
#include "list.h"

int main()
{
	list_t l;
	init_list(&l);
	int a[] = {25, 15, 35, 5, 45};
	int n = 5;
	for(int i = 0; i < n; ++i)
	{
		insert_list(&l, a[i]);
	}
	disp_list(&l);
}
