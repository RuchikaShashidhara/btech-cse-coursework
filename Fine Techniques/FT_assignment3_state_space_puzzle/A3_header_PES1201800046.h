#ifndef HEADER_H
#define HEADER_H

//capacities of each jug - A, B, C and 
//the implementation field of the next function index to be applied
struct state
{
	int A_; 	// number of litres in jug A
	int B_; 	// number of litres in jug B
	int C_; 	// number of litres in jug C
	int fn_index_;  // indicates next function to apply
};
typedef struct state state_t;

//each state in the list of states for a particular soln
struct node
{
	state_t st_;        //information of the node - state
	struct node* prev;  //address pointing to the previous node
	struct node* next;  //address pointing to the next node
};
typedef struct node node_t;

//double linked list of states for a particular soln
struct list
{
	node_t* head_;  //head node
	node_t* tail_;  //tail node
};
typedef struct list list_t;

//initialzing the maximun capacities of the jug
int maxA, maxB, maxC;

//to set the capacities of each jug - A, B, C
void set_state(state_t *ptr_state, int x, int y, int z);

//to display the capacities of each jug - A, B, C
void disp_state(const state_t *ptr_state);

//Each function moveXY defines water to poured from X to Y
int moveAB(const state_t *src, state_t *dst);
int moveAC(const state_t *src, state_t *dst);
int moveBA(const state_t *src, state_t *dst);
int moveBC(const state_t *src, state_t *dst);
int moveCA(const state_t *src, state_t *dst);
int moveCB(const state_t *src, state_t *dst);

//to check if ptr_state can be reached i.e. if it is a valid state or not
int is_valid(const state_t *ptr_state);

//to check if capacities of jugs - A, B, C of the states lhs and rhs are equal
int are_same(const state_t *lhs, const state_t *rhs);

//to initialize the list of nodes that will contain states that are reachable
void init_list(list_t *ptr_list);

//to add a state at the end of the list
void add_at_end(list_t *ptr_list, const state_t* ptr_state);

//to remove a state from the end of the list
void remove_at_end(list_t *ptr_list);

//to display the states, i.e. capacities of jugs A, B, C of each state/node of the list
void disp_list(const list_t *ptr_list);

//to check if a particular state is repeated i.e. is already present in the list
int is_repeated(list_t *ptr_list, const state_t* ptr_state);

#endif
