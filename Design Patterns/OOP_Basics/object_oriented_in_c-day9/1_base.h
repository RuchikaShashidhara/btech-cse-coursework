#ifndef BASE_H
#define BASE_H
// base class : A
// derived class : B
typedef struct 
{
	void (*foo)();
	void (*bar)();
} vtbl_A_t;

struct A
{
	vtbl_A_t *ptr;
	int a1;
	int a2;
};
typedef struct A A_t;
void init_A(A_t *p, int a1, int a2);




#endif
