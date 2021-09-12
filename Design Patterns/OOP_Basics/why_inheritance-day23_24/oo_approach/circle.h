#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
	private:
	double radius_;
	public:
	void read();
	void disp() const;
	double area() const;
	double peri() const;
};
#endif
