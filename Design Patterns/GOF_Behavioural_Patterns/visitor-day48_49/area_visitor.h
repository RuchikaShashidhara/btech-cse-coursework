#ifndef AREA_VISITOR
#define AREA_VISITOR
#include "visitor.h"
class Area_Visitor : public Visitor
{
	private:
	mutable double area_rect = 0;
	mutable double area_circle = 0;
	mutable double area_square = 0;
	
	public:
	virtual void visit_rect(const Rect*) const;
	virtual void visit_circle(const Circle*) const;
	virtual void visit_square(const Square*) const;
	void disp_areas() const;
};
#endif

