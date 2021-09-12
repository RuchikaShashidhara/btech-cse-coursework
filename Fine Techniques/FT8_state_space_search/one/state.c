#include <stdio.h>
#include "state.h"

void set_state(state_t * ptr_state, int can, int mis, int boatpos)
{
	ptr_state->can_ = can;
	ptr_state->mis_ = mis;
	ptr_state->boatpos_ = boatpos;
	
}
void disp_state(const state_t * ptr_state)
{
	printf("can : %d mis : %d boatpos : %s\n", 
		ptr_state->can_,
		ptr_state->mis_,
		ptr_state->boatpos_ ?  "RIGHT" : "LEFT");
}

void moveCC(const state_t *src, state_t *dst)
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
}

void moveMM(const state_t *src, state_t *dst)
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
}

void moveCM(const state_t *src, state_t *dst)
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
}


void moveC(const state_t *src, state_t *dst)
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
}

void moveM(const state_t *src, state_t *dst)
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
}








