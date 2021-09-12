#include <iostream>
using namespace std;
#include "shape.h"
#include "rect.h"
#include "circle.h"


int main()
{
	Shape *p = new Rect;
	p->read();
	p->disp();
	cout << "area : " << p->area() << "\n";
	cout << "peri : " << p->peri() << "\n";
	
	Shape *q = new Circle;
	q->read();
	q->disp();
	cout << "area : " << q->area() << "\n";
	cout << "peri : " << q->peri() << "\n";

}

