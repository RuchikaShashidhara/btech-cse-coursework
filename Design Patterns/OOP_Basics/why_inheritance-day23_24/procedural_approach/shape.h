#ifndef SHAPE_H
#define SHAPE_H
#include "rect.h"
#include "circle.h"
union ShapeUnion
{
	Rect r_;
	Circle c_;
};
class Shape
{
	private:
	ShapeUnion su_;
	char st_; // shape type : r : rect; c : circle
		  // st_ is called as a discriminator
		  // it tells which union we are using r or c
		  // enum is a better implementation of discriminator
	public:
	void read();
	void disp() const;
	double area() const;
	double peri() const;
};
#endif
