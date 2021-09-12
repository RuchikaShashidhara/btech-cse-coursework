#include <stdio.h>
#include "state.h"

int main()
{
#if 0
	state_t s;
	set_state(&s, 3, 3, 0);
	disp_state(&s);
#endif
	void (*move[])(const state_t *src, state_t *dst) 
	= {
		moveCC, moveMM, moveCM, moveC, moveM
	};
	
	// left to right
	state_t s; state_t d;
	set_state(&s, 3, 3, 0);
	for(int i = 0; i < 5; ++i)
	{
		move[i](&s, &d);
		disp_state(&d);
	}
	// right to left
	set_state(&s, 0, 0, 1);
	for(int i = 0; i < 5; ++i)
	{
		move[i](&s, &d);
		disp_state(&d);
	}
	
	
	
	
	
}
