#include <iostream>
using namespace std;
#include <cstring>

// Implementation 3 & 4
class MyStr
{
	private:
	char *p_;
	public:
	MyStr(const char *p);
	~MyStr();
	//void operator=(const MyStr& rhs);
	MyStr& operator=(const MyStr& rhs);
	void disp();
};

// 1. alloc memory
// 2. copy str
MyStr::MyStr(const char *p)
: p_(new char[strlen(p) + 1])
{
	strcpy(p_, p);
}

MyStr::~MyStr()
{
	delete [] p_;
}

#if 0
void MyStr::operator=(const MyStr& rhs)
{
	delete [] p_;
	p_ = new char[strlen(rhs.p_) + 1];
	strcpy(p_, rhs.p_);
}
#endif

#if 0
// do nothing if self assignment
void MyStr::operator=(const MyStr& rhs)
{
	if(this != &rhs)
	{
		delete [] p_;
		p_ = new char[strlen(rhs.p_) + 1];
		strcpy(p_, rhs.p_);
	}
}
#endif
/*
We can overload the assignment operator
By providing our own semantics by replacing the default shallow copy assignment operator with the function operator=()
*/

/*
Writing our own assignment operator, that replaces the default assignment operator 
Ex: s2 = s3; now becomes s2.operator=(s3);

In operator=() function, we pass the object s3 as an argument & objects are always passed by reference. Hence, operator signature should become operator(const MyStr&) with parameter having reference to class MyStr. Here RHS of assignment is normally not expected to change, unless there is a concept of ownership. Since it is not expected to change, the parameter becomes const MyStr&
Here assignment is a case of overloading
*/

/*
Hence in the implementation of operator=(); we need not do anything if a case of self assignment is seen i.e. when this, &rhs point to the same object s4 p_.

We can compare this with &rhs as it will lead to the same reference, but we can’t compare *this with rhs as it will lead to the same object and it leads to a compile-time error as here in MyStr class there is no operator defined as ==.
*/

// To support cascading of = operator; make = operation result in a value
MyStr& MyStr::operator=(const MyStr& rhs)
{
	if(this != &rhs)
	{
		delete [] p_;
		p_ = new char[strlen(rhs.p_) + 1];
		strcpy(p_, rhs.p_);
	}
	return *this;
	// return this should not be used, it will give a compile time error
	// The return type must be an obj (*this) and not a pointer (this)
}

// copy ctor
MyStr::MyStr(const MyStr& rhs)
: p_(new char[strlen(rhs.p_) + 1])
{
	strcpy(p_, rhs.p_);
}

void MyStr::disp()
{
	cout << p_ << "\n";
}

int main()
{


// Implementation 2
#if 0
	{
		char name2[] = "abcd";
		char name3[] = "pqrstuvw";
		MyStr s2(name2);
		MyStr s3(name3);
		s2 = s3; // assignment // s2.operator=(s3)
		s2.disp();
		s3.disp(); 
	}
	{
		char name4[] = "test";
		MyStr s4(name4);
		s4 = s4; // self assignment
		s4.disp();
	}
#endif



// Implementation 3
#if 0
	{
		MyStr x("rama");
		MyStr y("krishna");
		MyStr z("govinda");

		// Cascading Assignments
		x = y = z;
		
		/*
		Cascading Assignment works with integers
		Assignment operator works from right to left
		In all other languages except Python, = is an expression, so cascading = doesn't owrk with Python
		*/

		(x = y) = z;
		/* Is (x = y) an L-value
		The only operator in C that gives L-value back is the dereferencing operator
		In C++, assignment opeartor gives L-value, as the result is stored in a variable during the program. 
		If it is stored in a temporary variable, then it gives the R-value
		*/
	}
#endif



// Implementation 4
#if 0
// copy ctor:
	{
		MyStr x("India");
		MyStr y = x; // MyStr y(x); 
			     // These statements are initialization as the var/obj is being defined here, it is not assignment
		x.disp();
		y.disp();
	}
#endif
	
}
// valgrind : memory leak check
