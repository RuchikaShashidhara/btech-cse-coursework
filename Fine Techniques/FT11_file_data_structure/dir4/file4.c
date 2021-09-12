#include <stdio.h>
#include <stdlib.h>
#include "person4.h"
#include "file4.h"
void init_header(FILE *fp)
{
	header_t h;
	for(int i = 1; i <= MAX; ++i)
	{
		h.pos[i] = 0;
	}
	fwrite(&h, sizeof(header_t), 1, fp);
	
}
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
		init_header(fp);
	}
	return fp;
}

void close_file(FILE *fp)
{
	fclose(fp);
}
void write_file(FILE *fp, const person_t *ptr_person, int pos)
{
	header_t h;
	fseek(fp, 0, SEEK_SET);
	fread(&h, sizeof(header_t), 1, fp);
	h.pos[pos] = pos;
	fseek(fp, 0, SEEK_SET);
	fwrite(&h, sizeof(header_t), 1, fp);
	
	fseek(fp, sizeof(header_t) + (pos - 1) * size , SEEK_SET);	
	fwrite(ptr_person, size, 1, fp);
}
void read_file(FILE *fp, person_t *ptr_person, int pos)
{
	header_t h;
	fseek(fp, 0, SEEK_SET);
	fread(&h, sizeof(header_t), 1, fp);
	if(h.pos[pos] != 0)
	{
		fseek(fp, sizeof(header_t) + (pos - 1) * size , 					SEEK_SET);	
		fread(ptr_person, size, 1, fp);
	}
	else
	{
		printf("no record at that position\n");
	}
}
void disp_all(FILE *fp)
{
	header_t h;
	person_t x;
	fseek(fp, 0, SEEK_SET);
	fread(&h, sizeof(header_t), 1, fp);
	for(int pos = 1; pos <= MAX; ++pos)
	{
		if(h.pos[pos] != 0)
		{
			fseek(fp, sizeof(header_t) + (pos - 1) * size , 					SEEK_SET);	
			fread(&x, size, 1, fp);
			disp_person(&x);
		}
	}
}

