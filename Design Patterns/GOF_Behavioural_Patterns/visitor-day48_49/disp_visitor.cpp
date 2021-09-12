
#include <iostream>
using namespace std;
#include "disp_visitor.h"
#include "rect.h"
#include "circle.h"
#include "square.h"

void Disp_Visitor::visit_rect(const Rect* ptr) const
{
	cout << "rect : " << ptr->get_length() << ":" << ptr->get_breadth() << "\n";
}
void Disp_Visitor::visit_circle(const Circle* ptr) const
{
	cout << "circle : " << ptr->get_radius() << "\n"; 
}
void Disp_Visitor::visit_square(const Square* ptr) const
{
	cout << "square : " <<  ptr->get_length() << "\n";
}
