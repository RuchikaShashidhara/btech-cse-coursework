#ifndef DERIVED_H
#define DERIVED_H
#include "1_base.h"

typedef struct 
{
	void (*foo)();
	void (*bar)();
} vtbl_B_t;

struct B
{
	vtbl_B_t *ptr;
	A_t base;
	int b1;
	int b2;
};
typedef struct B B_t;
void init_B(B_t *q, int a1, int a2, int b1, int b2);
#endif
