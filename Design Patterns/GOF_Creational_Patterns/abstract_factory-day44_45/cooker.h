#ifndef COOKER_H
#define COOKER_H
class Factory;
class Body;
class Lid;
class Cooker
{
	public:
	Cooker(Factory *f);
	private:
	Body *ptr_body;
	Lid *ptr_lid;
};
#endif

