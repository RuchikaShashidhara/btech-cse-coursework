#include "rect.h"
#include "visitor.h"
 
Rect::Rect(double length, double breadth)
: length(length), breadth(breadth) 
{ 
}

double Rect::peri() const
{
	return 2 * (length + breadth);
}


double Rect::area() const
{
	return length * breadth;
}

double Rect::get_length() const
{
	return length;
}

double Rect::get_breadth() const
{
	return breadth;
}

void Rect::accept(const Visitor* ptr_visitor) const
{
	ptr_visitor->visit_rect(this);
}


