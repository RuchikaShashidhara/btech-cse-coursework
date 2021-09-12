#include <stdio.h>
#include "list.h"
#define DEBUG 0

// init state state
// init goal state
// make soln list empty
// add start state to the soln list
// while not goal state or no more transitons do
//	get the next state
//	if state is valid and safe then
//		add to the soln list
//		check if it is soln
//		
//  else there are possible moves
//		make the next move
//	else while no more moves
//		backtrack

int main()
{
	state_t start;
	set_state(&start, 3, 3, 0);
	state_t goal;
	set_state(&goal, 0, 0, 1);
	int (*move[])(const state_t *src, state_t *dst) = {
		moveCC, moveMM, moveCM, moveC, moveM
	};
	list_t soln_list;
	init_list(&soln_list);
	add_at_end(&soln_list, &start);
	//disp_list(&soln_list);
	int soln = 0;
	state_t temp;
	int fn_index;
	while(!soln)
	{
		// select the fn
		fn_index = soln_list.tail_->st_.fn_index_;
		if(DEBUG)
		{
			printf("trying function : %d\n", fn_index);
			getchar();
			printf("valid : %d\n", move[fn_index](&soln_list.tail_->st_, &temp));
		}
		if( move[fn_index](&soln_list.tail_->st_, &temp) &&
			! is_repeated(&soln_list, &temp))
		{
			add_at_end(&soln_list, &temp);
			if(DEBUG)
			{
				printf("added : ");
				disp_state(&temp);
				getchar();
			}
			soln = are_same(&temp, &goal);
		}
		else
		{
			// empty list not checked
			while(soln_list.tail_->st_.fn_index_ == 4)
			{
				if(DEBUG)
				{
					printf("removed : ");
					disp_state(&soln_list.tail_->st_);
					getchar();
				}
			
				remove_at_end(&soln_list);
			}
			++soln_list.tail_->st_.fn_index_;
		}
	}
	
	disp_list(&soln_list);
	
}






#if 0
int main()
{

	state_t s;
	set_state(&s, 3, 3, 0);
	disp_state(&s);


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
#endif

