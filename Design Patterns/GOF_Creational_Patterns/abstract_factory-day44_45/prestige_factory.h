#ifndef PRESTIGE_FACTORY_H
#define PRESTIGE_FACTORY_H
#include "factory.h"

class Prestige_Factory : public Factory
{
	public:
	virtual Body* create_body();
	virtual Lid* create_lid();
};
#endif

