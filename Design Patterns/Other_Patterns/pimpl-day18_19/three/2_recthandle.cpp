#include <iostream>
using namespace std;
#include "2_rect.h"
#include "2_recthandle.h"
	
RectHandle::RectHandle(int length, int breadth)
: ptr_rect(new Rect(length, breadth))
{
}

int RectHandle::find_area() const
{
	return ptr_rect->find_area();
}

void RectHandle::change_length(int length)
{
	ptr_rect->change_length(length);
}

void RectHandle::change_breadth(int breadth)
{
	ptr_rect->change_breadth(breadth);
}

RectHandle::~RectHandle()
{
	delete ptr_rect;
}
