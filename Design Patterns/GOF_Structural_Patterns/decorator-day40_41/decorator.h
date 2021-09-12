#ifndef DECORATOR_H
#define DECORATOR_H
#include "component.h"
class Decorator : public Component
{
	public:
	
	Decorator(Component *pc);

	virtual void operation();
	// mentioned in italics, operation() is a virtual function, overrrides from base class operation() function

	virtual ~Decorator() = 0;
	// to make the class abstract, dtor must be pure virtual

	private:
	Component *pc_;
	// it is a composition not an aggregation, hence component is pointer
	// though component is inherted here, component ptr pc is created to delegate something - ?, this is composition
	// 
};
#endif

/*
Decorator class is mentioned in italics in the diagram i.e. it is an abstract class
It inherits from Component class
It has a also a composition (*pc_) from Component class
*/

