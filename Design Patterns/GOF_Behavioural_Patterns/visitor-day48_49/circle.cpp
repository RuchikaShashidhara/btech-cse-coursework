#include "circle.h"
#include "visitor.h"

Circle::Circle(double radius)
: radius(radius)
{ 
}

double Circle::peri() const
{
	return 2 * 3.14 * radius;
}


double Circle::area() const
{
	return 3.14 * radius * radius;
}

double Circle::get_radius() const
{
	return radius;
}

void Circle::accept(const Visitor* ptr_visitor) const
{
	ptr_visitor->visit_circle(this);
}
