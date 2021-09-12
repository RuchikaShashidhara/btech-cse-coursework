#include <stdio.h>
#include <stdlib.h>
#include "A3_header_PES1201800046.h"

//to set the capacities of each jug - A, B, C
void set_state(state_t * ptr_state, int x, int y, int z)
{
	ptr_state->A_ = x;
	ptr_state->B_ = y;
	ptr_state->C_ = z;
	ptr_state->fn_index_ = 0;	
}

//to display the capacities of each jug - A, B, C
void disp_state(const state_t * ptr_state)
{
	printf("%d %d %d\n", 
		ptr_state->A_,
		ptr_state->B_,
		ptr_state->C_);
}

//Each function moveXY defines water to poured from X to Y
//water is poured to each jug if src->X_ > 0 && src->Y_ < maxY until dst->Y_ < maxY && dst->X_ > 0

int moveAB(const state_t *src, state_t *dst)
{
	dst->A_ = src->A_;
	dst->B_ = src->B_;
	dst->C_ = src->C_;
	dst->fn_index_ = 0;	
	
	if(src->A_ > 0 && src->B_ < maxB)
	{
		while(dst->B_ < maxB && dst->A_ > 0)
		{
			dst->B_ += 1;
			dst->A_ -= 1;
		}
	}
	
	return is_valid(dst);
}

int moveAC(const state_t *src, state_t *dst)
{
	dst->A_ = src->A_;
	dst->B_ = src->B_;
	dst->C_ = src->C_;
	dst->fn_index_ = 0;	
	
	if(src->A_ > 0 && src->C_ < maxC)
	{
		while(dst->C_ < maxC && dst->A_ > 0)
		{
			dst->C_ += 1;
			dst->A_ -= 1;
		}
	}
	
	return is_valid(dst);
}

int moveBA(const state_t *src, state_t *dst)
{
	dst->A_ = src->A_;
	dst->B_ = src->B_;
	dst->C_ = src->C_;
	dst->fn_index_ = 0;	
	
	if(src->B_ > 0 && src->A_ < maxA)
	{
		while(dst->A_ < maxA && dst->B_ > 0)
		{
			dst->A_ += 1;
			dst->B_ -= 1;
		}
	}
	
	return is_valid(dst);
}

int moveBC(const state_t *src, state_t *dst)
{
	dst->A_ = src->A_;
	dst->B_ = src->B_;
	dst->C_ = src->C_;
	dst->fn_index_ = 0;	
	
	if(src->B_ > 0 && src->C_ < maxC)
	{
		while(dst->C_ < maxC && dst->B_ > 0)
		{
			dst->C_ += 1;
			dst->B_ -= 1;
		}
	}
	
	return is_valid(dst);
}

int moveCA(const state_t *src, state_t *dst)
{
	dst->A_ = src->A_;
	dst->B_ = src->B_;
	dst->C_ = src->C_;
	dst->fn_index_ = 0;	
	
	if(src->C_ > 0 && src->A_ < maxA)
	{
		while(dst->A_ < maxA && dst->C_ > 0)
		{
			dst->A_ += 1;
			dst->C_ -= 1;
		}
	}
	
	return is_valid(dst);
}

int moveCB(const state_t *src, state_t *dst)
{
	dst->A_ = src->A_;
	dst->B_ = src->B_;
	dst->C_ = src->C_;
	dst->fn_index_ = 0;	
	
	if(src->C_ > 0 && src->B_ < maxB)
	{
		while(dst->B_ < maxB && dst->C_ > 0)
		{
			dst->B_ += 1;
			dst->C_ -= 1;
		}
	}
	
	return is_valid(dst);
}

//to check if ptr_state can be reached i.e. if it is a valid state or not
//capacities of each jug A, B, C should be <= maxJUG and >=0
int is_valid(const state_t *ptr_state)
{		
	return ((ptr_state->A_ <= maxA && ptr_state->A_ >= 0) && 
		(ptr_state->B_ <= maxB && ptr_state->B_ >= 0) && 
		(ptr_state->C_ <= maxC && ptr_state->C_ >= 0)); 
}

//to check if capacities of jugs - A, B, C of the states lhs and rhs are equal
int are_same(const state_t *lhs, const state_t *rhs)
{
	return (lhs->A_ == rhs->A_ && lhs->B_ == rhs->B_ && lhs->C_ == rhs->C_);
}

//to initialize the list of nodes that will contain states that are reachable
void init_list(list_t *ptr_list)
{
	ptr_list->head_ = NULL;
	ptr_list->tail_ = NULL;
}

//to add a state at the end of the list
void add_at_end(list_t *ptr_list, const state_t* ptr_state)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->st_ = *ptr_state;
	// empty list
	if(ptr_list->head_ == NULL)
	{
		temp->prev = ptr_list->tail_;
		ptr_list->head_ = temp;
		ptr_list->tail_ = temp;
		temp->next = NULL;
	}
	// non-empty list
	else
	{
		temp->prev = ptr_list->tail_;
		ptr_list->tail_->next = temp;
		ptr_list->tail_ = temp;
		temp->next = NULL;
	}

}

//to remove a state from the end of the list
void remove_at_end(list_t *ptr_list)
{
	//empty list
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
	// other cases of list
	else
	{
		node_t *temp = ptr_list->tail_;
		ptr_list->tail_ = temp->prev;
		ptr_list->tail_->next = NULL;
		free(temp);
	}
	
}

//to display the states, i.e. capacities of jugs A, B, C of each state/node of the list
void disp_list(const list_t *ptr_list)
{
	node_t* temp = ptr_list->head_;
	while(temp)  //until the end of the list is not reached
	{
		disp_state(&temp->st_);
		temp = temp->next;
	}
}

//to check if a particular state is repeated i.e. is already present in the list
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


