#ifndef CONCRETE_COMPONENT_H
#define CONCRETE_COMPONENT_H
#include "component.h"

class Concrete_Component : public Component
{
	public:
	virtual void operation() override;
};
#endif

/*
Concrete_Component inherits from Component class
It overrides operation() function from Component class's override() function
Since Dtor of base class - Component is virtual, dtor of dervied class - Concrete_Component is also virtual (no need to explicitly mention the virtual dtor here)
*/
