#include <stdio.h>
#include <stdlib.h>
#include "1_list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head = NULL;
}
void disp(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		printf("%d ", temp->key);
		temp = temp->next;
	}
	printf("\n");
	
}
node_t* make_node(int key)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->key = key;
	temp->next = NULL;
	return temp;
}
void add(list_t* ptr_list, int key)
{
	node_t* temp = make_node(key);
	// add in the beginning
	temp->next = ptr_list->head;
	ptr_list->head = temp;
}
// check this video:
//		Scott Meyers
//		most important design guideline


// list is valid; file is opened for writing
void write_file(const list_t *ptr_list, FILE* fp)
{
	node_t* temp = ptr_list->head;
	while(temp)
	{
		fprintf(fp, "%d ", temp->key);
		temp = temp->next;
	}
	printf("\n");
}

void read_file(list_t *ptr_list, FILE* fp)
{
	int key;
	fscanf(fp, "%d", &key);
	while(! feof(fp))
	{
		add(ptr_list, key);
		fscanf(fp, "%d", &key);
	}
}


