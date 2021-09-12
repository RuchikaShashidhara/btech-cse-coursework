#include <stdio.h>
#include "A3_header_PES1201800046.h"

int main()
{	
	//defining the start and goal capacities of the jugs
	int X, Y, Z, P, Q, R;
	//reading the input of maximum capacities of the jugs - A, B, C
	scanf("%d %d %d", &maxA, &maxB, &maxC);
	//reading the start capacities of the jugs - X, Y, Z	
	scanf("%d %d %d", &X, &Y, &Z);
	//reading the goal/end capacities of the jugs - P, Q, R	
	scanf("%d %d %d", &P, &Q, &R);
	
	//initializing callback array 
	int (*move[])(const state_t *src, state_t *dst) = { moveAB, moveAC, moveBA, moveBC, moveCA, moveCB };
	//initialzing the variable that will select the function
	int fn_index;
		
	//initializing start and goal states
	state_t start, goal;
	//initializing start state
	set_state(&start, X, Y, Z);
	//initializing goal state
	set_state(&goal, P, Q, R);	
	//initializing list that will contain each case
	list_t soln_list;		
	//inilializing list that will contain the soln cases and adding the start state to it
	init_list(&soln_list);
	//adding the start state to the soln list
	add_at_end(&soln_list, &start);
	//initializing a temporary state to be added to soln list	
	state_t temp;
	
	//initializing the variable that will count the number of soln cases
	int count = 0;
	//intialzing a flag soln, 1 - soln has been found, 0 - soln hasn't been found yet
	int soln = 0;	
	
	//Backtracing to display the soln cases and total num of soln
	//until there are no states in the soln list
	while(soln_list.tail_)
	{
		//selecting the fn_index from the tail state of the soln list
		fn_index = soln_list.tail_->st_.fn_index_;	
		//selecting the move function wrt fn_index to get a temp state	
		move[fn_index](&soln_list.tail_->st_, &temp);
		//if the temp state is not repeated in the soln list
		if(!is_repeated(&soln_list, &temp))
		{
			//adding the temp state to the soln list
			add_at_end(&soln_list, &temp);
			//assigning the flag of soln
			//if the last state is goal state, soln=1, else soln=0
			soln = are_same(&temp, &goal);
			//if soln list ends with the goal state
			if(soln)
			{
				//incrementting the count of number of soln cases
				count++;
				//displaying the states of the soln list
				disp_list(&soln_list);
				printf("\n");
				//incrementing the fn_index of the last state and 
				//checking if all the states have been reached from that state
				if(++soln_list.tail_->st_.fn_index_ == 6)
				{					
					//removing the last state
					remove_at_end(&soln_list);
					//assigning 0 to soln flag, as the last state is not the goal state
					soln = 0;					
				}				
			}
		}
		//if the temp state is repeated in the soln list
		else
		{
			//until there are no states in the soln list,
			//incrementing the fn_index of the last state and 
			//checking if all the states have been reached from that state
			while(soln_list.tail_ && ++soln_list.tail_->st_.fn_index_ == 6)
			{					
				//removing the last state
				remove_at_end(&soln_list);
				//assigning 0 to soln flag, as the last state is not the goal state
				soln = 0;		
			}
		}
		
	}	
	//displaying the total num of soln for the case entered
	printf("%d\n", count);
}


