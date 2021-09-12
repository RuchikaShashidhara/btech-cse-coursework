#ifndef PIGEON_FACTORY_H
#define PIGEON_FACTORY_H
#include "factory.h"

class Pigeon_Factory : public Factory
{
	public:
	virtual Body* create_body();
	virtual Lid* create_lid();
};
#endif
