#include <iostream>
using namespace std;
#include "mystr.h"

int main()
{
// Client code for only Copy Ctor Implementation
#if 0
	MyStr a("hello");
	a.disp();
//	MyStr z("hello");
//	z.disp();
	{
		MyStr b(a); 
		a.disp();
		b.disp();
	}
	a.disp();
#endif

// Client code for both Copy Ctor & Asgn Op Implementation
	MyStr a("hello");
	MyStr b(a);
	MyStr c(a);
	a.disp(); b.disp(); c.disp();
	
	MyStr x("world");
	MyStr y(x);
	x.disp(); y.disp();
	cout << "\n\n";
	
	x = a;
	
	a.disp(); b.disp(); c.disp();
	x.disp(); y.disp();
	cout << "\n\n";

	y = y;
	
	a = b;
	a.disp(); b.disp(); c.disp();
	x.disp(); y.disp();
	
	cout << "what : " << a[2] << "\n"; // a.operator[](2)
	// Example of overloading with indexing op for display
	
	//a[2] = 'Z'; //  b and c also changed?
	//a.disp(); b.disp(); c.disp();
	
}
