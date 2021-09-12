#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void init_list(list_t *ptr_list)
{
	ptr_list->head = NULL;
}

void disp_list(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		printf("%d ", temp->key);
		temp = temp->link;
	}
	printf("\n");
}
node_t* create_node(int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key = key;
	temp->link = NULL;
	return temp;
}
// ordered list
void insert(list_t *ptr_list, int key)
{
	node_t* temp = create_node(key);
	if(ptr_list->head == NULL) // empty list
	{
		ptr_list->head = temp;
	}
	else
	{
		node_t *prev = NULL; node_t *pres = ptr_list->head;
		while(pres != NULL && pres->key != temp->key)
		{
			prev = pres;
			pres = pres->link;
		}
		// middle or end
		if(prev != NULL)
		{
			prev->link = temp;
			temp->link = pres;
		}
		else
		{
			ptr_list->head = temp;
			temp->link = pres;
		}
	}
}

void delete(list_t *ptr_list, int key)
{
	if(ptr_list->head == NULL)
	{
		printf("empty list; cannot delete\n");
	}
	else
	{
		node_t* prev = NULL; node_t* pres = ptr_list->head;
		while(pres != NULL && pres->key != key)
		{
			prev = pres;
			pres = pres->link;
		} 
		if(pres == NULL)
		{
			printf("not found\n");
		}
		else if(prev == NULL)
		{
			ptr_list->head = pres->link;
			free(pres);
		} 
		else
		{
			prev->link = pres->link;
			free(pres);
		}
	}
}
			



