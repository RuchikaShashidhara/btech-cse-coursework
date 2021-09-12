#ifndef SHAPE_H
#define SHAPE_H
// class with pure virtual fn is not instantiable
// called abstract class
// derived class has to define these functions - overriding
// only then class becomes concrete
class Shape
{
	public:
	virtual void read() = 0; // pure virtual fns
	virtual void disp() const = 0;
	virtual double area() const = 0;
	virtual double peri() const = 0;
};
#endif
