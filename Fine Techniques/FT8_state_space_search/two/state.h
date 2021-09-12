#ifndef STATE_H
#define STATE_H
struct state
{
	int can_; // can on the left bank
	int mis_; // mis on the left bank
	int boatpos_; // boat position : 0 : left, 1 : right
	// implementation field
	int fn_index_; // indicates next function to apply
};
typedef struct state state_t;
void set_state(state_t *ptr_state, int can, int mis, int boatpos);
void disp_state(const state_t *ptr_state);

int moveCC(const state_t *src, state_t *dst);
int moveMM(const state_t *src, state_t *dst);
int moveCM(const state_t *src, state_t *dst);
int moveC(const state_t *src, state_t *dst);
int moveM(const state_t *src, state_t *dst);
int is_valid(const state_t *);
int are_same(const state_t *lhs, const state_t *rhs);
#endif
