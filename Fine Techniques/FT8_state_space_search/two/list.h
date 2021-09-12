#ifndef LIST_H
#define LIST_H
#include "state.h"

struct node
{
	state_t st_;
	struct node* prev;
	struct node* next;
};
typedef struct node node_t;
struct list
{
	node_t* head_;
	node_t* tail_;
};
typedef struct list list_t;
void init_list(list_t *ptr_list);
void add_at_end(list_t *ptr_list, const state_t* ptr_state);
void remove_at_end(list_t *ptr_list);
int is_repeated(list_t *ptr_list, const state_t* ptr_state);
void disp_list(const list_t *ptr_list);
#endif

