#ifndef STATE_H
#define STATE_H
struct state
{
	int can_; // can on the left bank
	int mis_; // mis on the left bank
	int boatpos_; // boat position : 0 : left, 1 : right
};
typedef struct state state_t;
void set_state(state_t *ptr_state, int can, int mis, int boatpos);
void disp_state(const state_t *ptr_state);

void moveCC(const state_t *src, state_t *dst);
void moveMM(const state_t *src, state_t *dst);
void moveCM(const state_t *src, state_t *dst);
void moveC(const state_t *src, state_t *dst);
void moveM(const state_t *src, state_t *dst);

#endif
