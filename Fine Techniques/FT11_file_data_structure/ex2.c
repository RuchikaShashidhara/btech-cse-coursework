#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fp;
	// cannot create a file using r+
	fp = fopen("test.dat", "r+");
	if(fp == NULL)
	{
		printf("opening file failed for r+\n");
		fp = fopen("test.dat", "w+");
		if(fp == NULL)
		{
			printf("opening failed for w\n");
		}
		else
		{
			printf("opening file succeeded for w\n");
		}
	}
	else
	{
		printf("opening file succeeded for r+\n");
		fclose(fp);
	}
}
