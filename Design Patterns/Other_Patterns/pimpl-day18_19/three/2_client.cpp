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

	// Rect r1;		 // 1
	// auto r1(*r.ptr_rect); // 2
	// Rect r1(*r.ptr_rect); // 3, which is same as 2

	// All the above 3 statements,
	// Throws error as client has no access to Rect class
	// The client only has access to the Handle Class - RectHandle
	
	//RectHandle r2(r); 
	// Terrible way of implemeting
	// Reason, since no copy ctor is implementaed
	// It leads to aliasing and dangling pointer & double mem freeing

	// RectHandle r3(20, 15);
	// r3 = r;		// This statement throws an error
	// Since Asgn op & copy ctor is being replaced in the class decl & defn
}






