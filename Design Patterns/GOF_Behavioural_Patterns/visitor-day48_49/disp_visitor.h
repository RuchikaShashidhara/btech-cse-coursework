#ifndef DISP_VISITOR
#define DISP_VISITOR
#include "visitor.h"
class Disp_Visitor : public Visitor
{
	public:
	virtual void visit_rect(const Rect*) const;
	virtual void visit_circle(const Circle*) const;
	virtual void visit_square(const Square*) const;
};
#endif

