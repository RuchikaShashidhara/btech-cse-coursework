#include <stdio.h>
#include <stdlib.h>
#include "person3.h"
#include "file3.h"

FILE* open_file(const char* fname)
{
	FILE* fp;
	fp = fopen(fname, "r+");
	if(fp == NULL)
	{
		printf("opening file failed for r+\n");
		fp = fopen(fname, "w+");
		if(fp == NULL)
		{
			printf("fatal: cannot open file\n");
			exit(1);
		}
	}
	return fp;
}

void close_file(FILE *fp)
{
	fclose(fp);
}
void write_file(FILE *fp, const person_t *ptr_person)
{
	fwrite(ptr_person, size, 1, fp);
}
void read_file(FILE *fp, person_t *ptr_person)
{
	fread(ptr_person, size, 1, fp);
}
void seek_file(FILE *fp, long offset)
{
	fseek(fp, (offset - 1) * size, SEEK_SET);

}
