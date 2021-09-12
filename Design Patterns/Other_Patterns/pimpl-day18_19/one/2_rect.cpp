#include <iostream>
using namespace std;
#include "2_rect.h"

#if 0
Rect::Rect(int length, int breadth)
: length_(length), breadth_(breadth)
{
}
	 
int Rect::find_area() const
{
	return length_ * breadth_;
}

void Rect::change_length(int length)
{
	length_ = length;
}

void Rect::change_breadth(int breadth)
{
	breadth_ = breadth;
}
#endif
Rect::Rect(int length, int breadth)
//: length_(length), breadth_(breadth), area_(length_ * breadth_) // NO
: length_(length), breadth_(breadth), area_(length * breadth) // yes
{
}
	 
int Rect::find_area() const
{
	//return length_ * breadth_;
	return area_;
}

void Rect::change_length(int length)
{
	length_ = length;
	area_ = length_ * breadth_;
}

void Rect::change_breadth(int breadth)
{
	breadth_ = breadth;
	area_ = length_ * breadth_;
}
