#ifndef RECT_H
#define RECT_H

struct Rect
{
	int length;
	int breadth;
};
typedef struct Rect rect_t;
void init(rect_t* ptr_rect, int length, int breadth);
int area(const rect_t* ptr_rect);
void disp(const rect_t* ptr_rect);
int peri(const rect_t* ptr_rect);

#endif

