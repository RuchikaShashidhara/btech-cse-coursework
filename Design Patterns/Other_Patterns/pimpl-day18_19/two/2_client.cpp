#include <iostream>
using namespace std;
// client does not get to know Rect
// do not include 2_rect.h here
#include "2_recthandle.h"

int main()
{
	RectHandle r(10, 5);
	cout << r.find_area() << "\n";
	
	r.change_length(20);
	cout << r.find_area() << "\n";

	r.change_breadth(15);
	cout << r.find_area() << "\n";
	
}

