#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
class Circle : public Shape
{
	public:
	Circle(double radius);
	virtual double peri() const;
	virtual double area() const;
	double get_radius() const;
	
	virtual void accept(const Visitor*) const;
	
	private:
	double radius;
};
#endif

