#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void init_list(list_t *ptr_list)
{
	ptr_list->head_filled = -1;
	ptr_list->head_free = 0;
	for(int i = 0; i < MAX - 1; ++i)
	{
		ptr_list->a[i].link = i + 1;
	}
	ptr_list->a[MAX - 1].link = -1;
}

void disp_list(const list_t *ptr_list)
{
	int temp = ptr_list->head_filled;
	while(temp != -1)
	{
		printf("%d ", ptr_list->a[temp].key);
		temp = ptr_list->a[temp].link;
	}
	printf("\n");
}

void insert(list_t *ptr_list, int key)
{
	// pickup the node from the freelist
	int temp = ptr_list->head_free;
	// remove the node from the freelist
	ptr_list->head_free = ptr_list->a[temp].link;
	
	// populate the node
	ptr_list->a[temp].key = key;
	ptr_list->a[temp].link = -1;
	
	
	if(ptr_list->head_filled == -1) // empty list
	{
		ptr_list->head_filled = temp;
	}
	else
	{
		int prev = -1; int pres = ptr_list->head_filled;
		while(pres != -1 && ptr_list->a[pres].key < key)
		{
			prev = pres;
			pres = ptr_list->a[pres].link;
		}
		// middle or end
		if(prev != -1)
		{
			ptr_list->a[prev].link = temp; // prev->link = temp;
			ptr_list->a[temp].link = pres; // temp->link = pres;
		}
		else
		{
			ptr_list->head_filled = temp;
			ptr_list->a[temp].link = pres; // temp->link = pres;
		}
	}
}

void delete(list_t *ptr_list, int key)
{
	if(ptr_list->head_filled == -1)
	{
		printf("empty list; cannot delete\n");
	}
	else
	{
		int prev = -1; int pres = ptr_list->head_filled;
		while(pres != -1 && ptr_list->a[pres].key != key)
		{
			prev = pres;
			pres = ptr_list->a[pres].link;
		}
	
		if(pres == -1)
		{
			printf("not found\n");
		}
		else if(prev == -1)
		{
			//ptr_list->head = pres->link;
			ptr_list->head_filled = ptr_list->a[pres].link;
			
			// add to free list
			ptr_list->a[pres].link = ptr_list->head_free;
			ptr_list->head_free = pres;
		} 
		else
		{
			//prev->link = pres->link;
			ptr_list->a[prev].link = ptr_list->a[pres].link;
			 
			// add to free list
			ptr_list->a[pres].link = ptr_list->head_free;
			ptr_list->head_free = pres;

		}
	}
}
			



