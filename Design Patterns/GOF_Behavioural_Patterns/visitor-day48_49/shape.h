#ifndef SHAPE_H
#define SHAPE_H
class Visitor;
class Shape
{
	public:
	virtual ~Shape();
	virtual double peri() const = 0;
	virtual double area() const = 0;
	virtual void accept(const Visitor*) const = 0;
};
#endif

