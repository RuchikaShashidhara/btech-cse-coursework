#ifndef CONCRETE_DECORATOR_H
#define CONCRETE_DECORATOR_H
#include "decorator.h"
class Concrete_Decorator : public Decorator
{
	public:
	Concrete_Decorator(Component *pc);
	virtual void operation() override;
};
#endif

// Inherits from Decorator class

