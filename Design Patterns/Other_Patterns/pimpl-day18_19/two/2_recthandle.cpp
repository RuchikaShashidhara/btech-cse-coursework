#include <iostream>		// needs to be included as we use "new"
using namespace std;
#include "2_rect.h"		// Though we hadn't included rect.h in recthandle.h, 
		// we must include it this file - function definition
#include "2_recthandle.h"	// Since this is no order dependeny of including files here
// include statements can be written in any order										
RectHandle::RectHandle(int length, int breadth)
: ptr_rect(new Rect(length, breadth))
{
}

// Delegating: All these functions intern call the functions defined in Rect Class	
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

