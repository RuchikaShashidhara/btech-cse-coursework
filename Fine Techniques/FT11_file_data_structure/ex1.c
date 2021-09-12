#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	// cannot create a file using r+
	fp = fopen("test.dat", "r+");
	if(fp == NULL)
	{
		printf("opening file failed\n");
	}
	else
	{
		printf("opening file succeeded\n");
		fclose(fp);
	}
}
