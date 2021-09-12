#ifndef RECTHANLDE_H
#define RECTHANLDE_H
class Rect;

class RectHandle
{
	private:
	Rect *ptr_rect;
	RectHandle(const RectHandle&);		// hide the function
	public:
	RectHandle(int length, int breadth);
	int find_area() const;
	void change_length(int length);
	void change_breadth(int breadth);
	~RectHandle();
	RectHandle& operator=(const RectHandle&) = delete; // contextual keyword, to remove implementation
};
#endif

