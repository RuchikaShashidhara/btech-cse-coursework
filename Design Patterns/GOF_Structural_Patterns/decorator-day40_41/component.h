#ifndef COMPONENT_H
#define COMPONENT_H
// pure virtual dtor should also have a definition
class Component
{
	public:
	virtual ~Component() = 0;
	// dtor must be virtual as devrived class needs to inherot from this class which would become base class (requirement in cpp)
	// though dtor cannot be supressed here, we can have no definition for it, i.e. make it a pure virtual function, but we have created empty dtor definition for it (though difinition is possible, it is not required here)
	// Hence we cannot have a client for this 
	virtual void operation() = 0; 
	// pure virtual, as it should be overridden, check diagram:  
	// - derived classes below override this function
	// - operation is in italics - it is an abstract class
};
#endif

/*
Problems in design patterns to consider in cpp:

1) Ctor cannot be supressed

When an object of dervied class is made, the ctor of the derived class will call the dtor of the base class.

Hence, Ctor cannot be deleted because all initalizations can be created only if ctor is created, if we del ctor, the initialization will be destroyed, this will lead to memory leaks - not allowed

Ctor cannot be made private as derived class when creating its object, calls the ctor of the base class. Private functions cannot be inherited in derived class, so now the derived class cannot call the ctor of the base class & hence the object cannot be created/instantiated.



2) Dtor cannot be supressed

Assume that every function in a class has an implementation.
The default implementation is in the base class as we don't need to keep writing it in the derived class.
This means that no function can be made pure.

If we want to make a function abstract, the design technique is to make the dtor pure. 
Hence, even though dtor is pure, considering the statemets above we must have a definition for it.
If we do not have a definition for it, we cannot create derrived class & inherit from this class.
*/



