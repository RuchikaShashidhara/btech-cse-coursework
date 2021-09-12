#include <iostream>
using namespace std;
#include "component.h"
#include "concrete_component.h"
#include "concrete_decorator.h"
#include "concrete_decorator1.h"

int main()
{
	Component *pc;
	//pc = new Component; // compile time error; instantiating an abstract class
	//delete pc;
	
	pc = new Concrete_Component();
	// LHS - base class ptr, RHS - derived class pointer
	// here base class is implicit / trivial, hence it is allowed
	pc->operation();
	cout << "--------------------------------\n";
	// delete is not used here - why?
	
	//new Decorator(); // NO; abstract class cannot be instantiated; complile time error

	pc = new Concrete_Decorator(pc);
	// can be expressed ie. subtituted in this manner by using inheritance
	pc->operation();
	// can be called from concrete component as we wanted to use the normal implementation (above) by using compositon
	/*
	Here once we decorate we cannot redecorate a decorated components
	First it decorates from concrete deorator and then it still calls the opeation of concrete component
	*/
	
	cout << "--------------------------------\n";
	pc = new Concrete_Decorator1(pc);
	// here pc was already decorated above, we are trying to redorate it
	// pc on the RHS is from the immediate parent class
	// here pc usues the ultimate base class to call the decorator function polymorphically
	pc->operation();
	// again calling the same operation as above
	
}




