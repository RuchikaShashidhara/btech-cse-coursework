
#include <iostream>
using namespace std;
#include "area_visitor.h"
#include "rect.h"
#include "circle.h"
#include "square.h"

void Area_Visitor::visit_rect(const Rect* ptr) const
{
	area_rect += ptr->area();
}
void Area_Visitor::visit_circle(const Circle* ptr) const
{
	area_circle += ptr->area();
}
void Area_Visitor::visit_square(const Square* ptr) const
{
	area_square += ptr->area();
}

void Area_Visitor::disp_areas() const
{
	cout << "total rect area : " << area_rect << "\n";
	cout << "total circle area : " << area_circle << "\n";
	cout << "total square area : " << area_square << "\n";
}



