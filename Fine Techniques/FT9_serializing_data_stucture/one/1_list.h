#ifndef LIST_H
#define LIST_H
#include <stdio.h>

struct node
{
	int key;
	struct node* next;
};
typedef struct node node_t;
struct list
{
	node_t *head;
	
};
typedef struct list list_t;
void init_list(list_t *ptr_list);
void disp(const list_t *ptr_list);
void add(list_t* ptr_list, int key);

void write_file(const list_t *ptr_list, FILE* fp);
void read_file(list_t *ptr_list, FILE* fp); 
#endif
