#include <iostream>
using namespace std;
#include "decorator.h"

Decorator::Decorator(Component* pc)
: pc_(pc)
{

}
// ctor - initializes an object of component pc

Decorator::~Decorator()
{
}
// dtor

void Decorator::operation()
{
	pc_->operation();	// polymorphic call
}
// calls operation() 
