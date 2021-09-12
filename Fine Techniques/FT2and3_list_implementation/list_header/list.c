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
	ptr_list->head = make_node(111); // some value
}

void insert_list(list_t *ptr_list, int elem)
{
	node_t* temp = make_node(elem);


	node_t* prev = ptr_list->head; node_t* pres = ptr_list->head->next;
	while(pres != NULL && pres->key < temp->key)
	{
		prev = pres;
		pres = pres->next;
	}
	prev->next = temp;
	temp->next = pres;
	disp_list(ptr_list);
}

void delete_list(list_t *ptr_list, int elem){
	node_t* prev = ptr_list->head;
	node_t* pres = ptr_list->head->next;
	while(pres != NULL && pres->key != elem)
	{
		prev = pres;
		pres = pres->next;
	}
	if(pres != NULL)
	{
		prev->next = pres->next;
		free(pres);
		pres = NULL;
	}
	else
	{
		printf("Element does not exist\n");
	}
	/*node_t *prev = ptr_list->head;
	node_t *pres = ptr_list->head->next;
	while(pres != NULL && pres->key != elem)
	{
			prev = pres;
			pres = pres->next;
	}
	if(pres == NULL)
	{
		printf("Element does not exist\n");
	}
	else
	{
		prev->next = pres->next;
		free(pres);
		pres = NULL;
	}*/
	disp_list(ptr_list);	
}

void disp_list(const list_t *ptr_list)
{
	node_t *temp = ptr_list->head->next;
	while(temp)
	{
		printf("%d ", temp->key);
		temp = temp->next;
	}
	printf("\n\n");
}


/*void list_destroy(list_t *ptr_list)
{
	node_t *temp = ptr_list->head
}*/
