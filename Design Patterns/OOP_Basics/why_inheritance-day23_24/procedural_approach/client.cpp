#include <iostream>
using namespace std;
#include "shape.h"


int main()
{
	Shape s;
	s.read();
	s.disp();
	cout << "area : " << s.area() << "\n";
	cout << "peri : " << s.peri() << "\n";
}

