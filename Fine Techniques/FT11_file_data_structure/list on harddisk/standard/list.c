#include <stdio.h>
#include <stdlib.h>
#include "list.h"



void init_list(list_t *ptr_list)
{
	ptr_list->free_head = 0;
	ptr_list->filled_head = -1;
	for(int i = 0; i < MAX - 1; ++i)
	{
		ptr_list->a[i].link = i + 1; 
	}
	ptr_list->a[MAX - 1].link = -1;
}
void disp_list(const list_t *ptr_list)
{
	int temp = ptr_list->filled_head;
	while(temp != -1)
	{
		printf("%d ", ptr_list->a[temp].key);
		temp = ptr_list->a[temp].link;
	}
	printf("\n");
}
void insert_key(list_t *ptr_list, int key)
{
	// get free node
	if(ptr_list->free_head == -1)
	{
		printf("cannot add\n"); exit(1);
	}
	int  temp = ptr_list->free_head;
	ptr_list->free_head = ptr_list->a[ptr_list->free_head].link;


	// populate
	// temp->key = key; temp->link = NULL;
	ptr_list->a[temp].key = key; 

	if(ptr_list->filled_head == -1)
	{
		ptr_list->filled_head = temp;
		ptr_list->a[temp].link = -1;
	}
	else
	{
		int prev = -1; int pres = ptr_list->filled_head;
		while(pres != -1 && ptr_list->a[pres].key < key)
		{
			prev = pres;
			pres = ptr_list->a[pres].link;	
		}
		if(prev == -1)
		{	
			ptr_list->filled_head = temp;
		}
		else
		{
			ptr_list->a[prev].link = temp;
		}
		ptr_list->a[temp].link = pres;
	}



}

void delete_key(list_t *ptr_list, int key)
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













