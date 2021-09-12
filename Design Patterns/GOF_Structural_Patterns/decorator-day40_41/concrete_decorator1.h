#ifndef CONCRETE_DECORATOR1_H
#define CONCRETE_DECORATOR1_H
#include "concrete_decorator.h"
class Concrete_Decorator1 : public Concrete_Decorator
{
	public:
	Concrete_Decorator1(Component *pc);
	virtual void operation() override;
};
#endif
