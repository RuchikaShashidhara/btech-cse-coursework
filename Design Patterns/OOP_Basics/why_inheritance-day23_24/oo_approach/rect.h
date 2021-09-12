#ifndef RECT_H
#define RECT_H
#include "shape.h"

class Rect : public Shape
{
	private:
	double length_;
	double breadth_;
	public:
	void read();
	void disp() const;
	double area() const;
	double peri() const;
};
#endif
