#include <stdio.h>
#include "list.h"

int main()
{
	int a[] = {4, 1, 5, 2, 3};
	list_t l;
	init(&l);
	for(int i = 0; i < 5; ++i)
	{
		insert(&l, a[i]);
	}
	disp(&l);
	printf("\n-------\n");
	iterator_t it;
	init_iterator(&l, &it);
	while(has_next(&it))
	{
		printf("%d ", next(&it));
	}
}
