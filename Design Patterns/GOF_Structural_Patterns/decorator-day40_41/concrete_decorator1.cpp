#include <iostream>
using namespace std;
#include "concrete_decorator1.h"

Concrete_Decorator1::Concrete_Decorator1(Component *pc)
: Concrete_Decorator(pc)
{
}


void Concrete_Decorator1::operation() 
{
	cout << "decorated by message from concrete decorator one\n";
	Decorator::operation();
	// dont use Concrete_Decorator - it will decorate more than required times, use decorator itself to ujust redeorate once
	// here ultimate base class funtion here is called. It is  polymorphically called by concrete component's parents till the top.
}
