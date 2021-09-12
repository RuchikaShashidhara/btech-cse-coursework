#include "square.h"
#include "visitor.h"

Square::Square(double length)
: length(length)
{ 
}

double Square::peri() const 
{
	return 4 * length;
}


double Square::area()  const
{
	return length * length;
}

double Square::get_length() const
{
	return length;
}

void Square::accept(const Visitor* ptr_visitor) const
{
	ptr_visitor->visit_square(this);
}
