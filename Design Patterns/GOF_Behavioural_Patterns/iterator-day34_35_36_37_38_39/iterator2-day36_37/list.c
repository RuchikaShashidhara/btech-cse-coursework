#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init(list_t *ptr_list)
{
	ptr_list->head = 0;
}

void insert(list_t *ptr_list, int key)
{
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	temp->link = 0;
	temp->key = key;
	if(ptr_list->head == 0)
	{
		ptr_list->head = temp;
	}
	else
	{
		node_t* prev = 0; node_t* pres = ptr_list->head;
		while(pres != 0 && pres->key < temp->key)
		{
			prev = pres;
			pres = pres->link;
		}
		if(prev == 0)
		{
			ptr_list->head = temp;
		}
		else
		{
			prev->link = temp;
		}
		temp->link = pres;
	}
}

void disp(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		printf("%d ", temp->key);
		temp = temp->link;
	}
}

void init_iterator(list_t *ptr_list, iterator_t *ptr_iterator)
{
	ptr_iterator->current = ptr_list->head;
}
int has_next(const iterator_t *ptr_iterator)
{
	return ptr_iterator->current != 0;
}
int next(iterator_t *ptr_iterator)
{
	int key = ptr_iterator->current->key;
	ptr_iterator->current = ptr_iterator->current->link;
	return key;
}










