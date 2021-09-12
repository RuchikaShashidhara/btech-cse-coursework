#include <iostream>
using namespace std;
#include "2_rect.h"

int main()
{
	Rect r(10, 5);
	cout << r.find_area() << "\n";
	
	r.change_length(20);
	cout << r.find_area() << "\n";

	r.change_breadth(15);
	cout << r.find_area() << "\n";
	
}

