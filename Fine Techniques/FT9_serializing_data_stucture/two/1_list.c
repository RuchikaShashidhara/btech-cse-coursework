#include <stdio.h>
#include <stdlib.h>
#include "1_list.h"
// dump the record as it exists in memory
// do not want to convert every field into a human readable form - text
// this binary structure is more efficient in space
// also indexable - find the loc of nth record easily
// not possible if the file is a text or file of chars


// possible to access ith record in the file directly
// not possible in text files - file of strings  - cannot make
//		out the length of record

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
//		fprintf(fp, "%d ", temp->key);
		fwrite(&temp->key, sizeof(int), 1, fp);
		temp = temp->next;
	}
	printf("\n");
}

void read_file(list_t *ptr_list, FILE* fp)
{
	int key;
	fread(&key, sizeof(int), 1,  fp);
	while(! feof(fp))
	{
		add(ptr_list, key);
		fread(&key, sizeof(int), 1,  fp);
	}
}


