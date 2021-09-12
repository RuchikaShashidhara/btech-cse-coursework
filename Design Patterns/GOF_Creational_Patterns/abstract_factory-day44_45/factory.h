#ifndef FACTORY_H
#define FACTORY_H
class Body;
class Lid;
class Factory
{
	public:
	virtual ~Factory();
	virtual Body* create_body() = 0;
	virtual Lid* create_lid() = 0;
};
#endif


