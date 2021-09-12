#include <iostream>
using namespace std;
#include <cstring>


// Implementation 2 -> removal of alias by copying arr of str util -> better design
// Output: "pesu" & "pesu"
class MyStr
{
	private:
		char *p_;
	public:
		MyStr(char *p);	//ctor
		~MyStr();	//dtor
		void disp();
};

// 1. alloc memory
// 2. copy str
MyStr::MyStr(char *p)		// ctor
: p_(new char[strlen(p) + 1])	// alloc new memory of size of arr + size of '\0'
{
	strcpy(p_, p);		// copy p_ from p i.e. strcpy(dest, source)
}

// Deallocate mem created in ctor to avoid garbage collection and p_
MyStr::~MyStr()			// dtor
{
	delete [] p_;
	// after deletion of [], p_ becomes a dangling pointer
	// hence we must delete p_ as well
}

void MyStr::disp()
{
	cout << p_ << "\n";
}
int main()
{
	char name[] = "pesu";
	{
	MyStr s1(name);
	s1.disp();		// displays "pesu"
	name[0] = ' ';
	s1.disp();		// displays "pesu"
	}
	
	{
		char name2[] = "abcd";
		char name3[] = "pqrstuvw";
		MyStr s2(name2);
		MyStr s3(name3);
		s2 = s3; 	// assignment
		s2.disp();	// displays "pqrstuvw"
		s3.disp(); 	// displays "parstuvw"
				// program crashes ..... but why ?  (Check written notes of Day 14 for detailed explanation)
	}
	
}

