#include <iostream>
using namespace std;
#include "2_rect.h"


#if 1
Rect::Rect(int length, int breadth)
: length_(length), breadth_(breadth), is_changed_(true)  
{
}
	 
int Rect::find_area() const
{
	if(is_changed_)
	{
		area_ = length_ * breadth_;
		is_changed_ = false;
	}
	return area_;
}

void Rect::change_length(int length)
{
	length_ = length;
	is_changed_ = true;
}

void Rect::change_breadth(int breadth)
{
	breadth_ = breadth;
	is_changed_ = true;
}
#endif

