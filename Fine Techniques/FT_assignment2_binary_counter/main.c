#include "assignment_2.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	int *num = (int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++)
	{
		scanf("%d", &num[i]);
	}
	find_second_greatest(num, n);
	return 0;
}
