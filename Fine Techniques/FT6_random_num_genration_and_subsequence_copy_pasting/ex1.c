#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n = 5;
	srand(time(0));
	for(int i = 0; i < n; ++i)
	{
		printf("%d ", rand() % 100);
	}
	printf("\n");
}
