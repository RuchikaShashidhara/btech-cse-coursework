#ifndef RECT_H
#define RECT_H
struct Rect; // struct type declaration
typedef struct Rect rect_t;

struct vtable;
struct Rect
{
	int length;
	int breadth;
	struct vtable *ptr_vtbl; // an interface
};

struct vtable
{
	int (*area)(const rect_t* ptr_rect);
	int (*peri)(const rect_t* ptr_rect);
	void (*disp)(const rect_t* ptr_rect);
};

void init(rect_t* ptr_rect, int length, int breadth);
// think : how to decrease the size of the structure
//			have one pointer instead of an array of pointers

#endif

