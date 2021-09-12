#ifndef RECTHANLDE_H
#define RECTHANLDE_H
class Rect;	// we need not include rect.h, we can just use this statement

class RectHandle
{
	private:
	Rect *ptr_rect;
	public:
	RectHandle(int length, int breadth);
	int find_area() const;
	void change_length(int length);
	void change_breadth(int breadth);
	~RectHandle();
};
#endif

