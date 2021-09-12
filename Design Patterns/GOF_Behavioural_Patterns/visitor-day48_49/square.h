#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
class Square : public Shape
{
	public:
	Square(double length);
	virtual double peri() const ;
	virtual double area()  const;
	double get_length() const;
	
	virtual void accept(const Visitor*) const;
	
	private:
	double length;
};
#endif
