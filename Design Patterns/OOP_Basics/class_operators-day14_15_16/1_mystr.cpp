#include <iostream>
using namespace std;
#include <cstring>

// Implementation 1 -> case of alias -> bad design

class MyStr
{
	private:
		char *p_;
	public:
		MyStr(char *p);	// ctor
		void disp();
};

MyStr::MyStr(char *p)	// ctor
: p_(p)			// member initialization list
{
}

void MyStr::disp()
{
	cout << p_ << "\n";
}
int main()
{
	char name[] = "pesu";
	MyStr s1(name);
	s1.disp();		// displays "pesu"

	name[0] = ' ';
	s1.disp();		// displays " esu"
}


