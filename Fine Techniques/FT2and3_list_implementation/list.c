#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node_t* make_node(int elem)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key = elem;
	temp->next = NULL;
	return temp;
}

void init_list(list_t *ptr_list)
{
	ptr_list->head = NULL;
}

void insert_list(list_t *ptr_list, int elem)
{
	node_t* temp = make_node(elem);
	// in order
	// 1. empty list
	if(ptr_list->head == NULL)
	{
		ptr_list->head = temp; temp->next = NULL;
	}
	else // traverse
	{
		node_t* prev = NULL; node_t* pres = ptr_list->head;
		while(pres != NULL && pres->key < temp->key)
		{
			prev = pres;
			pres = pres->next;
		}
		// 2. beginning
		if(prev == NULL)
		{
			ptr_list->head = temp;
			temp->next = pres;
		}
		else // 3. middle 4. end
		{
			prev->next = temp;
			temp->next = pres;
		}
		
	}
}

void disp_list(const list_t *ptr_list)
{
	node_t *temp = ptr_list->head;
	while(temp)
	{
		printf("%d ", temp->key);
		temp = temp->next;
	}
	printf("\n");
}
