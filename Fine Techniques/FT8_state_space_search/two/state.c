#include <stdio.h>
#include "state.h"

void set_state(state_t * ptr_state, int can, int mis, int boatpos)
{
	ptr_state->can_ = can;
	ptr_state->mis_ = mis;
	ptr_state->boatpos_ = boatpos;
	ptr_state->fn_index_ = 0;
	
}
void disp_state(const state_t * ptr_state)
{
	printf("can : %d mis : %d boatpos : %s\n", 
		ptr_state->can_,
		ptr_state->mis_,
		ptr_state->boatpos_ ?  "RIGHT" : "LEFT");
}

int moveCC(const state_t *src, state_t *dst)
{
	// left to right
	if(src->boatpos_ == 0)
	{
		dst->can_ = src->can_ - 2;
	}
	// right to left
	else
	{
		dst->can_ = src->can_ + 2;
	}
	dst->mis_ = src->mis_;
	dst->boatpos_ = ! src->boatpos_;
	dst->fn_index_ = 0;
	return is_valid(dst); 
}

int moveMM(const state_t *src, state_t *dst)
{
	// left to right
	if(src->boatpos_ == 0)
	{
		dst->mis_ = src->mis_ - 2;
	}
	// right to left
	else
	{
		dst->mis_ = src->mis_ + 2;
	}
	dst->can_ = src->can_;
	dst->boatpos_ = ! src->boatpos_;
	dst->fn_index_ = 0;
	return is_valid(dst); 
}

int moveCM(const state_t *src, state_t *dst)
{
	// left to right
	if(src->boatpos_ == 0)
	{
		dst->can_ = src->can_ - 1;
		dst->mis_ = src->mis_ - 1;
	}
	// right to left
	else
	{
		dst->can_ = src->can_ + 1;
		dst->mis_ = src->mis_ + 1;
	}
	dst->boatpos_ = ! src->boatpos_;
	dst->fn_index_ = 0;
	return is_valid(dst); 
}


int moveC(const state_t *src, state_t *dst)
{
	// left to right
	if(src->boatpos_ == 0)
	{
		dst->can_ = src->can_ - 1;
	}
	// right to left
	else
	{
		dst->can_ = src->can_ + 1;
	}
	dst->mis_ = src->mis_;
	dst->boatpos_ = ! src->boatpos_;
	dst->fn_index_ = 0;
	return is_valid(dst); 
}

int moveM(const state_t *src, state_t *dst)
{
	// left to right
	if(src->boatpos_ == 0)
	{
		dst->mis_ = src->mis_ - 1;
	}
	// right to left
	else
	{
		dst->mis_ = src->mis_ + 1;
	}
	dst->can_ = src->can_;
	dst->boatpos_ = ! src->boatpos_;
	dst->fn_index_ = 0;
	return is_valid(dst); 
}

int are_same(const state_t *lhs, const state_t *rhs)
{
	return lhs->can_ == rhs->can_ && lhs->mis_ == rhs->mis_
		&& lhs->boatpos_ == rhs->boatpos_;
}

int is_valid(const state_t *ptr_state)
{
	return (ptr_state->mis_ >= 0 && ptr_state->mis_ <= 3) &&
		(ptr_state->can_ >= 0 && ptr_state->can_ <= 3) &&
		
		(ptr_state->mis_ == 3 || ptr_state->mis_ == 0 || 
		ptr_state->mis_ == ptr_state->can_);
}




