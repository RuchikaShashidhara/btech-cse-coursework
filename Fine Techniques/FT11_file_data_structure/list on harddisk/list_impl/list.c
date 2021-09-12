#include <stdio.h>
#include <stdlib.h>
#include "list.h"

FILE *init_list(list_t *ptr_list, const char* name)
{
	FILE* fp = fopen(name, "r+");
	if(fp == NULL)
	{
		printf("empty file\n");
		fp = fopen(name, "w");
		ptr_list->free_head = -1;
		ptr_list->filled_head = -1;
		fwrite(ptr_list, sizeof(list_t), 1, fp);
		fclose(fp);
		fp = fopen(name, "r+");
	}
	fread(ptr_list, sizeof(list_t), 1, fp);
	return fp;
}

void close_list(list_t *ptr_list, FILE *fp)
{
	fclose(fp);
}

void disp_list(const list_t *ptr_list, FILE *fp)
{
	node_t temp;
	int off = ptr_list->filled_head;
	while(off != -1)
	{
		fseek(fp, off, SEEK_SET);
		fread(&temp, sizeof(node_t), 1, fp);
		printf("%d ", temp.key);
		off = temp.link;
	}
	printf("\n");
}
void insert_key(list_t *ptr_list, int key, FILE *fp)
{
	int off;
	
	node_t temp_node;
	int temp;
	if(ptr_list->free_head == -1)
	{
		fseek(fp, 0, SEEK_END); // seek to the end
		temp = ftell(fp);
		printf("off1 : %d\n", temp);
		
	}
	else
	{
		temp = ptr_list->free_head;
		fseek(fp, temp, SEEK_SET);
		printf("off2 : %d\n", temp);
		fread(&temp_node, sizeof(node_t), 1, fp);
		ptr_list->free_head = temp_node.link;
	}

	temp_node.key = key;
	temp_node.link = -1;
	if(ptr_list->filled_head == -1)
	{
		ptr_list->filled_head = temp;
		temp_node.link = -1;
		fseek(fp, 0, SEEK_SET); fwrite(ptr_list, sizeof(list_t), 1, fp);
		fseek(fp, temp, SEEK_SET); fwrite(&temp_node, sizeof(node_t), 1, fp);
	}
	else
	{
		int prev = -1; int pres = ptr_list->filled_head;
		// read the pres node
		node_t pres_node; node_t prev_node;
		fseek(fp, pres, SEEK_SET);
		fread(&pres_node, sizeof(node_t), 1, fp);
		
		while(pres != -1 && pres_node.key < key)
		{
			prev = pres;
			prev_node = pres_node;
			pres = pres_node.link;
			if(pres != -1)
			{	
				fseek(fp, pres, SEEK_SET);
				fread(&pres_node, sizeof(node_t), 1, fp);
			}
		}
		if(prev == -1)
		{	
			ptr_list->filled_head = temp;
			temp_node.link = pres;
		}
		else
		{
			prev_node.link = temp;
			temp_node.link = pres;
			fseek(fp, prev, SEEK_SET); fwrite(&prev_node, sizeof(node_t), 1, fp);
		}

		fseek(fp, 0, SEEK_SET); fwrite(ptr_list, sizeof(list_t), 1, fp);
		fseek(fp, temp, SEEK_SET); fwrite(&temp_node, sizeof(node_t), 1, fp);
	}



}
void delete_key(list_t *ptr_list, int key, FILE *fp)
{
	if(ptr_list->filled_head == -1)
	{
		printf("empty list; cannot delete\n");		
	}
	else
	{
		// locate
		int prev = -1; int pres = ptr_list->filled_head;
		node_t pres_node; node_t prev_node;
		fseek(fp, pres, SEEK_SET);
		fread(&pres_node, sizeof(node_t), 1, fp);
		while(pres != -1 && pres_node.key < key)
		{
			prev = pres;
			prev_node = pres_node;
			pres = pres_node.link;
			if(pres != -1)
			{	
				fseek(fp, pres, SEEK_SET);
				fread(&pres_node, sizeof(node_t), 1, fp);
			}
		}
		if(pres != -1 && pres_node.key == key) // found
		{
			if(prev == -1) // beginning
			{
				ptr_list->filled_head = pres_node.link;
			}
			else // anywhere else
			{
				prev_node.link = pres_node.link;
				fseek(fp, prev, SEEK_SET); fwrite(&prev_node, sizeof(node_t), 1, fp);
			}
			pres_node.link = ptr_list->free_head;
			ptr_list->free_head = pres;
			fseek(fp, 0, SEEK_SET); fwrite(ptr_list, sizeof(list_t), 1, fp);
			fseek(fp, pres, SEEK_SET); fwrite(&pres_node, sizeof(node_t), 1, fp);

		}
	}
}
/*
void delete_key(list_t *ptr_list, int key, FILE *fp)
{
	int pres = ptr_list->filled_head;
	int prev = -1;
	while(pres != -1 && ptr_list->a[pres].key != key)
	{
		prev = pres;
		pres = ptr_list->a[pres].link;
	}
	if(pres == -1)
	{
		printf("key %d not found\n", key);
	}
	else if(prev != -1)
	{
		ptr_list->a[prev].link = ptr_list->a[pres].link;
	}
	else
	{
		ptr_list->filled_head = ptr_list->a[pres].link;
	}
	//free(pres);
	// add in the beginning of free list
	ptr_list->a[pres].link = ptr_list->free_head;
	ptr_list->free_head = pres; 

}
*/











