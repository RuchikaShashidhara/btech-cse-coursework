#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head_ = NULL;
	ptr_list->tail_ = NULL;
}
void add_at_end(list_t *ptr_list, const state_t* ptr_state)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->st_ = *ptr_state;
	// empty
	if(ptr_list->head_ == NULL)
	{
		temp->prev = ptr_list->tail_;
		ptr_list->head_ = temp;
		ptr_list->tail_ = temp;
		temp->next = NULL;
	}
	// non-empty
	else
	{
		temp->prev = ptr_list->tail_;
		ptr_list->tail_->next = temp;
		ptr_list->tail_ = temp;
		temp->next = NULL;
	}

}
void remove_at_end(list_t *ptr_list)
{
	//empty
	if(ptr_list->head_ == NULL)
	{
		printf("empty\n");
	}
	// one node list
	else if(ptr_list->head_ == ptr_list->tail_)
	{
		free(ptr_list->head_);
		ptr_list->head_ = ptr_list->tail_ = NULL;
	}
	// other
	else
	{
		node_t *temp = ptr_list->tail_;
		ptr_list->tail_ = temp->prev;
		ptr_list->tail_->next = NULL;
		free(temp);
	}
	
}

int is_repeated(list_t *ptr_list, const state_t* ptr_state)
{
	node_t* temp = ptr_list->head_;
	while(temp)
	{
		if(are_same(&temp->st_, ptr_state))
			return 1;
		temp = temp->next;
	}
	return 0;
}

void disp_list(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head_;
	while(temp)
	{
		disp_state(&temp->st_);
		temp = temp->next;
	}
}


