#include <iostream>
using namespace std;

class A
{
	public:
	A() { cout << "ctor\n"; }
	~A() { cout << "dtor \n"; }
	
	
};

void bar()
{
	cout << "++++\n";
	throw 1;
	cout << "++++\n";
}
void foo()
{
	A a;
	cout << "****\n";
	bar();
	cout << "****\n";
	// cleanup call : will bot be called on exceptional flow
}

int main()
{
	try
	{
		cout << "----\n";
		foo();
		cout << "----\n";
	}
	catch(...)
	{
		cout << "Exception occurred \n";
	}
	cout << "end\n";
}



