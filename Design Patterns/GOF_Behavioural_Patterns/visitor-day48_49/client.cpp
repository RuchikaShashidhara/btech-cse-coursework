#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

#include "shape.h"
#include "rect.h"
#include "circle.h"
#include "square.h"
#include "disp_visitor.h"
#include "area_visitor.h"


int main()
{
#if 0
	Shape *p;
	p = new Rect(20, 10);
	cout << p->area() << " : " <<  p->peri() << "\n";
	delete p;

	p = new Circle(7);
	cout << p->area() << " : " <<  p->peri() << "\n";
	delete p;
	
	p = new Square(7);
	cout << p->area() << " : " <<  p->peri() << "\n";
	delete p;
#endif

	vector<Shape*> v{
		new Rect(1, 2),
		new Rect(3, 4),
		new Circle(5),
		new Square(6),
		new Circle(7),
		new Rect(8, 9),
		new Rect(10, 11),
		new Circle(12),
		new Square(13)
	};
	Disp_Visitor visitor;
	for(auto p : v)
	{	
		p->accept(&visitor);
	}
	Area_Visitor visitor1;
	for(auto p : v)
	{	
		p->accept(&visitor1);
	}	
	visitor1.disp_areas();
}
