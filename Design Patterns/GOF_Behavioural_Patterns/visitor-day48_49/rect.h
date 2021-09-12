#ifndef RECT_H
#define RECT_H
#include "shape.h"
class Rect : public Shape
{
	public:
	Rect(double length, double breadth);
	virtual double peri() const;
	virtual double area() const;
	double get_length() const;
	double get_breadth() const;
	
	virtual void accept(const Visitor*) const;
	
	private:
	double length;
	double breadth;
};
#endif



