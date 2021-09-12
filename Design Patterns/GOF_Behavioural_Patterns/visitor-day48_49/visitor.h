#ifndef VISITOR_H
#define VISITOR_H
class Rect;
class Circle;
class Square;

class Visitor
{
	public:
	virtual ~Visitor();
	// visitor for each element type
	virtual void visit_rect(const Rect*) const = 0;
	virtual void visit_circle(const Circle*) const = 0;
	virtual void visit_square(const Square*) const = 0;
};
#endif

